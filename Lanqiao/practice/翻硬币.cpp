#include <bits/stdc++.h>
using namespace std;
int MAX_N=1001;
string a,b;
int ans;
void turn(int i){
	if(a[i]=='*'){
		a[i]='o';
	}else{
		a[i]='*';
	}
	//a[i]=a[i]=='o'?'*':'o';
}

int main(){
	cin >>a>>b;
	int l =a.size();
	ans=0;
	for(int i=0;i<l-1;i++){
		if(a[i]!=b[i]){
			turn(i+1);
			ans++;
		}
	}
	cout << ans;
	return 0;
}
