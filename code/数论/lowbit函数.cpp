#include<iostream>
using namespace std;

//lowbit(x)是x的二进制表达式中最低位1所对应的值

int lowbit(int x) {
	return x&(-x);
}
int lowbit2(int x) {
	return x&(x^(x-1));
}
int main() {
	int a;
	cin>>a;
	cout<<lowbit(a)<<endl;
	cout<<lowbit2(a)<<endl;
	return 0;
}
