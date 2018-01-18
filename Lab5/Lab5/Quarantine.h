#include "stdafx.h"

using namespace std;

class messages
{
public:
	vector <string> textV,wordV;
	vector <int> numV;
	int sizeT = 0;
	messages()
	{
		int n = 0;
		string tmp, text = "";
		text = readFile("Text.txt");
		int size = text.size();
		for (int i = 0; i < size; i++)
		{
			if ((text[i] == '\n') | (i == size - 1))
			{
				for (int p = n; p < i + 1; p++)
				{
					if ((text[p] != '\n')&(text[p] != '\r')) tmp.push_back(text[p]);
				}
				textV.push_back(tmp);
				tmp.clear();
				n = i;
			}
		}
		sizeT = textV.size();
	}
	string readFile(const string& name)
	{
		ifstream fin;
		fin.open(name, ios::binary);
		stringstream fstr;
		fstr << fin.rdbuf();
		fin.close();

		return fstr.str();
	}
	void clrF(const string& name)
	{

		ofstream fout;
		fout.open(name, ios::binary);
		fout << "";
		fout.close();
	}
	void writeFile(const string& name, const string& sourse)
	{
		ofstream fout;
		fout.open(name, ios_base::app);
		fout << sourse;
		fout.close();
	}

	void filtM()
	{
		//int* flag=new int[sizeT];
		bool flag = true;
		vector <string> resV;
		for (int i = sizeT-1; i != -1; i--)
		{
			//thread thr(filt,i,flag);
			//thr.join();
			/*
			for (int i = sizeT - 1; i != -1; i--)
			{
				if (flag[i] == 0)
				{
					textV.pop_back();
					sizeT = textV.size();
				}
				else
				{
					resV.push_back(textV[i]);
					textV.pop_back();
					sizeT = textV.size();

				}
			}*/
			for (int p = 0; p < textV[i].size(); p++)
			{
				if ((textV[i][p] == '1') | (textV[i][p] == '2') | (textV[i][p] == '3') | (textV[i][p] == '4') | (textV[i][p] == '5') | (textV[i][p] == '6') | (textV[i][p] == '7') | (textV[i][p] == '8') | (textV[i][p] == '9'))
				{
					flag = false;
					break;
				}
			}
			if (flag == false)
			{
			textV.pop_back();
			sizeT = textV.size();
			flag = true;
			}
			else
			{
			resV.push_back(textV[i]);
			textV.pop_back();
			sizeT = textV.size();
			
			}
		}
		
		textV = resV;
		sizeT = textV.size();
	}
	
	void filtW(int num)
	{
	//	vector <string> wV;
		string tmp="";
		for (int i = 0; i < textV[num].size(); i++)
		{
			
			if (textV[num][i] == ' ')
			{
				wordV.push_back(tmp);
				numV.push_back(i);
				tmp = "";
			}
			else if (i == textV[num].size() - 1)
			{
				tmp += textV[num][i];
				wordV.push_back(tmp);
				numV.push_back(i);
				tmp = "";
			}
			else tmp += textV[num][i];
		}
		//wordV = wV;
		wordV.push_back("1");
	}
	void filtMW()
	{
		for (int i = 0; i < sizeT; i++)
		{
			filtW(i);
		}
		for (int i = 0; i < wordV.size(); i++)
		{
			for (int p = 2; p < wordV[i].size(); p++)
			{
				if (((wordV[i][p-2] == 'ì') | (wordV[i][p-2] == 'Ì')) & (wordV[i][p-1] == 'å') & (wordV[i][p] == 'ë'))
				{
					wordV[i][p - 2] = 'â';
					wordV[i][p - 1] = 'û';
					wordV[i][p] = 'ñ';
				}
				if ((wordV[i][p-2] == 'Î') | (wordV[i][p-2] == 'î'))
				{
					wordV[i][p-2] = 'à';
				}
				else if ((wordV[i][p - 1] == 'Î') | (wordV[i][p - 1] == 'î'))
				{
					wordV[i][p - 1] = 'à';
				}
				else if ((wordV[i][p] == 'Î') | (wordV[i][p] == 'î'))
				{
					wordV[i][p] = 'à';
				}
			}
		}
		bonding();

	}
	void bonding()
	{
		string out;
		vector <string> outV;
			for (int i = 0; i < wordV.size(); i++)
			{
				if (wordV[i] == "1")
				{
					out += '\r';
					out += '\n';
					outV.push_back(out);
					out = "";
				}
				else out += wordV[i] + " ";
			}	
			clrF("Out.txt");
		for (int p = outV.size()-1; p!=-1;p--)
		{
			writeFile("Out.txt", outV[p]);
		}
	}
};