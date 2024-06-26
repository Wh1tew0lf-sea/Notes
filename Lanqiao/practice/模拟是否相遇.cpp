#include <bits/stdc++.h>
#include <iostream>

using namespace std;

char m[12][12];//地图
int f[3],c[3],ans,tdz;//农夫，奶牛，秒数，专属值
bool zt[160005];//记录专属值是否出现
void move(int x,int y,int mi,int h){//移动函数
	if (mi==0){
		if (m[x-1][y]=='*') if (h==0) f[0]=1; else c[0]=1;
		else if (h==0) f[1]--; else c[1]--;
	}else if (mi==1){
		if (m[x][y+1]=='*') if (h==0) f[0]=2; else c[0]=2;
		else if (h==0) f[2]++; else c[2]++;
	}else if (mi==2){
		if (m[x+1][y]=='*') if (h==0) f[0]=3; else c[0]=3;
		else if (h==0) f[1]++; else c[1]++;
	}else{
		if (m[x][y-1]=='*') if (h==0) f[0]=0; else c[0]=0;
		else if (h==0) f[2]--; else c[2]--;
	}
}

bool pd(){ //判断循环终止条件：如果奶牛坐标与农夫坐标相等，则他们重叠，返回0，退出循环
	if (f[1]==c[1]&&f[2]==c[2]) return 0;
	else return 1;
}

int main(){
	for (int i=0;i<=11;i++) m[i][0]='*',m[i][11]='*';
	for (int i=1;i<=11;i++) m[0][i]='*',m[11][i]='*';
    for (int i=1;i<=10;i++){
    	for (int j=1;j<=10;j++){
    		cin>>m[i][j];
    		if (m[i][j]=='F') f[1]=i,f[2]=j;
    		if (m[i][j]=='C') c[1]=i,c[2]=j;
		}
	}
	while (pd()){//模拟每秒
		tdz=f[1]+f[2]*10+c[1]*100+c[2]*1000+f[0]*10000+c[0]*40000;
		if (zt[tdz]){//死循环了就输出0并结束程序
			cout<<0<<endl;
			return 0;
		}
		zt[tdz]=1;//标记
		move(f[1],f[2],f[0],0);
		move(c[1],c[2],c[0],1);//依次移动农夫和奶牛
		ans++;//记录秒数
	}
	cout<<ans<<endl;//输出
    return 0;
}
