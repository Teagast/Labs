// Lab4.cpp: определяет точку входа для консольного приложения.
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
	cout << "Вася хочет отправить сообщение Андрею, для этого он делает следующие шаги:" << '\n';
	cout << "Генерирует простые числа q и p" << '\n';
	rsa.genPQ();
//	rsa.p = 3;
//	rsa.q = 11;
	cout << "q=" << rsa.q << '\n';
	cout << "p=" << rsa.p << '\n';
	cout << "Вычисляет n=p*q" << '\n';
	rsa.genN();
	cout << "n=" << rsa.n << '\n';
	rsa.genFn();
	cout << "Вычисляет F(n)" << '\n';
	cout << "F(n)=" << rsa.fn << '\n';
	cout << "Выбирает число e" << '\n';
	rsa.genE(); 
//	rsa.e = 7;
	cout << "e=" << rsa.e << '\n';
	cout << "Вычисляет секретный ключ d" << '\n';
	rsa.genD();
	cout << "d=" << rsa.d << '\n';
	cout << "Пара (e=" << rsa.e << ',' << "n=" << rsa.n <<") - открытый ключ." << '\n';
	cout << "Пара (d=" << rsa.d << ',' << "n=" << rsa.n << ") - закрытый ключ." << '\n';
	cout << "Теперь Вася отсылает открытый ключ Андрею" << '\n';
	cout << "Вася ----------------------------> Андрей" << '\n';
	cout << "            (e=" << rsa.e << ',' << "n=" << rsa.n << ')'  << '\n';
	cout << "Теперь Вася шифрует сообщение и посылает его Андрею" << '\n';
	system("notepad.exe Encryption.txt");
	rsa.Encryption("Encryption.txt", rsa.e, rsa.n);
	cout << "Вася ----------------------------> Андрей" << '\n';
	cout << "	   Сообщение" << '\n';
	cout << "Теперь Андрей использует свой ключ для расшифрования" << '\n';
	rsa.Decryption("1_Encryption.txt", "Decryption.txt");
	system("notepad.exe 1_Decryption.txt");
	//system("pause");
    return 0;
}

