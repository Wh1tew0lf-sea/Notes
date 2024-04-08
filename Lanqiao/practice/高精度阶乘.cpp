#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <iostream>
using namespace std;

typedef struct {
	char data[1000];//一千位的高精（可自行拓展）
	int len;		//数字有多长
}HighAcc;

void dealNumber(HighAcc* h) {//output
	int start = 0, end = strlen(h->data) - 1;
	char tmp;

	h->len = end + 1;
	for (; start <= end; start++, end--) {
		tmp = h->data[start];
		h->data[start] = h->data[end] - '0';
		h->data[end] = tmp - '0';
	}
}

HighAcc add(HighAcc m_num1, HighAcc m_num2) {
	HighAcc sum = { 0 };
	int i, tmp;
	int maxlen = fmax(m_num1.len, m_num2.len);
	for (i = 0; i < maxlen; i++) {
		tmp = m_num1.data[i] + m_num2.data[i] + sum.data[i];
		sum.data[i] = tmp % 10;
		sum.data[i + 1] = tmp / 10;
	}
	sum.len = maxlen + sum.data[maxlen];
	return sum;
}
HighAcc mul(HighAcc m_num1, HighAcc m_num2) {
	HighAcc sum = { 0 };
	int i, j, tmp;

	//如果两者中有一个为0直接返回0
	if ((m_num1.len == 1 && m_num1.data[0] == 0) || (m_num2.len == 1 && m_num2.data[0] == 0)) {
		sum.len = 1;
		return sum;
	}

	//高精乘算法核心
	for (i = 0; i < m_num1.len; i++) {
		for (j = 0; j < m_num2.len; j++) {
			tmp = m_num1.data[i] * m_num2.data[j] + sum.data[i + j];
			sum.data[i + j] = tmp % 10;
			sum.data[i + j + 1] += tmp / 10;
		}
	}
	sum.len = m_num1.len + m_num2.len - !sum.data[m_num1.len + m_num2.len - 1];//得到sum 的长度
	return sum;
}

void printNumber(HighAcc h) {
	int i;
	for (i = h.len - 1; i >= 0; i--) {
		putchar(h.data[i] + '0');
	}
}

int n;
int main() {

	HighAcc num1 = { 0 };
	HighAcc num2 = { 0 };
	HighAcc sum = { 0 };
	HighAcc one = { 0 };
	int n;
	cin >> n;
	one.data[0] = '1';
	num1.data[0] = '1';
	num2.data[0] = '0';
	dealNumber(&num1);
	dealNumber(&num2);
	dealNumber(&sum);
	dealNumber(&one);

	for (int i = 0; i < n; i++) {
		num2 = add(one, num2);
		num1 = mul(num1, num2);
		sum = add(num1, sum);
	}


	printNumber(sum);
	putchar('\n');

	system("pause");
	return 0;

}
