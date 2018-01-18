
#pragma once
#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class Decryptor
{
public:
	int count_text[33] = { 0 }, count_lit[33] = {0}; 
	int letter_pos_text[33] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33},
letter_pos_lit[33] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33 };
	string alf = " ��������������������������������"; 
	string Alf = " �����Ũ��������������������������"; 
	
	
	
	string decrypt(string str) 
	{
		cout << "��� ����� �����-�� �������� �����, ��� �������� ����! ��������� �� ������ �����-�� ������������ � ��������." << '\n';
		system("pause");
		system("cls");
		system("notepad.exe Text_Lit.txt");
		ifstream fin("Text_Lit.txt");
		string text, sbuff; 
		while (fin >> sbuff) text += sbuff; 
		fin.close(); 
		count(text, count_lit); 
		count(str, count_text); 
		sort(count_lit,letter_pos_lit); 
		sort(count_text, letter_pos_text); 
		str=replacement(str); 
		return(str); 
	}
private:
	void count(string str, int *mass) 
	{
		int size = str.size();
		int i = 0; 
		while (i < size)
		{
			switch (str[i]) 
			{
			case '�': {mass[0]++; break; } 
			case '�': {mass[1]++; break; } 
			case '�': {mass[2]++; break; } 
			case '�': {mass[3]++; break; } 
			case '�': {mass[4]++; break; }
			case '�': {mass[5]++; break; }
			case '�': {mass[6]++; break; }
			case '�': {mass[7]++; break; }
			case '�': {mass[8]++; break; }
			case '�': {mass[9]++; break; }
			case '�': {mass[10]++; break; }
			case '�': {mass[11]++; break; }
			case '�': {mass[12]++; break; }
			case '�': {mass[13]++; break; }
			case '�': {mass[14]++; break; }
			case '�': {mass[15]++; break; }
			case '�': {mass[16]++; break; }
			case '�': {mass[17]++; break; }
			case '�': {mass[18]++; break; }
			case '�': {mass[19]++; break; }
			case '�': {mass[20]++; break; }
			case '�': {mass[21]++; break; }
			case '�': {mass[22]++; break; }
			case '�': {mass[23]++; break; }
			case '�': {mass[24]++; break; }
			case '�': {mass[25]++; break; }
			case '�': {mass[26]++; break; }
			case '�': {mass[27]++; break; }
			case '�': {mass[28]++; break; }
			case '�': {mass[29]++; break; }
			case '�': {mass[30]++; break; }
			case '�': {mass[31]++; break; }
			case '�': {mass[32]++; break; }
			case '�': {mass[0]++; break; }
			case '�': {mass[1]++; break; }
			case '�': {mass[2]++; break; }
			case '�': {mass[3]++; break; }
			case '�': {mass[4]++; break; }
			case '�': {mass[5]++; break; }
			case '�': {mass[6]++; break; }
			case '�': {mass[7]++; break; }
			case '�': {mass[8]++; break; }
			case '�': {mass[9]++; break; }
			case '�': {mass[10]++; break; }
			case '�': {mass[11]++; break; }
			case '�': {mass[12]++; break; }
			case '�': {mass[13]++; break; }
			case '�': {mass[14]++; break; }
			case '�': {mass[15]++; break; }
			case '�': {mass[16]++; break; }
			case '�': {mass[17]++; break; }
			case '�': {mass[18]++; break; }
			case '�': {mass[19]++; break; }
			case '�': {mass[20]++; break; }
			case '�': {mass[21]++; break; }
			case '�': {mass[22]++; break; }
			case '�': {mass[23]++; break; }
			case '�': {mass[24]++; break; }
			case '�': {mass[25]++; break; }
			case '�': {mass[26]++; break; }
			case '�': {mass[27]++; break; }
			case '�': {mass[28]++; break; }
			case '�': {mass[29]++; break; }
			case '�': {mass[30]++; break; }
			case '�': {mass[31]++; break; }
			case '�': {mass[32]++; break; }
			default: break;
			}
			i++; 
		}
	}
	void sort(int *mass, int *pos_mass) 
	{
			for (int i = 1; i < 33; i++)
			{
				for (int j = 0; j < 33-i; j++)
				{
					if (mass[j] < mass[j + 1])
					{
						int temp = mass[j];
						mass[j] = mass[j + 1];
						mass[j + 1] = temp;
						temp = pos_mass[j];
						pos_mass[j] = pos_mass[j + 1];
						pos_mass[j + 1] = temp;
					}
				}
			}
	}
	string replacement(string str) 
	{
		int i = 0;
		int n = str.size(); 
		while (i<n)
		{
			switch (str[i]) 
			{ 
			case '�': {str[i]=alf[letter_pos_lit[search(letter_pos_text, 1)]]; break; } 
			case '�': {str[i] = alf[letter_pos_lit[search(letter_pos_text, 2)]]; break; } 
			case '�': {str[i] = alf[letter_pos_lit[search(letter_pos_text, 3)]]; break; } 
			case '�': {str[i] = alf[letter_pos_lit[search(letter_pos_text, 4)]]; break; } 
			case '�': {str[i] = alf[letter_pos_lit[search(letter_pos_text, 5)]]; break; } 
			case '�': {str[i] = alf[letter_pos_lit[search(letter_pos_text, 6)]]; break; }
			case '�': {str[i] = alf[letter_pos_lit[search(letter_pos_text, 7)]]; break; }
			case '�': {str[i] = alf[letter_pos_lit[search(letter_pos_text, 8)]]; break; }
			case '�': {str[i] = alf[letter_pos_lit[search(letter_pos_text, 9)]]; break; }
			case '�': {str[i] = alf[letter_pos_lit[search(letter_pos_text, 10)]]; break; }
			case '�': {str[i] = alf[letter_pos_lit[search(letter_pos_text, 11)]]; break; }
			case '�': {str[i] = alf[letter_pos_lit[search(letter_pos_text, 12)]]; break; }
			case '�': {str[i] = alf[letter_pos_lit[search(letter_pos_text, 13)]]; break; }
			case '�': {str[i] = alf[letter_pos_lit[search(letter_pos_text, 14)]]; break; }
			case '�': {str[i] = alf[letter_pos_lit[search(letter_pos_text, 15)]]; break; }
			case '�': {str[i] = alf[letter_pos_lit[search(letter_pos_text, 16)]]; break; }
			case '�': {str[i] = alf[letter_pos_lit[search(letter_pos_text, 17)]]; break; }
			case '�': {str[i] = alf[letter_pos_lit[search(letter_pos_text, 18)]]; break; }
			case '�': {str[i] = alf[letter_pos_lit[search(letter_pos_text, 19)]]; break; }
			case '�': {str[i] = alf[letter_pos_lit[search(letter_pos_text, 20)]]; break; }
			case '�': {str[i] = alf[letter_pos_lit[search(letter_pos_text, 21)]]; break; }
			case '�': {str[i] = alf[letter_pos_lit[search(letter_pos_text, 22)]]; break; }
			case '�': {str[i] = alf[letter_pos_lit[search(letter_pos_text, 23)]]; break; }
			case '�': {str[i] = alf[letter_pos_lit[search(letter_pos_text, 24)]]; break; }
			case '�': {str[i] = alf[letter_pos_lit[search(letter_pos_text, 25)]]; break; }
			case '�': {str[i] = alf[letter_pos_lit[search(letter_pos_text, 26)]]; break; }
			case '�': {str[i] = alf[letter_pos_lit[search(letter_pos_text, 27)]]; break; }
			case '�': {str[i] = alf[letter_pos_lit[search(letter_pos_text, 28)]]; break; }
			case '�': {str[i] = alf[letter_pos_lit[search(letter_pos_text, 29)]]; break; }
			case '�': {str[i] = alf[letter_pos_lit[search(letter_pos_text, 30)]]; break; }
			case '�': {str[i] = alf[letter_pos_lit[search(letter_pos_text, 31)]]; break; }
			case '�': {str[i] = alf[letter_pos_lit[search(letter_pos_text, 32)]]; break; }
			case '�': {str[i] = alf[letter_pos_lit[search(letter_pos_text, 33)]]; break; }
			case '�': {str[i] = Alf[letter_pos_lit[search(letter_pos_text, 1)]]; break; }
			case '�': {str[i] = Alf[letter_pos_lit[search(letter_pos_text, 2)]]; break; }
			case '�': {str[i] = Alf[letter_pos_lit[search(letter_pos_text, 3)]]; break; }
			case '�': {str[i] = Alf[letter_pos_lit[search(letter_pos_text, 4)]]; break; }
			case '�': {str[i] = Alf[letter_pos_lit[search(letter_pos_text, 5)]]; break; }
			case '�': {str[i] = Alf[letter_pos_lit[search(letter_pos_text, 6)]]; break; }
			case '�': {str[i] = Alf[letter_pos_lit[search(letter_pos_text, 7)]]; break; }
			case '�': {str[i] = Alf[letter_pos_lit[search(letter_pos_text, 8)]]; break; }
			case '�': {str[i] = Alf[letter_pos_lit[search(letter_pos_text, 9)]]; break; }
			case '�': {str[i] = Alf[letter_pos_lit[search(letter_pos_text, 10)]]; break; }
			case '�': {str[i] = Alf[letter_pos_lit[search(letter_pos_text, 11)]]; break; }
			case '�': {str[i] = Alf[letter_pos_lit[search(letter_pos_text, 12)]]; break; }
			case '�': {str[i] = Alf[letter_pos_lit[search(letter_pos_text, 13)]]; break; }
			case '�': {str[i] = Alf[letter_pos_lit[search(letter_pos_text, 14)]]; break; }
			case '�': {str[i] = Alf[letter_pos_lit[search(letter_pos_text, 15)]]; break; }
			case '�': {str[i] = Alf[letter_pos_lit[search(letter_pos_text, 16)]]; break; }
			case '�': {str[i] = Alf[letter_pos_lit[search(letter_pos_text, 17)]]; break; }
			case '�': {str[i] = Alf[letter_pos_lit[search(letter_pos_text, 18)]]; break; }
			case '�': {str[i] = Alf[letter_pos_lit[search(letter_pos_text, 19)]]; break; }
			case '�': {str[i] = Alf[letter_pos_lit[search(letter_pos_text, 20)]]; break; }
			case '�': {str[i] = Alf[letter_pos_lit[search(letter_pos_text, 21)]]; break; }
			case '�': {str[i] = Alf[letter_pos_lit[search(letter_pos_text, 22)]]; break; }
			case '�': {str[i] = Alf[letter_pos_lit[search(letter_pos_text, 23)]]; break; }
			case '�': {str[i] = Alf[letter_pos_lit[search(letter_pos_text, 24)]]; break; }
			case '�': {str[i] = Alf[letter_pos_lit[search(letter_pos_text, 25)]]; break; }
			case '�': {str[i] = Alf[letter_pos_lit[search(letter_pos_text, 26)]]; break; }
			case '�': {str[i] = Alf[letter_pos_lit[search(letter_pos_text, 27)]]; break; }
			case '�': {str[i] = Alf[letter_pos_lit[search(letter_pos_text, 28)]]; break; }
			case '�': {str[i] = Alf[letter_pos_lit[search(letter_pos_text, 29)]]; break; }
			case '�': {str[i] = Alf[letter_pos_lit[search(letter_pos_text, 30)]]; break; }
			case '�': {str[i] = Alf[letter_pos_lit[search(letter_pos_text, 31)]]; break; }
			case '�': {str[i] = Alf[letter_pos_lit[search(letter_pos_text, 32)]]; break; }
			case '�': {str[i] = Alf[letter_pos_lit[search(letter_pos_text, 33)]]; break; } 
			default: break;
			}
			i++; 
		}
		return(str);
	}
	int search(int *mass,int search_letter) 
	{
		for (int i = 0; i < 33; i++)
		{
			if (mass[i] == search_letter) { return i; }
		}
	}
};