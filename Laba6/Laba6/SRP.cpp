#include "SRP.h"

#include <stdlib.h>
#include <time.h>
#include <cmath>
#include <iostream>
using namespace std;
unsigned long long encr(unsigned long long osn, unsigned long long step, unsigned long long mod)
{
	unsigned long long c = 1;
	while (step != 0)
	{
		if (step % 2 == 0)
		{
			step /= 2;
			osn = (osn * osn) % mod;
		}
		else
		{
			step--;
			c = (c * osn) % mod;
		}
	}
	return c;
}

unsigned long long hashFunc(const string& message)
{
	const char* mChar = message.c_str();

	char out[65];
	sha256_context ctext;
	unsigned char sha256sum[32];

	sha256_starts(&ctext);
	sha256_update(&ctext, (uint8 *)mChar, strlen(mChar));
	sha256_finish(&ctext, sha256sum);

	for (int i = 0; i < 32; i++)
		sprintf(out + i * 2, "%02x", sha256sum[i]);

	unsigned long long res = 0;
	memcpy(&res, out, 4);

	return res;
}

string Client::salt()
{
	srand(time(NULL));

	string res;
	int length = 15 + rand() % 10;

	for (int i = 0; i < length; i++)
		res += (97 + rand() % 25);

	return res;
}

unsigned long long Client::genNum()
{
	srand(time(NULL));
	return (rand() % 3000);
}

unsigned long long Client::genSimple(int gen)
{
	srand(time(NULL));
	unsigned long long res;

	do
	{
		res = rand() % gen;
	} while (!checkSimple(res));

	return res;
}

bool Client::checkSimple(unsigned long long num)
{
	for (unsigned long long i = 2; i <= sqrt(num); i++)
		if (num % i == 0)
			return false;
	return true;
}

SafetyField Client::genGKN()
{
	srand(time(NULL));
	unsigned long long n, g, k, tmp = 0;

	do
	{
		n = genSimple(15000);

		do
		{
			L1:
			if (checkSimple(n))
				n = 2 * n + 1;
			else
			{
				n = genSimple(15000);
				goto L1;
			}
		} while (!checkSimple(n));
		
		do
		{
			g = 2 + rand() % 20;
		} while (!checkSimple(g));

		tmp = encr(g, n - 1, n);
	} while (tmp != 1);

	k = 3;

	return { n, g, k };
}

unsigned long long Client::genVer()
{
	string tmp = _info.fields.salt + _password;

	unsigned long long x = 0;
	x = hashFunc(tmp);

	unsigned long long verif = encr(_info.safety.g, x, _info.safety.n);

	return verif;
}

Client::Client(const string& login, const string& password)
{
	this->_info.login = login;
	this->_password = password;
	this->A = 0;
	this->fromServ.B = 0;
	this->fromServ.salt = "";
	this->U = 0;
	this->_s = 0;
	this->_key = 0;
	this->M = 0;
	this->R = 0;
}

Client::~Client()
{ }

void Client::reg()
{
	this->_info.fields.salt = salt();
	this->_info.safety = genGKN();
	this->_info.fields.passVer = genVer();
}

InfoFromClient Client::aut(const Server& server)
{
	this->_a = genNum();
	_info.safety = server.getSField(this->_info.login);

	this->A = encr(_info.safety.g, this->_a, _info.safety.n);

	return { _info.login, A };
}

void Client::fromS(const InfoFromServer& fromServ)
{
	this->fromServ.B = fromServ.B;
	this->fromServ.salt = fromServ.salt;

	if (this->fromServ.B == 0)
	{
		cout << "[Client] Failed to connect (B == 0)" <<endl;
		exit(0);
	}
}

void Client::scr()
{
	string first = to_string(this->A);
	string second = to_string(this->fromServ.B);
	string tmp = first + second;

	this->U = hashFunc(tmp);
}

void Client::checkScr()
{
	if (this->U == 0)
	{
		cout << "[Client] Failed to connect (U == 0)" <<endl;
		exit(0);
	}
}

void Client::genSessKey()
{
	string tmp = fromServ.salt + _password;

	unsigned long long x = 0;
	x = hashFunc(tmp);

	unsigned long long base = this->fromServ.B - this->_info.safety.k * encr(this->_info.safety.g, x, this->_info.safety.n);
	unsigned long long exponent = this->_a + U * x;
	this->_s = encr(base, exponent, this->_info.safety.n);

	string keyM = to_string(this->_s);

	this->_key = hashFunc(keyM);
}

void Client::genM()
{
	unsigned long long n = 0, g = 0, i = 0;

	n = hashFunc(to_string(this->_info.safety.n));
	g = hashFunc(to_string(this->_info.safety.g));
	i = hashFunc(this->_info.login);
	unsigned long long NxorG = 0;
	NxorG = n ^ g;

	string m = to_string(NxorG) + to_string(i) + to_string(this->_s) +
					to_string(this->A) + to_string(this->fromServ.B) + to_string(this->_key);

	this->M = hashFunc(m);
}

