
#pragma once

#include "stdafx.h"
#include <string>
using namespace std;
class Encryptor
{
public:
	string cypher(string str) 
	{
		int size = str.size();
		int i=0;
		while (i < size) 
		{
			switch (str[i]) 
			{
			case 'à': {str[i] = 'ç'; break; } 
			case 'á': {str[i] = 'è'; break; } 
			case 'â': {str[i] = 'é'; break; } 
			case 'ã': {str[i] = 'ê'; break; } 
			case 'ä': {str[i] = 'ë'; break; } 
			case 'å': {str[i] = 'ì'; break; }
			case '¸': {str[i] = 'í'; break; }
			case 'æ': {str[i] = 'î'; break; }
			case 'ç': {str[i] = 'ï'; break; }
			case 'è': {str[i] = 'ð'; break; }
			case 'é': {str[i] = 'ñ'; break; }
			case 'ê': {str[i] = 'ò'; break; }
			case 'ë': {str[i] = 'ó'; break; }
			case 'ì': {str[i] = 'ô'; break; }
			case 'í': {str[i] = 'õ'; break; }
			case 'î': {str[i] = 'ö'; break; }
			case 'ï': {str[i] = '÷'; break; }
			case 'ð': {str[i] = 'ø'; break; }
			case 'ñ': {str[i] = 'ù'; break; }
			case 'ò': {str[i] = 'ú'; break; }
			case 'ó': {str[i] = 'û'; break; }
			case 'õ': {str[i] = 'ü'; break; }
			case 'ô': {str[i] = 'ý'; break; }
			case 'ö': {str[i] = 'þ'; break; }
			case '÷': {str[i] = 'ÿ'; break; }
			case 'ø': {str[i] = 'à'; break; }
			case 'ù': {str[i] = 'á'; break; }
			case 'ú': {str[i] = 'â'; break; }
			case 'û': {str[i] = 'ã'; break; }
			case 'ü': {str[i] = 'ä'; break; }
			case 'ý': {str[i] = 'å'; break; }
			case 'þ': {str[i] = '¸'; break; }
			case 'ÿ': {str[i] = 'æ'; break; }
			case 'À': {str[i] = 'Ç'; break; }
			case 'Á': {str[i] = 'È'; break; }
			case 'Â': {str[i] = 'É'; break; }
			case 'Ã': {str[i] = 'Ê'; break; }
			case 'Ä': {str[i] = 'Ë'; break; }
			case 'Å': {str[i] = 'Ì'; break; }
			case '¨': {str[i] = 'Í'; break; }
			case 'Æ': {str[i] = 'Î'; break; }
			case 'Ç': {str[i] = 'Ï'; break; }
			case 'È': {str[i] = 'Ð'; break; }
			case 'É': {str[i] = 'Ñ'; break; }
			case 'Ê': {str[i] = 'Ò'; break; }
			case 'Ë': {str[i] = 'Ó'; break; }
			case 'Ì': {str[i] = 'Ô'; break; }
			case 'Í': {str[i] = 'Õ'; break; }
			case 'Î': {str[i] = 'Ö'; break; }
			case 'Ï': {str[i] = '×'; break; }
			case 'Ð': {str[i] = 'Ø'; break; }
			case 'Ñ': {str[i] = 'Ù'; break; }
			case 'Ò': {str[i] = 'Ú'; break; }
			case 'Ó': {str[i] = 'Û'; break; }
			case 'Õ': {str[i] = 'Ü'; break; }
			case 'Ô': {str[i] = 'Ý'; break; }
			case 'Ö': {str[i] = 'Þ'; break; }
			case '×': {str[i] = 'ß'; break; }
			case 'Ø': {str[i] = 'À'; break; }
			case 'Ù': {str[i] = 'Á'; break; }
			case 'Ú': {str[i] = 'Â'; break; }
			case 'Û': {str[i] = 'Ã'; break; }
			case 'Ü': {str[i] = 'Ä'; break; }
			case 'Ý': {str[i] = 'Å'; break; }
			case 'Þ': {str[i] = '¨'; break; }
			case 'ß': {str[i] = 'Æ'; break; }
			default: break;
			}
			i++; 
		}
		return(str);
	}

};