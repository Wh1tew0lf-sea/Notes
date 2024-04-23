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
小蓝得到了一副大小为 M ×N的格子地图，可以将其视作一个只包含字符‘0’（代表海水）和 ‘1’（代表陆地）的二维数组，地图之外可以视作全部是海水，每个岛屿由在上/下/左/右四个方向上相邻的 ‘1’ 相连接而形成。
在岛屿 A 所占据的格子中，如果可以从中选出 k 个不同的格子，使得他们的坐标能够组成一个这样的排列：(x0, y0),(x1, y1), . . . ,(xk?1, yk?1)，其中(x(i+1)%k , y(i+1)%k) 是由 (xi , yi) 通过上/下/左/右移动一次得来的 (0 ≤ i ≤ k ? 1)，
此时这k个格子就构成了一个“环”.如果另一个岛屿 B 所占据的格子全部位于这个 “环” 内部，此时我们将岛屿 B 视作是岛屿 A 的子岛屿。若 B 是 A 的子岛屿，C 又是 B 的子岛屿，那 C 也是 A 的子岛屿。
请问这个地图上共有多少个岛屿？在进行统计时不需要统计子岛屿的数目。
*/
