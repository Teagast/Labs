// Lab4.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include "RSA.h"
using namespace std;
int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "Russian");
	RSA rsa;
	rsa.genSimple();
	cout << "���� ����� ��������� ��������� ������, ��� ����� �� ������ ��������� ����:" << '\n';
	cout << "���������� ������� ����� q � p" << '\n';
	rsa.genPQ();
//	rsa.p = 3;
//	rsa.q = 11;
	cout << "q=" << rsa.q << '\n';
	cout << "p=" << rsa.p << '\n';
	cout << "��������� n=p*q" << '\n';
	rsa.genN();
	cout << "n=" << rsa.n << '\n';
	rsa.genFn();
	cout << "��������� F(n)" << '\n';
	cout << "F(n)=" << rsa.fn << '\n';
	cout << "�������� ����� e" << '\n';
	rsa.genE(); 
//	rsa.e = 7;
	cout << "e=" << rsa.e << '\n';
	cout << "��������� ��������� ���� d" << '\n';
	rsa.genD();
	cout << "d=" << rsa.d << '\n';
	cout << "���� (e=" << rsa.e << ',' << "n=" << rsa.n <<") - �������� ����." << '\n';
	cout << "���� (d=" << rsa.d << ',' << "n=" << rsa.n << ") - �������� ����." << '\n';
	cout << "������ ���� �������� �������� ���� ������" << '\n';
	cout << "���� ----------------------------> ������" << '\n';
	cout << "            (e=" << rsa.e << ',' << "n=" << rsa.n << ')'  << '\n';
	cout << "������ ���� ������� ��������� � �������� ��� ������" << '\n';
	system("notepad.exe Encryption.txt");
	rsa.Encryption("Encryption.txt", rsa.e, rsa.n);
	cout << "���� ----------------------------> ������" << '\n';
	cout << "	   ���������" << '\n';
	cout << "������ ������ ���������� ���� ���� ��� �������������" << '\n';
	rsa.Decryption("1_Encryption.txt", "Decryption.txt");
	system("notepad.exe 1_Decryption.txt");
	//system("pause");
    return 0;
}

