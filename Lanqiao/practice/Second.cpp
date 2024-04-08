#include <bits/stdc++.h>

using namespace std;

double s,v,m;

int print(int a , int b){
	if(a<10)//ÂýÂýÅÐ¶ÏÊÇ·ñ²¹0
	{
		if(b<10) cout<<"0"<<a<<":0"<<b;
		else cout<<"0"<<a<<":"<<b;
	}
	else
	{
		if(b<10) cout<<a<<":0"<<b;
		else cout<<a<<":"<<b;
	}
	return 0;
}

int main(){
	int time = (8+24)*60;
	cin >> s >> v;
	int t = ceil(s/v) + 10;
	time -= t;
	int t1,t2;
	if (time>= 24*60){
		time -= 24*60;
	}
	t1 = time/60;
	t2 = time%60;
	print(t1,t2);
	
	return 0;
}


