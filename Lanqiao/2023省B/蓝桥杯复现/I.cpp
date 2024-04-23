#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAX_N=1e5+1;
vector<int>E[MAX_N],W[MAX_N];
int N,K,dep[MAX_N],fa[MAX_N][21],A[MAX_N];
LL dis[MAX_N]; 
void dfs(int u,int Fa){
	dep[u]=dep[Fa]+1;
	fa[u][0]=Fa;
	for(int i=1;i<=20;++i)
		fa[u][i]=fa[fa[u][i-1]][i-1];
	for(int i=0;i<E[u].size();++i){
		int v=E[u][i],w=W[u][i];
		if(v==Fa) continue;
		dis[v]=dis[u]+w;
		dfs(v,u);
	}
}
int LCA(int u,int v){
	if(dep[u]<dep[v]) swap(u,v);
	for(int i=20;i>=0;--i)
		if(dep[fa[u][i]]>=dep[v])
			u=fa[u][i];
	if(u==v) return u;
	for(int i=20;i>=0;--i)
		if(fa[u][i]!=fa[v][i]){
			u=fa[u][i];
			v=fa[v][i];
		}
	return fa[u][0];
}
LL path_dis(int u,int v){
	if(!u || !v) return 0;
	return dis[u]+dis[v]-2*dis[LCA(u,v)];
}
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	cin>>N>>K;
	for(int i=1;i<N;++i){
		int u,v,t; cin>>u>>v>>t;
		E[u].push_back(v);
		W[u].push_back(t);
		E[v].push_back(u);
		W[v].push_back(t);
	}
	dfs(1,0);
	LL ans=0;
	for(int i=1;i<=K;++i){
		cin>>A[i];
		ans+=path_dis(A[i],A[i-1]);
	}
	for(int i=1;i<=K;++i)
		cout<<ans-path_dis(A[i-1],A[i])-path_dis(A[i],A[i+1])+path_dis(A[i-1],A[i+1])<<' ';
	return 0;
}
/*
6 4
1 2 1
1 3 1
3 4 2
3 5 2
4 6 3
2 6 5 1
*/

