
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
	string alf = " абвгдеёжзийклмнопрстуфхцчшщъыьэюя"; 
	string Alf = " АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ"; 
	
	
	
	string decrypt(string str) 
	{
		cout << "Мне нужен какой-то исходный текст, для подсчета букв! Зачитайте на изусть какое-то произведение в блокноте." << '\n';
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
			case 'а': {mass[0]++; break; } 
			case 'б': {mass[1]++; break; } 
			case 'в': {mass[2]++; break; } 
			case 'г': {mass[3]++; break; } 
			case 'д': {mass[4]++; break; }
			case 'е': {mass[5]++; break; }
			case 'ё': {mass[6]++; break; }
			case 'ж': {mass[7]++; break; }
			case 'з': {mass[8]++; break; }
			case 'и': {mass[9]++; break; }
			case 'й': {mass[10]++; break; }
			case 'к': {mass[11]++; break; }
			case 'л': {mass[12]++; break; }
			case 'м': {mass[13]++; break; }
			case 'н': {mass[14]++; break; }
			case 'о': {mass[15]++; break; }
			case 'п': {mass[16]++; break; }
			case 'р': {mass[17]++; break; }
			case 'с': {mass[18]++; break; }
			case 'т': {mass[19]++; break; }
			case 'у': {mass[20]++; break; }
			case 'х': {mass[21]++; break; }
			case 'ф': {mass[22]++; break; }
			case 'ц': {mass[23]++; break; }
			case 'ч': {mass[24]++; break; }
			case 'ш': {mass[25]++; break; }
			case 'щ': {mass[26]++; break; }
			case 'ъ': {mass[27]++; break; }
			case 'ы': {mass[28]++; break; }
			case 'ь': {mass[29]++; break; }
			case 'э': {mass[30]++; break; }
			case 'ю': {mass[31]++; break; }
			case 'я': {mass[32]++; break; }
			case 'А': {mass[0]++; break; }
			case 'Б': {mass[1]++; break; }
			case 'В': {mass[2]++; break; }
			case 'Г': {mass[3]++; break; }
			case 'Д': {mass[4]++; break; }
			case 'Е': {mass[5]++; break; }
			case 'Ё': {mass[6]++; break; }
			case 'Ж': {mass[7]++; break; }
			case 'З': {mass[8]++; break; }
			case 'И': {mass[9]++; break; }
			case 'Й': {mass[10]++; break; }
			case 'К': {mass[11]++; break; }
			case 'Л': {mass[12]++; break; }
			case 'М': {mass[13]++; break; }
			case 'Н': {mass[14]++; break; }
			case 'О': {mass[15]++; break; }
			case 'П': {mass[16]++; break; }
			case 'Р': {mass[17]++; break; }
			case 'С': {mass[18]++; break; }
			case 'Т': {mass[19]++; break; }
			case 'У': {mass[20]++; break; }
			case 'Х': {mass[21]++; break; }
			case 'Ф': {mass[22]++; break; }
			case 'Ц': {mass[23]++; break; }
			case 'Ч': {mass[24]++; break; }
			case 'Ш': {mass[25]++; break; }
			case 'Щ': {mass[26]++; break; }
			case 'Ъ': {mass[27]++; break; }
			case 'Ы': {mass[28]++; break; }
			case 'Ь': {mass[29]++; break; }
			case 'Э': {mass[30]++; break; }
			case 'Ю': {mass[31]++; break; }
			case 'Я': {mass[32]++; break; }
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
			case 'а': {str[i]=alf[letter_pos_lit[search(letter_pos_text, 1)]]; break; } 
			case 'б': {str[i] = alf[letter_pos_lit[search(letter_pos_text, 2)]]; break; } 
			case 'в': {str[i] = alf[letter_pos_lit[search(letter_pos_text, 3)]]; break; } 
			case 'г': {str[i] = alf[letter_pos_lit[search(letter_pos_text, 4)]]; break; } 
			case 'д': {str[i] = alf[letter_pos_lit[search(letter_pos_text, 5)]]; break; } 
			case 'е': {str[i] = alf[letter_pos_lit[search(letter_pos_text, 6)]]; break; }
			case 'ё': {str[i] = alf[letter_pos_lit[search(letter_pos_text, 7)]]; break; }
			case 'ж': {str[i] = alf[letter_pos_lit[search(letter_pos_text, 8)]]; break; }
			case 'з': {str[i] = alf[letter_pos_lit[search(letter_pos_text, 9)]]; break; }
			case 'и': {str[i] = alf[letter_pos_lit[search(letter_pos_text, 10)]]; break; }
			case 'й': {str[i] = alf[letter_pos_lit[search(letter_pos_text, 11)]]; break; }
			case 'к': {str[i] = alf[letter_pos_lit[search(letter_pos_text, 12)]]; break; }
			case 'л': {str[i] = alf[letter_pos_lit[search(letter_pos_text, 13)]]; break; }
			case 'м': {str[i] = alf[letter_pos_lit[search(letter_pos_text, 14)]]; break; }
			case 'н': {str[i] = alf[letter_pos_lit[search(letter_pos_text, 15)]]; break; }
			case 'о': {str[i] = alf[letter_pos_lit[search(letter_pos_text, 16)]]; break; }
			case 'п': {str[i] = alf[letter_pos_lit[search(letter_pos_text, 17)]]; break; }
			case 'р': {str[i] = alf[letter_pos_lit[search(letter_pos_text, 18)]]; break; }
			case 'с': {str[i] = alf[letter_pos_lit[search(letter_pos_text, 19)]]; break; }
			case 'т': {str[i] = alf[letter_pos_lit[search(letter_pos_text, 20)]]; break; }
			case 'у': {str[i] = alf[letter_pos_lit[search(letter_pos_text, 21)]]; break; }
			case 'х': {str[i] = alf[letter_pos_lit[search(letter_pos_text, 22)]]; break; }
			case 'ф': {str[i] = alf[letter_pos_lit[search(letter_pos_text, 23)]]; break; }
			case 'ц': {str[i] = alf[letter_pos_lit[search(letter_pos_text, 24)]]; break; }
			case 'ч': {str[i] = alf[letter_pos_lit[search(letter_pos_text, 25)]]; break; }
			case 'ш': {str[i] = alf[letter_pos_lit[search(letter_pos_text, 26)]]; break; }
			case 'щ': {str[i] = alf[letter_pos_lit[search(letter_pos_text, 27)]]; break; }
			case 'ъ': {str[i] = alf[letter_pos_lit[search(letter_pos_text, 28)]]; break; }
			case 'ы': {str[i] = alf[letter_pos_lit[search(letter_pos_text, 29)]]; break; }
			case 'ь': {str[i] = alf[letter_pos_lit[search(letter_pos_text, 30)]]; break; }
			case 'э': {str[i] = alf[letter_pos_lit[search(letter_pos_text, 31)]]; break; }
			case 'ю': {str[i] = alf[letter_pos_lit[search(letter_pos_text, 32)]]; break; }
			case 'я': {str[i] = alf[letter_pos_lit[search(letter_pos_text, 33)]]; break; }
			case 'А': {str[i] = Alf[letter_pos_lit[search(letter_pos_text, 1)]]; break; }
			case 'Б': {str[i] = Alf[letter_pos_lit[search(letter_pos_text, 2)]]; break; }
			case 'В': {str[i] = Alf[letter_pos_lit[search(letter_pos_text, 3)]]; break; }
			case 'Г': {str[i] = Alf[letter_pos_lit[search(letter_pos_text, 4)]]; break; }
			case 'Д': {str[i] = Alf[letter_pos_lit[search(letter_pos_text, 5)]]; break; }
			case 'Е': {str[i] = Alf[letter_pos_lit[search(letter_pos_text, 6)]]; break; }
			case 'Ё': {str[i] = Alf[letter_pos_lit[search(letter_pos_text, 7)]]; break; }
			case 'Ж': {str[i] = Alf[letter_pos_lit[search(letter_pos_text, 8)]]; break; }
			case 'З': {str[i] = Alf[letter_pos_lit[search(letter_pos_text, 9)]]; break; }
			case 'И': {str[i] = Alf[letter_pos_lit[search(letter_pos_text, 10)]]; break; }
			case 'Й': {str[i] = Alf[letter_pos_lit[search(letter_pos_text, 11)]]; break; }
			case 'К': {str[i] = Alf[letter_pos_lit[search(letter_pos_text, 12)]]; break; }
			case 'Л': {str[i] = Alf[letter_pos_lit[search(letter_pos_text, 13)]]; break; }
			case 'М': {str[i] = Alf[letter_pos_lit[search(letter_pos_text, 14)]]; break; }
			case 'Н': {str[i] = Alf[letter_pos_lit[search(letter_pos_text, 15)]]; break; }
			case 'О': {str[i] = Alf[letter_pos_lit[search(letter_pos_text, 16)]]; break; }
			case 'П': {str[i] = Alf[letter_pos_lit[search(letter_pos_text, 17)]]; break; }
			case 'Р': {str[i] = Alf[letter_pos_lit[search(letter_pos_text, 18)]]; break; }
			case 'С': {str[i] = Alf[letter_pos_lit[search(letter_pos_text, 19)]]; break; }
			case 'Т': {str[i] = Alf[letter_pos_lit[search(letter_pos_text, 20)]]; break; }
			case 'У': {str[i] = Alf[letter_pos_lit[search(letter_pos_text, 21)]]; break; }
			case 'Х': {str[i] = Alf[letter_pos_lit[search(letter_pos_text, 22)]]; break; }
			case 'Ф': {str[i] = Alf[letter_pos_lit[search(letter_pos_text, 23)]]; break; }
			case 'Ц': {str[i] = Alf[letter_pos_lit[search(letter_pos_text, 24)]]; break; }
			case 'Ч': {str[i] = Alf[letter_pos_lit[search(letter_pos_text, 25)]]; break; }
			case 'Ш': {str[i] = Alf[letter_pos_lit[search(letter_pos_text, 26)]]; break; }
			case 'Щ': {str[i] = Alf[letter_pos_lit[search(letter_pos_text, 27)]]; break; }
			case 'Ъ': {str[i] = Alf[letter_pos_lit[search(letter_pos_text, 28)]]; break; }
			case 'Ы': {str[i] = Alf[letter_pos_lit[search(letter_pos_text, 29)]]; break; }
			case 'Ь': {str[i] = Alf[letter_pos_lit[search(letter_pos_text, 30)]]; break; }
			case 'Э': {str[i] = Alf[letter_pos_lit[search(letter_pos_text, 31)]]; break; }
			case 'Ю': {str[i] = Alf[letter_pos_lit[search(letter_pos_text, 32)]]; break; }
			case 'Я': {str[i] = Alf[letter_pos_lit[search(letter_pos_text, 33)]]; break; } 
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