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

MAp::MAp(){}

MAp::MAp(const string &json, int &i)
{
	i++;
	for(; json[i] != '}'; i++)
	{
		string key = "";
		
		clean(json, i);

		if(json[i] == '}')
		{
			break;
		}

		if(json[i] == '"')
		{
			key = KeyValue(json, i);
		}

		for(; json[i] != ':'; i++){}

		i++;

		clean(json, i);

		if(json[i] == '"')
		{
			objectData[key] = new STring(json, i);
		}

		if(json[i] == 'f' || json[i] == 't')
		{
			objectData[key] = new BOol(json, i);
		}

		if(json[i] == '[')
		{
			objectData[key] = new ARray(json, i);
		}

		if(json[i] == '{')
		{
			objectData[key] = new MAp(json, i);
		}

		if(isdigit(json[i]) > 0)
		{
			objectData[key] = IsDigit(json, i);
		}
	}
}

void MAp :: print (int i)
{
	i++;
	cout << "Object {" << endl;
	auto it = objectData.begin();
	for(; it != objectData.end(); ++it) 
	{
		for(int j = 0; j < i; j++)
		{
			cout << "\t";
		}

  		cout << "\"" << it->first << "\" : ";
  		it->second->print(i);
  	}

  	for(int j = 0; j < i - 1; j++)
	{
			cout << "\t";
	}

  	cout << "}" << endl;
}