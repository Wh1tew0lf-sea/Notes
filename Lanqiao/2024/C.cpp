#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e7+1;
int N;
int total[8];
bool top[8];

bool check(int i){
	int p = i%10;
	return p&1;  
}

int count(int x,int n){
	int s=1;
	for(int i=0;i<n;i++){
		s*=5;
	}
	s*=x;
	return s;
}//x*5^^n

int main(){
	cin >> N;
	int length=0;
	int ans=0;
	int A = N;
	while(A!=0){
		A/=10;
		top[length]=0;
		length++;
	}
	
	for(int i=0;i<length;i++){
		int now = N%10;//shuzi 
		N=N/10;
		if(check(i+1)&&check(now)){
			top[i]=1;
		}else if(!check(i+1)&&!check(now)){
			top[i]=1;
		}else{
			top[i]=0;
		}
		
		int tmp;
		if(check(i+1)){//jishu
			tmp = (now+1)/2;
		}else{//oushu
			tmp = (now/2)+1;
		}
		total[i] = tmp;
	}//top,total
	
	for(int pos=length-1;pos>=0;pos--){
		
		if(top[pos]){
			ans += count(total[pos]-1,pos);
		}else{
			ans+= count(total[pos],pos);
			break;
		}
	}
	cout << ans;
	return 0;
}
