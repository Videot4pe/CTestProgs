#include <iostream>
#include <cstdio>
#include <fstream>
#include <vector>
#include <cstring>
#include <string>
 
 
using namespace std;
 
int main(int argc, char* argv[])
{
    int a, b, n, d, r;
    string c, v, kill, copy, copy2, copy3;
    string kl = "-d";

    ifstream in("phonebook.txt");
    in >> n;
     	if (argc > 1) {
     		r = argc-1;
     	}
     	else {
     		r=0;
     	}

    for(int y=0; y<r; y=y+1) {
        if (argv[y]==kl)
        {
        	kill = argv[y+1];
        }
    }

    vector <string> str(n+r);
    for (a=0; a<n; a++) {
     in >> str[a];
     in >> c;
     in >> v;
     str[a]=c+" "+str[a]+" "+v;
 	 
 	 if(v==kill) {
 	 	str.erase (str.begin()+a);
 	 }
 }
 int co=1;
 for (int i = n; i < n+r; ++i)
 {
   if (argv[co]!=kl)
   {
   str[i]=argv[co];
   int count=0;
   char ch=' ';
   while(str[i][count]!=ch) {
     copy = copy + str[i][count];
     count = count + 1;
   }
   count = count + 1;
    while(str[i][count]!=ch) {
     copy2 = copy2 + str[i][count];
     count = count + 1;
   }

   count = count + 1;
    while(count<strlen(argv[co])) {
     copy3 = copy3 + str[i][count];
     count = count + 1;
   }
   str[i]=copy2 + " " + copy + " " + copy3;
   }


   else {
   	if (co+1>r) {
   		break;
   	}
   	else {
   	co=co+1;
   	i = i + 1;
   }
   }
   co=co+1;
 }

for (int f=0; f<n+r; f++)
{
 
for (b=f+1; b<n+r; b++) {

        if (str[f].compare(str[b])>0) {
            c = "";
            c = str[b];
            str[b] = str[f];
            str[f] = c;
        }
     }
      cout << str[f] << "\n";
}
in.close();
    return 0;
}