#include <iostream>
#include <cstdio>
#include <fstream>
#include <vector>
#include <cstring>
#include <string>
#include <math.h>
 
using namespace std;
 
int main(int argc, char* argv[])
{
	const int radius = 6372795;
	const double pi = 3.14;
	int N, numberOfLinks, a, b, sw;
	vector <vector<double> > coordinates;
	vector <vector<int> > links;

	ifstream in("routeTestWorld2.txt");
    in >> N;
    for(int i = 0; i < N; i++)
    {
    	int trash;
    	in >> trash;

	 	vector<double> v;
	 	double x;

    	in >> x;
    	v.push_back(x);

     	in >> x;
     	v.push_back(x);

    	coordinates.push_back(v);
		
     	in >> numberOfLinks;
     	vector<int> s;
     	for (int i = 0; i < numberOfLinks; i++)
     	{
     		int y;
     		in >> y;
     		s.push_back(y);
     	}

     	links.push_back(s);
    }

    in >> a;
    in >> b;
    in.close();

    double len[N][N];
    for(int i = 0; i < N; i++)
    {
    	for(int j = 0; j < N; j++)
    	{
    		len[i][j] = -1;
    	}
    }

    for (int i = 0; i < N; i++)
    {
    	int l = links[i].size();
    	for (int j = 0; j < l; j++)
    	{
    		int pos = links[i][j];


    		// https://www.kobzarev.com/programming/calculation-of-distances-between-cities-on-their-coordinates.html


    		double lat1, lat2, long1, long2, cos1, cos2, sin1, sin2, delta, cdelta, sdelta, y, x, arctan, _length;

    		lat1 = coordinates[i][0] * M_PI / 180;
    		lat2 = coordinates[pos-1][0] * M_PI / 180;
    		long1 = coordinates[i][1] * M_PI / 180;
    		long2 = coordinates[pos-1][1] * M_PI / 180;

    		cos1 = cos(lat1);
     		cos2 = cos(lat2);

			sin1 = sin(lat1);
			sin2 = sin(lat2); 

			delta = long2 - long1;
			cdelta = cos(delta);
			sdelta = sin(delta); 

			x = sqrt(pow(cos2*sdelta, 2) + pow(cos1*sin2-sin1*cos2*cdelta, 2)); 	
			y = sin1*sin2 + cos1*cos2*cdelta;

			arctan = atan2(x, y);
			_length = arctan * radius;

    		
    		len[i][pos-1] = _length;
    	}
    }

	

vector <vector<int> > vec(N+1);
vector <vector<int> > integ(N);
vector <vector<int> > sort;
vector <double> ma;

double mass[N];

vec[a-1].push_back(a-1);

for (int i = 0; i < N; i++)
{
    mass[i] = 1. / 0.000000000000000000000001;
}
mass[a-1] = 0;

integ[a-1].push_back(a-1);


sw = -1;
b = b - 1;
for (int i = a - 1; i < N; i++)
{
    for (int j = 0; j < vec[i].size(); j++)
    {
        for (int k = 0; k < N; k++)
        {
            int f = vec[i][j];


            if(len[f][k] > -1)
            {   
            if (mass[k] > (mass[f] + len[f][k]))
            {
                mass[k] = mass[f] + len[f][k];


                vector <int> ll;
                integ[k] = integ[f];
                integ[k].push_back(k);

                if(k == b)
                {
                    sw = sw + 1;

                    if(sw > 0)
                    {
                        if(mass[b] < ma[sw-1])
                        {
                            double ch;
                            ch = ma[sw-1];
                            ma[sw-1] = mass[b];
                            ma.push_back(ch);

                            vector <vector<int> > ch2;
                            ch2.push_back(sort[sw-1]);
                            sort[sw-1] = integ[b];
                            sort.push_back(ch2[0]);
                        }
                        else
                        {
                            vector <int> ch2;
                            sort.push_back(ch2);
                            sort[sw] = integ[b];

                            ma.push_back(mass[b]);
                        }
                    }
                    else
                    {
                        vector <int> ch2;
                        sort.push_back(ch2);
                        sort[sw] = integ[k];

                        ma.push_back(mass[b]);
                    }

                }

            }
            if (k != b)
            {
                vec[i+1].push_back(k);
            }
            }

        }
    }
}


    cout << "\n";
    if(sw == -1)
    {
        cout << "No route =(" << endl;
    }
    else
    {
        for (int en = 0; en <= sw; en++)
        {
            cout << "https://maps.yandex.ru/?ll=" << coordinates[a-1][1] << "%2C" << coordinates[a-1][0] << "&rl=" << coordinates[a-1][1] << "%2C" << coordinates[a-1][0];

            int rl = a - 1;

            for (int end = 0; end < sort[en].size(); end++)
            {
                int rll = sort[en][end];
                cout << "~" << coordinates[rll][1] - coordinates[rl][1] << "%2C" << coordinates[rll][0] - coordinates[rl][0]; 
                rl = sort[en][end];                
            }
            cout << endl;


            for (int end = 0; end < sort[en].size(); end++)
            {
                cout << sort[en][end] + 1 << " точка" << endl;
            }

            cout << "Общее расстояние = " << ma[en] / 1000 << "км" << endl;

            // https://maps.yandex.ru/?ll=35.90260218%2C55.61553738&rl=35.90260218%2C55.61553738~0.91461182%2C0.32892490~1.34994507%2C-0.32115343

            cout << "\n";
        }
    }
 	
}