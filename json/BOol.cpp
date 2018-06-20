#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <cstring>
#include <string>
using namespace std;
#include "BOol.h"

BOol::BOol()
{}

BOol::BOol(const string &json, int &i)
{
	string h = "";

	for(int k = i + 4; i < k; i++)
	{
		h = h + json[i];
	}

	if((h == "true") && (json[i] == ',' || json[i] == ' ' || json[i] == '\t' || json[i] == '\r' || json[i] == '\n'))
	{
		boolData = true;
	}
	else
	{
		h = h + json[i];
		i++;
		if ((h == "false") && (json[i] == ',' || json[i] == ' ' || json[i] == '\t' || json[i] == '\r' || json[i] == '\n'))
		{
			boolData = false;
		}
		else
		{
			cout << "error" << endl;
			exit(1);
		}
	}
}
void BOol :: print (int i)
{
	cout.setf(ios::boolalpha);
	cout << boolData << " (Type Bool)" << endl;
}