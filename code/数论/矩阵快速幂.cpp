#include<iostream>//矩阵快速幂
#define ll long long
using namespace std;
const int mod = 1007;

//  f[n] = f[n-1]+f[n-2]  n >= 3
//  f[n] = 1  			  1 <= n <= 2

/*
f[n]    = (1 1)(f[n-1])
f[n-1]  = (1 0)(f[n-2])
*/

struct Matrix{  //一个矩阵的结构体
	int f[2][2];
};
Matrix multi(Matrix a,Matrix b) {//矩阵乘法
	Matrix ans;//保存结果
	for(int i = 0;i < 2;i++) {
		for(int j = 0;j < 2;j++) {
			ans.f[i][j] = 0;
			for(int k = 0;k < 2;k++) {
				ans.f[i][j] += a.f[i][k]*b.f[k][j]%mod;
			}
			ans.f[i][j] %= mod;
		}
	}
	return ans;//返回一个Matrix结构体的数据
}
int main() {
	ll n;
	cin>>n;
	Matrix ans,tmp;
	tmp.f[0][0] = tmp.f[0][1] = tmp.f[1][0] = 1;
	tmp.f[1][1] = 0;//tmp为固定乘数
	ans.f[0][1] = ans.f[1][1] = 1;//ans保留结果
	ans.f[0][0] = ans.f[1][0] = 1;
	n -= 2;//从第三项才需要运算
	while(n>=1) {
		if(n&1) ans = multi(tmp,ans);//tmp为第一参数！！！
		tmp = multi(tmp,tmp);//快速幂
		n >>= 1;
	}
	cout<<(ans.f[0][0])%mod;//可根据公式推导
	return 0;
}
