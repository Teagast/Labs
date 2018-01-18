#pragma once
#include "stdafx.h"
using namespace std;
class DiffHelf
{
public:
	int range = 10000;
	int *massSimple = new int[range + 1];
	int p = 0, g = 0, a = 0, b = 0;
	unsigned long long key = 0, sKey;
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
	void getP()
	{
		do
		{
			p = getNumber(range);
		} while (p == g);
	}
	void getG()
	{
		do
		{
			g = getNumber(20);
		} while (g == p);
	}
	void getA()
	{
		a = 0;
		while (a == 0)
		{
			a = rand();
		}
	}
	void getB()
	{
		b = 0;
		while (b == 0)
		{
			b = rand();
		}
	}
	unsigned long long genKey(int x, int osn)
	{
		unsigned long long res = 1;
		while (x != 0)
		{
			if (x % 2 == 0)
			{
				x /= 2;
				osn = (osn * osn) % p;
			}
			else
			{
				x--;
				res = (res * osn) % p;
			}
		}
		return res;
	}
};