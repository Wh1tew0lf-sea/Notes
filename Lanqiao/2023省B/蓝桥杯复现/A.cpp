#include <bits/stdc++.h>

using namespace std;
/*5686916124919823647759503875815861830379270588570991944686338516346707827689565614010094809128502533*/

bool vis[20240000];
char str[101] = "5686916124919823647759503875815861830379270588570991944686338516346707827689565614010094809128502533";
int a[100];
int ans;

bool check(int date){
	if(vis[date]) return false;
	vis[date]=1;
	int mm = date/100%100;
	int dd = date%100;
	if(mm<1||12<mm) return false;
	if((mm==1||mm==3||mm==5||mm==7||mm==8||mm==10||mm==12)){
		if(dd>=1&&dd<=31) return true;
	}else if(mm==2){
		if(dd>=1&&dd<=28) return true;
	}else if(1<=dd && dd <=30) return true;
	else return false;
}

void dfs(int x,int pos,int date){
	if(x==100) return;
	if(pos == 8){
		if(check(date)) ++ans;
		return;
	} 
	if( (pos==0&&a[x]==2)||
		(pos==1&&a[x]==0)||
		(pos==2&&a[x]==2)||
		(pos==3&&a[x]==3)||
		(pos==4&&a[x]>=0&&a[x]<=1)||
		(pos==5&&a[x]>=0&&a[x]<=9)||
		(pos==6&&a[x]>=0&&a[x]<=3)||
		(pos==7&&a[x]>=0&&a[x]<=9))
		dfs(x+1,pos+1,date*10+a[x]);
	dfs(x+1,pos,date);
}
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	for(int i=0;i<100;++i) cin>>a[i];
	dfs(0,0,0);
	cout<<ans; 
	return 0;
}
