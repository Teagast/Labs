


#include "stdafx.h"

using namespace std;

void main()
{
	setlocale(LC_ALL, "Russian"); 
	int choise=0; 
	while (choise != 5) 
	{
		cout << "��� ������?" << '\n';
		cout << "1. ������� �����!" << '\n';
		cout << "2. ��������� �����!" << '\n';
		cout << "3. ������ ��� � ���� ��� ����������!" << '\n';
		cout << "4. ������ ��� �� ��� ����������!" << '\n';
		cout << "5. �����������." << '\n';
		cout << "� ������� -";
		cin >> choise; 
		system("cls");
		switch (choise)
		{
		case 1: 
		{
			system("notepad.exe Text_in.txt");
			ifstream fin("Text_in.txt");
			string str, sbuff; 
			while (fin >> sbuff) str += sbuff + ' '; 
			fin.close(); 
			Encryptor encryptor; 
			str = encryptor.cypher(str); 
			ofstream fo("Text_out.txt");
			fo << str; 
			fo.close();
			system("notepad.exe Text_out.txt");
			break;
		}
		case 2: 
		{
			system("cls");
			cout << "������� ����� ��� ���������� � ��������.";
			system("notepad.exe Text_in.txt");
			ifstream fin("Text_in.txt");
			string str, sbuff; 
			while (fin >> sbuff) str += sbuff + ' '; 
			fin.close(); 
			Decryptor decryptor;
		    str=decryptor.decrypt(str);
			ofstream fo("Text_out.txt");
			fo << str; 
			fo.close();
			system("notepad.exe Text_out.txt");
			break;
		}
		case 3: 
		{
			system("notepad.exe Text_in.txt");
			break;
		}
		case 4: 
		{
			system("notepad.exe Text_out.txt");
			break;
		}
		default: 
			break;
		}
	}
	
	
	

}

