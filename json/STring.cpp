#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <cstring>
#include <string>
using namespace std;
#include "STring.h"

STring::STring()
{}

STring::STring(const string &json, int &i)
{
	string h;
	i++;
	for(; json[i] != '"'; i++)
	{
		if(json[i] == '\\')
		{
			i++;
		}
		
		h = h + json[i];
	}
	stringData = h;
}

void STring :: print (int i)
{
	cout << "\"" << stringData << "\" (Type String)" << endl;
}