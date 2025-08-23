#include<iostream>//ac
#include<cstdio>
#include<cmath>
#include<string>
#include<queue>
#include<algorithm>
using namespace std;
const int MAXN = 2e5+5;
int a[MAXN],ll[MAXN],rr[MAXN],belong[MAXN],mark[MAXN];

void add(int l,int r) {//增加操作
	if(belong[l]==belong[r]) {
		for(int i = l;i <= r;i++) {
			a[i]++;
		}
	}
	else {
		for(int i = l;i <= rr[belong[l]];i++) a[i]++;
		for(int i = ll[belong[r]];i <= r;i++) a[i]++;
		for(int i = belong[l]+1;i < belong[r];i++) mark[i]++;
	}
}
int main() {
	int n,m,l,r,block,num;
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;

	//分块初始化
	block = sqrt(n);//块的长度
	num = n/block;//块的数量
	if(n%block) num++;
	for(int i = 1;i <= num;i++) {
		ll[i] = (i-1)*block+1;//第i个块的左右界
		rr[i] = i*block;
	}
	rr[num] = n;
	for(int i = 1;i <= n;i++) {
		belong[i] = (i-1)/block+1;
	}

	while(m--) {
		cin>>l>>r;
		add(l,r);//区间增加
	}
	for(int i = 1;i <= n;i++) {//单个查询
		a[i] += mark[belong[i]];
	}

	sort(a+1,a+n+1);
	long long ans = 0;
	for(int i = 1;i <= n;i++) ans += i*1LL*a[i];
	cout<<ans;
	return 0;
}
