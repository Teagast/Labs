
#include "stdafx.h"
#include "Vernam.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	int choise = 0;
	while (choise != 3)
	{
		cout << "Что делаем?" << '\n';
		cout << "1. Шифруем/дешифруем текст!" << '\n';
		cout << "2. Дешифруем текст!" << '\n';
		cout << "3. Заканчиваем." << '\n';
		cout << "Я выбираю -";
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

