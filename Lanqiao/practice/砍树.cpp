#include <bits/stdc++.h>
#include <iostream>

using namespace std;
int N,L;
int h[1000002];
int tmp,Left,Right;

int main(){
	cin >> N >>L;
	Right = 0;
	for(int i =0;i<N;i++){
		cin >> h[i];
		if(h[i]>Right){
			Right = h[i]; 
		}
	}
	
	Left = 0;
	while(Left<=Right){//二分模板
		int mid=(Left+Right)>>1;//位运算
		tmp=0;
		for(int i=1;i<=N;i++) 
		    if(h[i]>mid) tmp+=h[i]-mid;
		if(tmp<L) Right=mid-1;
		else Left=mid+1;//模板
	}
	
	cout << Right ;
	return 0;
}
