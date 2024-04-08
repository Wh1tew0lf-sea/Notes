#include <bits/stdc++.h>

using namespace std;
//上下取整 
const int MAX_N=1e4+1;
int N,A[MAX_N],B[MAX_N];
bool check_min(int V){
	for(int i=1;i<=N;i++){
		if(A[i]/V>B[i])return false;
	}
	return true;
}
bool check_max(int V){
	for(int i=1;i<=N;i++){
		if(A[i]/V<B[i])return false;
	}
	return true;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0); 
	cin >>N;
	for(int i=1;i<=N;++i) cin>>A[i]>>B[i];
	int L =1,R=1000000000,V_min;
	while(L<=R){
		int mid=L+R>>1;
		
		if(check_min(mid)){
			V_min=mid;
			R=mid-1;
		}else L=mid+1;
	} 
	L =1,R=1000000000;int V_max;
	while(L<=R){
		int mid=L+R>>1;
		
		if(check_max(mid)){
			V_max = mid;
			L=mid+1;
		}else R = mid-1;
	}
	cout << V_min << ' ' << V_max;
	return 0;
}

/*小蓝有一个神奇的炉子用于将普通金属 O 冶炼成为一种特殊金属 X。这个炉子有一个称作转换率的属性V
,V是一个正整数，这意味着消耗 V个普通金属 O 恰好可以冶炼出一个特殊金属 X，当普通金属 O 的数目不足 
V 时，无法继续冶炼。
现在给出了 N 条冶炼记录，每条记录中包含两个整数 A 和 B，这表示本次投入了 A 个普通金属 O，最终冶炼出了 
B 个特殊金属 X。每条记录都是独立的，这意味着上一次没消耗完的普通金属 O 不会累加到下一次的冶炼当中。
根据这 N 条冶炼记录，请你推测出转换率 V 的最小值和最大值分别可能是多少，题目保证评测数据不存在无解的情况。

输入格式
第一行一个整数N，表示冶炼记录的数目。
接下来输入 N 行，每行两个整数 
A,B，含义如题目所述。

输出格式
输出两个整数，分别表示 
V 可能的最小值和最大值，中间用空格分开。

输入输出样例
输入 #1复制
3
75 3
53 2
59 2
输出 #1复制
20 25
说明/提示

蓝桥杯 2023 省赛 B 组 C 题。*/
