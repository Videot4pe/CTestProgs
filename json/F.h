#ifndef F_H
#define F_H

#include "Object.h"
#include "MAp.h"
#include "ARray.h"
#include "STring.h"
#include "BOol.h"
#include "INt.h"
#include "FLoat.h"

Object *recObject(const string &json, int &i);
Object *recArray(const string &json, int &i);
void clean(const string &json, int &i);
Object *ArrayOrObject(const string &json, int &i);
string KeyValue(const string &json, int &i);
Object *IsDigit(const string &json, int &i);

#endif