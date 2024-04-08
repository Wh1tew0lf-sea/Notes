#include <bits/stdc++.h>

using namespace std;
typedef double db;

const int N = 23333333; 
const db ans = 11625907.5798,eps=1e-4;

int main(){
	for(int v =0;v<=N/2;++v){
		int u = N-v;
		db res=-1.0*u*u/N*log2(1.0*u/N)-1.0*v*v/N*log2(1.0*v/N);
		if(fabs(res-ans)<eps){
			cout<<v;
			return 0;
		}
	}
	
	return 0;
}

//11027421
