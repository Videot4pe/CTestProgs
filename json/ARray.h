#ifndef ARRAY_H
#define ARRAY_H
#include "Object.h"
class ARray : public Object
{
public:
	ARray();
	ARray(const string &json, int &i);
	vector<Object *> arrayData;	
	void print(int i);
};
#endif