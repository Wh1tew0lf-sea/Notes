#include <bits/stdc++.h>
using namespace std;
#define val first
#define pos second
typedef long long LL;
typedef pair<LL,int> PLI;
const int MAX_N=5e5+5;
int N,K ,pre[MAX_N],nxt[MAX_N];
LL A[MAX_N];
priority_queue<PLI>q;//优先队列 
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	cin >>N>>K;
	for(int i=1;i<=N;i++){
		cin >> A[i];
		pre[i]=i-1;
		nxt[i]=i+1;
		q.push({-A[i],-i});
	}
	pre[1]=-1;
	nxt[N]=-1;
	while(K--){
		PLI now;
		do{
			now =q.top();q.pop();
			now.val=-now.val;now.pos=-now.pos;
		}while(A[now.pos]!=now.val);
		int PRE=pre[now.pos];
		int NXT=nxt[now.pos];
		if(PRE!=-1){
			A[PRE]+=now.val;
			q.push({-A[PRE],-PRE});
			nxt[PRE]=NXT;
		}
		if(NXT!=-1){
			A[NXT]+=now.val;
			q.push({-A[NXT],-NXT});
			pre[NXT]=PRE;
		}		
		A[now.pos]=-1;
	}
	for(int i=1;i<=N;++i)
		if(A[i]!=-1)
			cout<<A[i]<<' ';
	return 0;
}
/*
*/
