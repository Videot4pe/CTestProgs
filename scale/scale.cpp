#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <string.h>
#include <tgmath.h>
 
using namespace std;
 
int main(int argc, char* argv[])
{
	string scale, t, pp;
	char e;
	int a, count, i, p; 
	double ro, f, hz, b;
	vector <string> n(13);
	vector <int> m(8);
	vector <int> mj(8);

	n[0]="C";
	n[1]="C#";
	n[2]="D";
	n[3]="D#";
	n[4]="E";
	n[5]="F";
	n[6]="F#";
	n[7]="G";
	n[8]="G#";
	n[9]="A";
	n[10]="A#";
	n[11]="B";

	m[0]=2;
	m[1]=1;
	m[2]=2;
	m[3]=2;
	m[4]=1;
	m[5]=2;
	m[6]=2;
	m[7]=2;

	mj[0]=2;
	mj[1]=2;
	mj[2]=1;
	mj[3]=2;
	mj[4]=2;
	mj[5]=2;
	mj[6]=1;
	mj[7]=1;

	scale = argv[1];
	if(argc > 2) 
	{
		p = atoi (argv[2]);
		p = p - 1;
	}
	else
	{
		p = 0;
	}

	i = 0;
	count = 0;

	a = scale.length();
	e = 'm';
	if(scale[a-1] == e)
	{
		a = a - 2;
		count = 1;
	}
	else
	{
		a = a - 1;
	}

	for(int g = 0; g <= a; g++)
	{
		t = t + scale[g];
	}

	while(t != n[i])
	{
		i = i + 1;
	}



	b = i;

	vector <int> scalee;

	if (count == 1)
	{
		scalee = m;
	}
	else 
	{
		scalee = mj;
	}

	ro = i + p * 12;

	p = p + 1;
	for(int l = 0; l < 8; l++)
	{

		f = (ro - 9) / 12;
		hz = 440*pow(2, f);

		cout<<n[i]<<p<<" ("<<hz<<"Hz) \n";

		i = i + scalee[l];
		ro = ro + scalee[l];
		
		if(i > 11)
		{
			if (i - 11 == 1)
			{
				i = 0;
			}
			else
			{
				i = 1;
			}
			p = p + 1;
		}
	}

}