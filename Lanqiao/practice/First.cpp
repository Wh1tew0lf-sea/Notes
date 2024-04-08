#include <bits/stdc++.h>

using namespace std;

char cr[100000];
float input;
int num;
double a,b,c;

int main(){
	
	cin >> a>>b>>c;
	double p = 0.5 * (a+b+c) ;
 	printf ("%.1lf",sqrt(p*(p-a)*(p-b)*(p-c)));
	return 0;
}
