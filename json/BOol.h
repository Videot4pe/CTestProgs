#ifndef BOOL_H
#define BOOL_H
#include "Object.h"
class BOol : public Object
{
public:
	BOol();
	BOol(const string &json, int &i);
	bool boolData;
	void print(int i);
};
#endif