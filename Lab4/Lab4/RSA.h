#pragma once
#include "stdafx.h"
using namespace std;
class RSA
{
public:
	unsigned long long q=0, p=0, n=0, fn=0, e=0, d=0;
	int range = 10000;
	int *massSimple = new int[range + 1];
	string text;
	string readFile(const string& name)
	{
		ifstream fin;
		fin.open(name, ios::binary);
		stringstream fstr;
		fstr << fin.rdbuf();
		fin.close();

		return fstr.str();
	}

	void writeFile(const string& name, const string& sourse)
	{
		ofstream fout;
		fout.open("1_" + name, ios::binary);
		fout << sourse;
		fout.close();
	}

	unsigned long long* readBinary(const string& name)
	{
		int size = getFileSize(name);

		unsigned long long* data = new unsigned long long[size];

		FILE* pFile;
		pFile = fopen(name.c_str(), "rb");
		fread(data, size, 1, pFile);

		return data;
	}

	void writeBinary(const string& name, unsigned long long* data, int size)
	{
		ofstream file;
		file.open("1_" + name, ios::binary);

		for (int i = 0; i < size; i++)
			file.write((char*)&data[i], sizeof(unsigned long long));

		file.close();
	}
	int getFileSize(const string& name)
	{
		ifstream file;
		file.open(name, ios::binary);

		file.seekg(0, ios::end);
		int size = file.tellg();

		file.close();

		return size;
	}
	void genSimple()
	{
		for (int i = 0; i < range + 1; i++)
			massSimple[i] = i;
		for (int p = 2; p < range + 1; p++)
		{
			if (massSimple[p] != 0)
			{
				for (int j = p*p; j < range + 1; j += p)
					massSimple[j] = 0;
			}
		}
		massSimple[1] = 0;
	}
	int getNumber(int rn)
	{
		int tmp, number = 0;
		while (number == 0)
		{
			tmp = rand() % rn;
			number = massSimple[tmp];
		}
		massSimple[tmp] = 0;
		return number;
	}
	void genPQ()
	{
		do
		{
			p = getNumber(1000);
			q = getNumber(1000);
		} while (p == q);
	}
	void genN()
	{
		n = p*q;
	}
	void genFn()
	{
		fn = ((p - 1) * (q - 1));
	}
	void genE()
	{
		do
		{
			e = getNumber(2000);
		} while ((fn % e == 0)&(e < fn));
	}
	void genD()
	{
		long long v1=e,v2=0,v3=1,u1=fn,u2=1,u3=0,T1,T2,T3, tmp;
		while (v1 != 0)
		{
			tmp = u1 / v1;
			T1 = u1 % v1;
			T2 = u2 - tmp*v2;
			T3 = u3 - tmp* v3;
			u1 = v1;
			u2 = v2;
			u3 = v3;
			v1 = T1;
			v2 = T2;
			v3 = T3;
		}
		while (u3 < 0)
		{
			u3 += fn;
		}
		d = u3;
	}
	unsigned long long encr(unsigned long long step, unsigned long long osn, unsigned long long mod)
	{
		unsigned long long res = 1;
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
				res = (res * osn) % mod;
			}
		}
		return res;
	}

	void Encryption(const string& fin, unsigned long long key1, unsigned long long n)
	{
		text = readFile(fin);
		int textSize = text.size();
		unsigned long long* data = new unsigned long long[textSize];

		for (int i = 0; i < textSize; ++i)
			data[i] = encr(key1, (unsigned long long)text[i], n);

		writeBinary(fin, data, textSize);

		delete[] data;
		data = nullptr;
	}

	void Decryption(const string& fin, const string& fout)
	{
		string txt = "";
		int size = getFileSize(fin) / sizeof(unsigned long long);
		unsigned long long* data = new unsigned long long[size];

		data = readBinary(fin);

		for (int i = 0; i < size; ++i)
			txt += (unsigned char)encr(d,data[i] , n);

		writeFile(fout, txt);

		delete[] data;
		data = nullptr;
	}

};