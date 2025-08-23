#include<iostream>//ac
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN = 1e5+5;
int a[MAXN],f[MAXN][20];
int n,m;
void RMQ_init() {
    for(int i = 1;i <= n;i++) f[i][0] = a[i];//边界
    int siz = log(n)/log(2);//siz只用于计算倍增规模！！！
    for(int i = 1;i <= siz;i++) {
        //j为起点， j+(1<<i)-1为终点
        //i大区间分成两个(i-1)小区间
        for(int j = 1;j+(1<<i)-1 <= n;j++) {
            int len = 1<<(i-1);//大区间分成两个小区间
            f[j][i] = max(f[j][i-1], f[j+len][i-1]);
        }
    }
}
int query(int l,int r) {// 求[l,r]区间最大值
    int siz = log(r-l+1)/log(2);
    return max(f[l][siz],f[r-(1<<siz)+1][siz]);
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i = 1;i <= n;i++) cin>>a[i];
    RMQ_init();
    while(m--) {
        int l,r;
        cin>>l>>r;
        cout<<query(l,r)<<"\n";
    }
    return 0;
}
