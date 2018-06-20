#ifndef STRING_H
#define STRING_H
#include "Object.h"
class STring : public Object
{
public:
	STring();
	STring(const string &json, int &i);
	string stringData;	
	void print(int i);
};
#endif