void Client::checkR(const Server& server)
{
	string r = to_string(this->A) + to_string(this->M) + to_string(this->_key);
	this->R = hashFunc(r);

	if (this->R == server.R)

		cout << "Successful connection!" <<endl;
	else
	{
		cout << "[Client] Failed to connect (R != R)" <<endl;
		exit(0);
	}
}

UserInfo Client::getForS() const
{
	return this->_info;
}

void Server::loadDB()
{
	FILE* file;
	file = fopen(_filePath.c_str(), "r");
	char str[255];

	UserInfo info;
	char* login = new char;
	char* salt = new char;
	unsigned long long ver = 0, n = 0, g = 0, k = 0;

	while (!feof(file))
	{
		fgets(str, 255, file);
		sscanf(str, "Login: %s Salt: %s VPassword: %u NGK: %u, %u, %u",
			login, salt, &ver, &n, &g, &k);

		string strLogin(login);
		string strSalt(salt);

		info = { strLogin, { strSalt, ver }, { n, g, k } };

		_dataBase.insert(pair<string, UserInfo>(info.login, info));
	}

	fclose(file);
}

unsigned long long Server::genNum()
{
	srand(time(NULL));
	return (rand() % 3000);
}

Server::Server(const string& dataBaseFile)
{
	this->_filePath = dataBaseFile;
	loadDB();
	this->fromClient.A = 0;
	this->fromClient.login = "";
	this->B = 0;
	this->U = 0;
	this->_s = 0;
	this->_key = 0;
	this->M = 0;
	this->R = 0;
}

void Server::addClient(const Client& cilent)
{
	int count = 0;
	UserInfo userInfo;
	userInfo = cilent.getForS();

	for (auto i = _dataBase.begin(); i != _dataBase.end(); ++i)
		if (i->first == userInfo.login)
			count++;

	FILE* file;
	file = fopen(_filePath.c_str(), "a");

	if (!count)
	{
		fprintf(file, "Login: %-30s Salt: %-30s VPassword: %u ",
			userInfo.login.c_str(), userInfo.fields.salt.c_str(), userInfo.fields.passVer);

		fprintf(file, "NGK: %u, ", userInfo.safety.n);
		fprintf(file, "%u, ", userInfo.safety.g);
		fprintf(file, "%u\n", userInfo.safety.k);

		_dataBase.insert(pair<string, UserInfo>(userInfo.login, userInfo));
	}

	fclose(file);
}

InfoFromServer Server::aut(const InfoFromClient& clientAuth)
{
	this->fromClient.A = clientAuth.A;
	this->fromClient.login = clientAuth.login;

	if (this->fromClient.A == 0)
	{
		cout << "[Server] Failed to connect (A == 0)" <<endl;
		exit(0);
	}

	this->_b = genNum();
	UserInfo info = _dataBase.find(this->fromClient.login)->second;

	this->B = info.safety.k * info.fields.passVer + encr(info.safety.g, this->_b, info.safety.n);

	return { info.fields.salt, B };
}

void Server::scr()
{
	string first = to_string(this->fromClient.A);
	string second = to_string(this->B);
	string tmpMsg = first + second;

	this->U = hashFunc(tmpMsg);
}

void Server::checkScr()
{
	if (this->U == 0)
	{
		cout << "[Server] Failed to connect (U == 0)" <<endl;
		exit(0);
	}
}

void Server::genSessKey()
{
	UserInfo info = _dataBase.find(this->fromClient.login)->second;

	this->_s = encr(this->fromClient.A * encr(info.fields.passVer, this->U, info.safety.n), this->_b, info.safety.n);

	string keyMsg = to_string(this->_s);

	this->_key = hashFunc(keyMsg);
}

void Server::checkM(const Client& client)
{
	UserInfo info = client.getForS();

	unsigned long long n = 0, g = 0, i = 0;

	n = hashFunc(to_string(info.safety.n));
	g = hashFunc(to_string(info.safety.g));
	i = hashFunc(info.login);
	unsigned long long NxorG = 0;
	NxorG = n ^ g;

	string m = to_string(NxorG) + to_string(i) + to_string(this->_s) +
		to_string(this->fromClient.A) + to_string(this->B) + to_string(this->_key);

	this->M = hashFunc(m);

	if (this->M == client.M)
		genR();
	else
	{
		cout << "[Server] Failed to connect (M != M)" <<endl;
		exit(0);
	}
}

void Server::genR()
{
	string r = to_string(this->fromClient.A) + to_string(this->M) + to_string(this->_key);
	this->R = hashFunc(r);
}

SafetyField Server::getSField(const string& userLogin) const
{
	int count = 0;

	for (auto i = _dataBase.begin(); i != _dataBase.end(); ++i)
		if (i->first == userLogin)
			count++;

	if (!count)
	{
		cout << "Unknown user" <<endl;
		exit(0);
	}

	return _dataBase.find(userLogin)->second.safety;
}