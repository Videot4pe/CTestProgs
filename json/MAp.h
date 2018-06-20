#ifndef MAP_H
#define MAP_H
#include "Object.h"
class MAp : public Object
{
public:
	MAp();
	MAp(const string &json, int &i);
	
	map <string, Object *> objectData;
	void print(int i);
};
#endif