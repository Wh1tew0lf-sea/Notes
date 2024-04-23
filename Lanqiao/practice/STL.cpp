#include <bits/stdc++.h>
using namespace std;

int main(){
	vector<int>a;
	a.push_back(0);
	a.push_back(2);
	a.push_back(9);
	a.push_back(1);
	cout << a[0] << a[1] <<endl;
	cout << a.back() << a.front() << a.size()<<endl;
	a.pop_back();
	cout << a.back()<<endl;
	auto t = a.begin();
	cout << *t << endl;
	
	array<int,4>values;
    //初始化 values 容器为 {0,1,2,3}
    for (int i = 0; i < values.size(); i++) {
        values[i] = i;
    }
    //使用 get() 重载函数输出指定位置元素
    cout << get<3>(values) << endl;
    cout << values[3] << endl;
    //如果容器不为空，则输出容器中所有的元素
    
	if (!values.empty()) {
        for (auto val = values.begin(); val < values.end(); val++) {//使用指针 
            cout << *val << " ";
        }
        cout << endl;
    }
    for(int i=0;i<values.size();i++){
    	cout << values[i];
    }
    
	return 0;
}
