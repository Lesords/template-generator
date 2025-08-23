#include<iostream>
#include<algorithm>
using namespace std;
const int MAXV = 1e8;
const int MAXN = 6e6+6;//共5761455个质数
int prim[MAXN], v[MAXV+10], cnt;//prim记录质数，v为当前数的最小质因子
void get_prim() {
    for(int i = 2;i <= MAXV;i++) {
        if(v[i]==0) {
            prim[++cnt] = i;
            v[i] = i;                   //质数的质因子即为本身
        }
        for(int j = 1;j <= cnt;j++) {   //遍历所有质数
            //乘积不能超过范围，并且当前数的最小质因子不能小于当前质数
            //因为当前乘积是以 当前质数 为最小质因子来计算的！！！
            if(i*1ll*prim[j]>MAXV||v[i]<prim[j]) break;
            v[i*prim[j]] = prim[j];
        }
    }
}
int main() {
    get_prim();
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,q,tmp;
    cin>>n>>q;
    while(q--) {
        cin>>tmp;
        cout<<prim[tmp]<<"\n";
    }
    return 0;
}
