// Lab3.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include "DiffHelf.h"
using namespace std;
int main()
{
	int tmp;
	setlocale(LC_ALL, "Russian");
	cout << "-----------------����----------------" << '\n';
	cout << "���� ����� �������� ��������� ������" << '\n';
	//system("pause");
	//system("cls");
	DiffHelf andrey,vasya;
	srand(time(NULL));
	vasya.genSimple();
	vasya.getG();
	vasya.getP();
	cout << "���� �������� ������ ������� �����: g="<< vasya.g << '\n';
	//system("pause");
	//system("cls");
	cout << "���� �������� ������ ������� �����: p=" << vasya.p << '\n';
	//system("pause");
	//system("cls");
	cout << "���� �������� ����� ������." <<  '\n';
	cout << "���� ---------------> ������" << '\n';
	cout << "         g=" << vasya.g <<  '\n';
	cout << "         p=" << vasya.p <<  '\n';
	andrey.g = vasya.g;
	andrey.p = vasya.p;
	//system("pause");
	//system("cls");
	cout << "���� ����������� ����� a � ��������� g^a mod p" << '\n';
	vasya.getA();
	cout << "���� �������� ����� a=" << vasya.a << '\n';
	vasya.key=vasya.genKey(vasya.a, vasya.g);
	cout << "g^a mod p =" << vasya.key << '\n';
	//system("pause");
	//system("cls");
	andrey.getB();
	cout << "-----------------������---------------" << '\n';
	cout << "������ ������ ����������� ����� b=" << andrey.b << '\n';
	andrey.key = andrey.genKey(andrey.b, andrey.g);
	cout << "� ����� ������� g^b mod p � �������� =" << andrey.key << '\n';
	//system("pause");
	//system("cls");
	cout << "������ ���� � ������ ������������ ����������� ������������" << '\n';
	cout << "���� ---------------> ������" << '\n';
	cout << "         A=" << vasya.key << '\n';
	cout << "���� <--------------- ������" << '\n';
	cout << "         B=" << andrey.key << '\n';
	tmp = vasya.key;
	vasya.key = andrey.key;
	andrey.key = tmp;
	vasya.sKey=vasya.genKey(vasya.a, vasya.key);
	andrey.sKey=andrey.genKey(andrey.b, andrey.key);
	cout << "-----------------����----------------" << '\n';
	cout << "���� ��������� ���� ����� � ��������� ������ �������� ����� ���� =" << vasya.sKey << '\n';
	cout << "-----------------������----------------" << '\n';
	cout << "������ ��������� ���� ����� � ��������� ���� �������� ����� ���� =" << andrey.sKey << '\n';
	cout << "-------------------------------------" << '\n';
	if (vasya.sKey == andrey.sKey)
	{
		cout << "             ---------------------------------" << '\n';
		cout << "             |����� ��������� � ��� �������! |" << '\n';
		cout << "             ---------------------------------" << '\n';
	}
	else cout << "���-�� ���� ����� �� ��� =(" << '\n';
	system("pause");
    return 0;
}

