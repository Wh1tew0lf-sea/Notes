#include <bits/stdc++.h>
#include <iostream>

using namespace std;
int L;

int main(){
	cin >> L;
	int p = 2;
	if(L == 2){
		cout<< 2 << endl <<1;
		return 0;
	}
	if(L == 1){
		cout <<0;
		return 0;
	}
	int pline[100000] = {0};
	int sum = 2;
	int num = 1;
	pline[0]=2;
	for(int i = 3;;i++){
		int e = 0;
		for(int j = 0;j<num;j++){
			if(i%pline[j]==0){
				e=1;
			}
		}
		if(e==0){
			if(sum + i <= L){
				sum +=i;
				pline[num] = i;
			    num++;
			}
			else{
				break;
			}
			
			
		}
	} 
	for(int i = 0;i<num;i++){
		cout <<pline[i]<<endl;
	}
	cout << num << endl;
	return 0;
}
