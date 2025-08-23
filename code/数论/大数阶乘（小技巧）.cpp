#include<cstdio>//ac
using namespace std;
const int MAXN = 36000;
int a[MAXN],pos;
void mult(int n) {
	int carry = 0;//进位
	for(int i = 1;i <= pos;i++) {//已知的位数
		a[i] = a[i]*n+carry;
		carry = a[i]/10;
		if(i==pos&&carry) pos++;//处理进位
		a[i] %= 10;
	}
	while(a[pos]>=10) {//位数多了
		a[pos+1] = a[pos]/10;
		a[pos] %= 10;
		++pos;//加位
	}
}
int main() {
	int n;//scanf和cin没差，memset也没差
	while(scanf("%d",&n)!=EOF) {
		pos = a[1] = 1;//初始化为1，位数只有1
		for(int i = 2;i <= n;i++)//阶乘
			mult(i);
		for(int i = pos;i >= 1;i--) printf("%d",a[i]),a[i]=0;
		printf("\n");
	}
	return 0;
}
