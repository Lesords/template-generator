#include<iostream>
#include<cstdio>
using namespace std;
int poww(int a,int b) {//a的b次方
	int ans = 1,base = a;//ans为结果，base为过程量 
	while(b) {
		if(b&1) ans *= base;
		base *= base;//二进制每次乘都要翻倍 
		b >>= 1;
	}
	return ans;   
}
int main() {
	int a,b;
	cin>>a>>b;//a为底数，b为次数 
	cout<<poww(a,b)<<endl;
	return 0;
}
