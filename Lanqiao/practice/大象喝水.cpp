#include <bits/stdc++.h>
using namespace std;

double pi = 3.14;
int h,r;
int L = 20;
int main(){
	cin >> h >> r;
	double LL = pi * r*r *h;
	int num = ceil(20000 / LL);
	cout << num;
	return 0;
}
