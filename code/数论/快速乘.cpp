#include<iostream>
using namespace std;
//原理：x*y 等于y个x相加
int fast(int a,int b) {//快速乘
	int ans = 0;
	while(b) {
		if(b&1) ans += a;//b当前位为1时相加
		a *= 2;//a是倍数关系
		b >>= 1;
	}
	return ans;
}
int main() {
	int x,y;
	cin>>x>>y;
	cout<<fast(x,y);//x*y
	return 0;
}
