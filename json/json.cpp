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

int main(int argc, char* argv[])
{
	ifstream in("songsTest.json");

	string json((std::istreambuf_iterator<char>(in)),
                 std::istreambuf_iterator<char>());

	int i = 0;

	clean(json, i);
	
	ArrayOrObject(json, i)->print();
}