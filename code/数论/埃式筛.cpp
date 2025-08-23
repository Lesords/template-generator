#include<iostream>
#include<algorithm>
using namespace std;
const int MAXV = 1e6;
const int MAXN = 8e4+8;//共78498个质数
int prim[MAXN], v[MAXV+10], cnt;
void get_prim() {
    for(int i = 2;i <= MAXV;i++) {
        if(v[i]) continue;              //跳过已标记的
        prim[++cnt] = i;                //记录当前素数
        for(int j = i+i;j <= MAXV;j+=i) {
            v[j] = 1;                   //标记合数为1
        }
    }
}
int main() {
    get_prim();
    int n,pos = 0,sum = 0;
    cin>>n;
    while(sum+prim[pos+1]<=n) {
        cout<<prim[++pos]<<"\n";
        sum += prim[pos];
    }
    cout<<pos<<"\n";
    return 0;
}
