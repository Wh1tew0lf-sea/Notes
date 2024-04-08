#include <bits/stdc++.h>
using namespace std;
const int MAX_N=11;
int N,T[MAX_N],D[MAX_N],L[MAX_N];
bool have_answer;
bool used[MAX_N];
void dfs(int x ,int time){
	if(have_answer) return;
	if(x==N){
		have_answer=1;
		return;
	}
	for(int i=1;i<=N;i++){
		if(!used[i]&&time<=T[i]+D[i]){
			used[i]=1;
			dfs(x+1,max(T[i],time)+L[i]);
			if(have_answer) return;
			used[i]=0;
		}
	}
}
void solve(){
	have_answer=0;
	cin >>N;
	for (int i=1;i<=N;++i){
		cin >> T[i]>>D[i]>>L[i];
		used[i]=0;//需要提前清空 
	}
	dfs(0,0);
	if(have_answer){
		cout << "YES\n"; 
	}else cout << "NO\n";
}
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int T;cin>>T;
	while(T--) solve();
	return 0;
}
/*全排列 -》剪枝 */
