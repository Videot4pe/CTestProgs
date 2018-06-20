#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <cstring>
#include <string>
using namespace std;
#include "Object.h"
#include "MAp.h"
#include "ARray.h"
#include "STring.h"
#include "BOol.h"
#include "INt.h"
#include "FLoat.h"
#include "F.h"

ARray::ARray(){}

ARray::ARray(const string &json, int &i)
{
	i++;

	for(; json[i] != ']'; i++)
	{

		clean(json, i);

		if(json[i] == ']')
		{
			break;
		}

		if(json[i] == '{')
		{
			arrayData.push_back(new MAp(json, i));
		}	

		if(json[i] == '[')
		{
			arrayData.push_back(new ARray(json, i));
		}

		if(json[i] == '"')
		{
			arrayData.push_back(new STring(json, i));	
		}

		if(json[i] == 'f' || json[i] == 't')
		{
			arrayData.push_back(new BOol(json, i));
		}

		if(isdigit(json[i]) > 0)
		{
			arrayData.push_back(IsDigit(json, i));
		}
	}
}
void ARray :: print (int i)
{
	i++;
	cout << "Array [" << endl;
	for(int j = 0; j < arrayData.size(); j++)
	{
		for(int l = 0; l < i; l++)
		{
			cout << "\t";
		}

		arrayData[j]->print(i);
	}
	for(int j = 0; j < i - 1; j++)
	{
			cout << "\t";
	}
	cout << "]" << endl;
}