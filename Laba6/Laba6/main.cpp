#include <iostream>

#include "SRP.h"
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	int choice=0;
	Server srv("DataBase.txt");
	Client cl("AntonLob", "123");

	cout << "Регистрируемся?" <<endl;
	cout << "1 - Да! 2 - Не..." <<endl;
//	cin >> choice;
//	if (choice == 1) {
		cl.reg();
		srv.addClient(cl);
//	}
	
		InfoFromClient fromCln = cl.aut(srv);
		InfoFromServer fromSrv = srv.aut(fromCln);

		cl.fromS(fromSrv);
		cl.scr();
		srv.scr();

		cl.checkScr();
		srv.checkScr();

		cl.genSessKey();
		srv.genSessKey();

		cl.genM();
		srv.checkM(cl);

		srv.genR();
		cl.checkR(srv);
	system("pause");
	return 0;
}