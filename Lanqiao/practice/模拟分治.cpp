#include <bits/stdc++.h>
#include <iostream>

using namespace std;
int a[1050][1050];
int n;

void fuzhi(int n,int x){
	if(n==x){
		return;
	}
	for(int i =pow(2,x);i<pow(2,x+1);i++){
		for(int j = 0;j<pow(2,x);j++){
			a[i][j] = a[i-(int)pow(2,x)][j];
		}
	}
	for(int i =pow(2,x);i<pow(2,x+1);i++){
		for(int j = 0;j<pow(2,x);j++){
			a[j][i] = a[j][i-(int)pow(2,x)];
		}
	}
	for(int i =pow(2,x);i<pow(2,x+1);i++){
		for(int j = pow(2,x);j<pow(2,x+1);j++){
			a[j][i] = 0;
		}
	}
	fuzhi(n,x+1);
}

int main(){
	cin >> n;
	int x = 1;
	a[0][0] = 1;
	a[1][1] = 0;
	a[1][0] = 1;
	a[0][1] = 1;
	fuzhi(n,x);
	for(int i = pow(2,n)-1;i>=0;i--){
		for(int j = pow(2,n)-1;j>=0;j--){
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
}
