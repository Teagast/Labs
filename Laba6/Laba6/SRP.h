#ifndef LABA6SOURSE_H
#define LABA6SOURSE_H

#include <string>
#include <map>

#include "sha256.h"
using namespace std;

class Client;
class Server;

unsigned long long encr(unsigned long long a, unsigned long long b, unsigned long long n);
unsigned long long hashFunc(const string& message);

struct UserFields
{
	string salt;
	unsigned long long passVer;
};

struct SafetyField
{
	unsigned long long n;
	unsigned long long g;
	unsigned long long k;
};

struct UserInfo
{
	string login;
	UserFields fields;
	SafetyField safety;
};

struct InfoFromServer
{
	string salt;
	unsigned long long B;
};

struct InfoFromClient
{
	string login;
	unsigned long long A;
};

class Client
{
private:
	UserInfo _info;
	string _password;
	unsigned long long _a;
	unsigned long long _s;
	unsigned long long _key;
private:
	string salt();
	unsigned long long genNum();
	unsigned long long genSimple(int gen);
	bool checkSimple(unsigned long long num);
	SafetyField genGKN();
	unsigned long long genVer();
public:
	unsigned long long A;
	InfoFromServer fromServ;
	unsigned long long U;
	unsigned long long M;
	unsigned long long R;
public:
	Client(const string& login, const string& password);
	~Client();

	void reg();
	InfoFromClient aut(const Server& server);
	void fromS(const InfoFromServer& fromServ);
	void scr();
	void checkScr();
	void genSessKey();
	void genM();
	void checkR(const Server& server);

	UserInfo getForS() const;
};

class Server
{
private:
	string _filePath;
	map<string, UserInfo> _dataBase;
	unsigned long long _b;
	unsigned long long _s;
	unsigned long long _key;
private:
	void loadDB();
	unsigned long long genNum();
public:
	InfoFromClient fromClient;
	unsigned long long B;
	unsigned long long U;
	unsigned long long M;
	unsigned long long R;
public:
	Server(const string& dataBaseFile);

	void addClient(const Client& cilent);
	InfoFromServer aut(const InfoFromClient& clientAuth);
	void scr();
	void checkScr();
	void genSessKey();
	void checkM(const Client& client);
	void genR();

	SafetyField getSField(const string& userLogin) const;
};

#endif // LABA6SOURSE_H