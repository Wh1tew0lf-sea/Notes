#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,Cx,Cy;
const int fx[] = {0, -2, -1, 1, 2, 2, 1, -1, -2};
const int fy[] = {0, 1, 2, 2, 1, -1, -2, -2, -1};
ll f[40][40];
bool s[40][40];


int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	cin>>n>>m>>Cx>>Cy;
	n+=2;m+=2;Cx+=2;Cy+=2;
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			s[i][j]=0;
			f[i][j]=0;
		}
	}
	
	
	f[2][1]=1;
	
	for(int i=0;i<=8;i++){
		s[Cx+fx[i]][Cy+fy[i]]=1;
	}
	
	for(int i=2;i<=n;i++){
		for(int j=2;j<=m;j++){
			if(s[i][j]) continue;
			f[i][j]=f[i-1][j]+f[i][j-1];
		}
	}
	cout << f[n][m];
	
	return 0;
	
}
