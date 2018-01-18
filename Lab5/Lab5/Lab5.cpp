// Lab5.cpp: определ€ет точку входа дл€ консольного приложени€.
//

#include "stdafx.h"
#include "Quarantine.h"
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "¬ведите сообщение в блокноте" << '\n';
	system("notepad.exe Text.txt");
	messages mes;
	mes.filtM();
	mes.filtMW();
	system("notepad.exe Out.txt");
    return 0;
}

