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

Object *ArrayOrObject(const string &json, int &i)
{
	Object *o;
	if(json[i] == '{')
	{
		o = new MAp(json, i);
	}
	
	if(json[i] == '[')
	{
		o = new ARray(json, i);
	}
	return o;
}

string KeyValue(const string &json, int &i)
{
	string key = "";
	i++;
	for(; json[i] != '"'; i++)
	{
		if(json[i] == '\\')
		{
			i++;
		}
		key = key + json[i];
	}
	return key;
}

Object *IsDigit(const string &json, int &i)
{
			string h;
			bool check = true;
			for(; isdigit(json[i]) > 0 || json[i] == '.'; i++)
			{
				h = h + json[i];

				if(json[i] == '.')
				{
					check = false;	
				}
			}

			if(check)
			{
				INt *l = new INt;
				int b = atoi(h.c_str());
				l->intData = b;
				return l;
			}
			else
			{
				FLoat *l = new FLoat;
				double b = atof(h.c_str());
				l->floatData = b;
				return l;
			}
}

void clean(const string &json, int &i)
{
	for(; json[i] == ' ' || json[i] == '\n' || json[i] == '\r' || json[i] == '\t' || json[i] == ','; i++)
	{}	
	return;
}