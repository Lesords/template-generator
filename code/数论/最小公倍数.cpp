#include<iostream>
#include<cstring>
using namespace std;
int gcd(int a, int b) {//最大公约数
	return a%b==0?b:gcd(b,a%b);
}
int lcm(int a,int b) {//最小公倍数
	return a*b/gcd(a,b);
}
int main() {
	int n, m;
	while(cin>>n>>m) {
		cout<<lcm(n,m)<<endl;
	}
	return 0;
} 
