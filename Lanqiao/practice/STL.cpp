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
    //��ʼ�� values ����Ϊ {0,1,2,3}
    for (int i = 0; i < values.size(); i++) {
        values[i] = i;
    }
    //ʹ�� get() ���غ������ָ��λ��Ԫ��
    cout << get<3>(values) << endl;
    cout << values[3] << endl;
    //���������Ϊ�գ���������������е�Ԫ��
    
	if (!values.empty()) {
        for (auto val = values.begin(); val < values.end(); val++) {//ʹ��ָ�� 
            cout << *val << " ";
        }
        cout << endl;
    }
    for(int i=0;i<values.size();i++){
    	cout << values[i];
    }
    
	return 0;
}
