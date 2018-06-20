#include <iostream>
#include <cstdio>
#include <fstream>
#include <vector>
#include <cstring>
#include <string>
#include <math.h>
 
using namespace std;
 

vector<vector<int> > findRoute(int A, int B, int N, vector<vector<int> > length, vector<int> prevRoute, vector<vector<int> > result)
{
    printf("A = %d, B = %d\n", A, B);

    if (A == B)
    {
            prevRoute.push_back(B);
            vector<vector<int> > resultingRoute;
            resultingRoute.push_back(prevRoute);
            printf("Found!\n");
            result.push_back(prevRoute);
            return result;
    }


    vector<int> nextPoints;
    for(int j = 0; j < N; j++)
    {
        bool check = false;
        for(int h = 0; h < prevRoute.size(); h++)
        {
            if(prevRoute[h] == j)
            {
                check = true;
                break;
            }
        }

        if((length[A][j] > -1) && (!check))
        {
            nextPoints.push_back(j);
            printf("%d\n", j);
        }
    }

    for (int i = 0; i < nextPoints.size(); ++i)
    {
        vector<int> lll = prevRoute;
        lll.push_back(A);
        result = findRoute(nextPoints[i], B, N, length, lll, result);
        //printf("A = %d\n", lll[A]);

    }

    return result;
}




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

    vector<vector<int> > len(N);
    for(int i = 0; i < N; i++)
    {
    	for(int j = 0; j < N; j++)
    	{
    		len[i].push_back(-1);
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



    vector<vector <int> > sort;


    //printf("A = %d, B = %d\n", a, b);

    a = a - 1;
    b = b - 1;
    int cp  = 0;

    sort = findRoute(a, b, N, len, vector<int>(), vector<vector<int> >());

    a = a + 1;
    b = b + 1;
   
        for (int en = 0; en < sort.size(); en++)
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

            // https://maps.yandex.ru/?ll=35.90260218%2C55.61553738&rl=35.90260218%2C55.61553738~0.91461182%2C0.32892490~1.34994507%2C-0.32115343

            cout << "\n";
        }
 	
}