#pragma once

#include "stdafx.h"
using namespace std;

void encryption()
{
	system("notepad.exe Text_in.txt");
	ifstream fin("Text_in.txt",ios::binary);

	string str, sbuff, key;

	while (fin >> sbuff) str += sbuff + ' ';
	fin.close();

	srand(time(NULL));

	for (int i = 0; i < str.size(); ++i)
		key += rand() % 63 + 192;

	for (int i = 0; i < str.size(); i++)
		str[i] ^= key[i];

	ofstream fo("Text_out.txt", ios::binary);
	fo << str;
	fo.close();
	system("notepad.exe Text_out.txt");

	ofstream fok("Text_outKey.txt", ios::binary);
	fok << key;
	fok.close();
	system("notepad.exe Text_outKey.txt");
}
int get_file_size()
{
	ifstream fin("Text_out.txt", ios::binary);
	fin.seekg(0, std::ios::end);
	int size = fin.tellg();
	fin.close();
	return(size);
}
void decryption()
{
	int size_f = get_file_size();
	string key, str, sbuff, skbuff;
	
	system("notepad.exe Text_outKey.txt");
	ifstream fink("Text_outKey.txt",ios::binary);

	while (fink >> skbuff) key += skbuff;
	fink.close();

	system("notepad.exe Text_out.txt");
	ifstream fin("Text_out.txt", ios::binary);

	char* st = new char[size_f];
	fin.read(st, size_f);

	//while (fin >> sbuff) str += sbuff;
	fin.close();

	for (int i = 0; i < size_f; i++)
		st[i] ^= key[i];

	ofstream fo("Text_out.txt", ios::binary);
	fo.write(st, size_f);
	fo.close();
	system("notepad.exe Text_out.txt");
}
