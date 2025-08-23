#include<iostream>
#define ll long long
using namespace std;
const int MAXN = 1e5 + 5;
ll m,sum[MAXN<<2];//MAXN<<2 等于 MAXN*4
void add_op(int t,int v,int l,int r,int rt) {
	if(l==r) {//不可分节点
		sum[rt] = v;
		return ;
	}
	int mid = (l+r)>>1;
	//(l+r)>>1 等于  (l+r)/2
	//rt<<1 等于 rt*2
	//rt<<1|1 等于 rt*2+1
	if(t<=mid) add_op(t,v,l,mid,rt<<1);//左半区间
	else add_op(t,v,mid+1,r,rt<<1|1);//右半区间
	sum[rt] = sum[rt<<1] * sum[rt<<1|1] % m;//更新
}
int main() {
	int T,n;
	ios::sync_with_stdio(false);//加速
	cin>>T;
	while(T--) {
		cin>>n>>m; 
		for(int i=1;i<=n<<2;i++) sum[i] = 1;//初始化为1
		char op;
		int tmp;
		for(int i=1;i<=n;i++) {
			cin>>op>>tmp;
			if(op=='M') add_op(i,tmp,1,n,1);//节点i的值改为tmp
			else add_op(tmp,1,1,n,1);//节点tmp的值改为1
			cout<<sum[1]<<endl;//输出根节点的值
		}
	}
	return 0;
}
