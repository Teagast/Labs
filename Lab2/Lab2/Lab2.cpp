
#include "stdafx.h"
#include "Vernam.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	int choise = 0;
	while (choise != 3)
	{
		cout << "��� ������?" << '\n';
		cout << "1. �������/��������� �����!" << '\n';
		cout << "2. ��������� �����!" << '\n';
		cout << "3. �����������." << '\n';
		cout << "� ������� -";
		cin >> choise;
		system("cls");
		switch (choise)
		{
		case 1:
		{
			system("cls");
			encryption();
			break;
		}
		case 2:
		{
			system("cls");
			decryption();
			break;
		}
		default:
			break;
		}
	}
}

