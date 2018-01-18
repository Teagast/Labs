// Lab3.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "DiffHelf.h"
using namespace std;
int main()
{
	int tmp;
	setlocale(LC_ALL, "Russian");
	cout << "-----------------Вася----------------" << '\n';
	cout << "Вася хочет передать сообщение Андрею" << '\n';
	//system("pause");
	//system("cls");
	DiffHelf andrey,vasya;
	srand(time(NULL));
	vasya.genSimple();
	vasya.getG();
	vasya.getP();
	cout << "Вася придумал первое простое число: g="<< vasya.g << '\n';
	//system("pause");
	//system("cls");
	cout << "Вася придумал второе простое число: p=" << vasya.p << '\n';
	//system("pause");
	//system("cls");
	cout << "Вася передает числа Андрею." <<  '\n';
	cout << "Вася ---------------> Андрей" << '\n';
	cout << "         g=" << vasya.g <<  '\n';
	cout << "         p=" << vasya.p <<  '\n';
	andrey.g = vasya.g;
	andrey.p = vasya.p;
	//system("pause");
	//system("cls");
	cout << "Вася придумывает число a и вычисляет g^a mod p" << '\n';
	vasya.getA();
	cout << "Вася придумал число a=" << vasya.a << '\n';
	vasya.key=vasya.genKey(vasya.a, vasya.g);
	cout << "g^a mod p =" << vasya.key << '\n';
	//system("pause");
	//system("cls");
	andrey.getB();
	cout << "-----------------Андрей---------------" << '\n';
	cout << "Теперь Андрей придумывает число b=" << andrey.b << '\n';
	andrey.key = andrey.genKey(andrey.b, andrey.g);
	cout << "А затем считает g^b mod p и получает =" << andrey.key << '\n';
	//system("pause");
	//system("cls");
	cout << "Теперь Вася и Андрей обмениваются полученными результатами" << '\n';
	cout << "Вася ---------------> Андрей" << '\n';
	cout << "         A=" << vasya.key << '\n';
	cout << "Вася <--------------- Андрей" << '\n';
	cout << "         B=" << andrey.key << '\n';
	tmp = vasya.key;
	vasya.key = andrey.key;
	andrey.key = tmp;
	vasya.sKey=vasya.genKey(vasya.a, vasya.key);
	andrey.sKey=andrey.genKey(andrey.b, andrey.key);
	cout << "-----------------Вася----------------" << '\n';
	cout << "Вася используя свое число и результат Андрея получает общий ключ =" << vasya.sKey << '\n';
	cout << "-----------------Андрей----------------" << '\n';
	cout << "Андрей используя свое число и результат Васи получает общий ключ =" << andrey.sKey << '\n';
	cout << "-------------------------------------" << '\n';
	if (vasya.sKey == andrey.sKey)
	{
		cout << "             ---------------------------------" << '\n';
		cout << "             |Ключи одинаковы и все отлично! |" << '\n';
		cout << "             ---------------------------------" << '\n';
	}
	else cout << "Что-то выше пошло не так =(" << '\n';
	system("pause");
    return 0;
}

