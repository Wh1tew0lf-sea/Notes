#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int K;
string S;
char c1,c2;



int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	cin >>K>>S>>c1>>c2;
	int sum_c1=0;
	int n = S.size();
	LL ans=0;
	for(int i=K-1,j=0;i<n;i++,j++){
		if(S[j]==c1){
			++sum_c1;
		}
		if(S[i]==c2){
			ans+=sum_c1; //i����c2����ǰ�������c1 
		}
	}
	cout<< ans; 
	return 0;
}
/*

*/
