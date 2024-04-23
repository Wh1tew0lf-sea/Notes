#include <bits/stdc++.h>
using namespace std;
int M,N;
const int MAX_N=51;
string mp[MAX_N];
bool vis[MAX_N][MAX_N],used[MAX_N][MAX_N];
int dx[]={0,0,1,-1,1,-1,1,-1};
int dy[]={1,-1,0,0,1,1,-1,-1};
void bfs_col(int x,int y){
	queue<int>qx,qy;
	qx.push(x);qy.push(y);vis[x][y]=1;
	while(!qx.empty()){
		x=qx.front();qx.pop();
		y=qy.front();qy.pop();
		for(int i=0;i<4;++i){
			int nx=x+dx[i];
			int ny=y+dy[i];
			if(nx<0 || M<=nx || ny<0 || N<=ny || vis[nx][ny] || mp[nx][ny]=='0') continue;
			qx.push(nx);qy.push(ny);vis[nx][ny]=1;
		}
	}
}

bool bfs_out(int x,int y){
	for(int i=0;i<M;i++){
		for(int j=0;j<N;++j){
			used[i][j]=0;
		}
	}
	queue<int>qx,qy;
	qx.push(x);qy.push(y);used[x][y]=1;
	while(!qx.empty()){
		x=qx.front();qx.pop();
		y=qy.front();qy.pop();
		if(x==0||x==M-1||y==0||y==N-1) return true;
		for(int i=0;i<8;i++){
			int nx=x+dx[i];
			int ny=y+dy[i];
			if(nx<0 || M<=nx || ny<0 || N<=ny || used[nx][ny] || mp[nx][ny]=='1') continue;
			qx.push(nx); qy.push(ny); used[nx][ny]=1;
		}
	}
	return false;
}
void solve(){
	cin >> M>> N;
	int ans =0;
	for(int i=0;i<M;i++){
		cin>>mp[i];
		for(int j=0;j<N;j++){
			vis[i][j]=0;
		}
	}
	for(int i=0;i<M;i++){
		for(int j=0;j<N;j++){
			if(!vis[i][j] && mp[i][j]=='1'){
				bfs_col(i,j);
				if(bfs_out(i,j)) ++ans;
			}
		}
	}
	cout << ans<< '\n';
	
}
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int T; cin >>T;
	while(T--) solve();
	
	return 0;
}

/*
С���õ���һ����СΪ M ��N�ĸ��ӵ�ͼ�����Խ�������һ��ֻ�����ַ���0��������ˮ���� ��1��������½�أ��Ķ�ά���飬��ͼ֮���������ȫ���Ǻ�ˮ��ÿ������������/��/��/���ĸ����������ڵ� ��1�� �����Ӷ��γɡ�
�ڵ��� A ��ռ�ݵĸ����У�������Դ���ѡ�� k ����ͬ�ĸ��ӣ�ʹ�����ǵ������ܹ����һ�����������У�(x0, y0),(x1, y1), . . . ,(xk?1, yk?1)������(x(i+1)%k , y(i+1)%k) ���� (xi , yi) ͨ����/��/��/���ƶ�һ�ε����� (0 �� i �� k ? 1)��
��ʱ��k�����Ӿ͹�����һ��������.�����һ������ B ��ռ�ݵĸ���ȫ��λ����� ������ �ڲ�����ʱ���ǽ����� B �����ǵ��� A ���ӵ��졣�� B �� A ���ӵ��죬C ���� B ���ӵ��죬�� C Ҳ�� A ���ӵ��졣
���������ͼ�Ϲ��ж��ٸ����죿�ڽ���ͳ��ʱ����Ҫͳ���ӵ������Ŀ��
*/
