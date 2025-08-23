#include<iostream>
using namespace std;
const int MAXN = 1e5+5;
int a[MAXN],b[MAXN];
void merge(int s1,int e1,int s2,int e2) {//合并
	//左区间起点和终点，右区间起点和终点
	int pos = s1,st = s1;//初始化起点！！！
	while(s1<=e1&&s2<=e2) {
		if(a[s1]<=a[s2]) b[pos++] = a[s1++];//左区间右移
		else b[pos++] = a[s2++];//右区间右移
	}
	while(s1<=e1) b[pos++] = a[s1++];//剩余区间
	while(s2<=e2) b[pos++] = a[s2++];
	//赋值给原来的数组a
	for(int i = st;i <= e2;i++) a[i] = b[i];
}
void sortt(int l,int r) {
	if(l==r) return;//单个区间
	int mid = l + (r-l)/2;//取中间值
	sortt(l,mid);//先左
	sortt(mid+1,r);//后右
	merge(l,mid,mid+1,r);//再合并
}
int main() {
	int n;
	cin>>n;
	for(int i = 1;i <= n;i++) cin>>a[i];
	sortt(1,n);//归并排序
	for(int i = 1;i <= n;i++) cout<<a[i]<<" ";
	return 0;
}
