#include<iostream>//ac
#include<algorithm>
#define ll long long
using namespace std;
const int MAXN = 1e5+5;
struct node{
    ll l,r,sum,add;
}tree[MAXN<<2];
ll a[MAXN];
//建树
void build(int dot,int l,int r) {
    tree[dot].l = l,tree[dot].r = r;
    if(l==r) {
        tree[dot].sum = a[l];return;
    }
    int mid = (l+r)/2;
    build(dot<<1,l,mid);
    build(dot<<1|1,mid+1,r);
    tree[dot].sum = tree[dot<<1].sum+tree[dot<<1|1].sum;
}
//向下更新（lazy标记），lnum是左侧添加数量，rnum是右侧添加数量
void push_down(int dot,ll lnum,ll rnum) {
    if(tree[dot].add) {
        tree[dot<<1].add += tree[dot].add;
        tree[dot<<1|1].add += tree[dot].add;
        tree[dot<<1].sum += tree[dot].add*lnum;
        tree[dot<<1|1].sum += tree[dot].add*rnum;
        tree[dot].add = 0;
    }
}
//区间修改，[l,r]是修改区间（不变），val是增加的值
void update(int dot,int l,int r,ll val) {
    if(l<=tree[dot].l&&tree[dot].r<=r) {
        tree[dot].sum += (tree[dot].r-tree[dot].l+1)*val;
        tree[dot].add += val;
        return ;
    }
    int mid = (tree[dot].l+tree[dot].r)/2;
    push_down(dot,mid-tree[dot].l+1,tree[dot].r-mid);
    if(mid>=l) update(dot<<1,l,r,val);
    if(mid<r) update(dot<<1|1,l,r,val);
    tree[dot].sum = tree[dot<<1].sum+tree[dot<<1|1].sum;
};
//区间查询，[l,r]是查询区间（不变）
ll query(int dot,int l,int r) {
    if(l<=tree[dot].l&&tree[dot].r<=r) {
        return tree[dot].sum;
    }
    int mid = (tree[dot].l+tree[dot].r)/2;
    push_down(dot,mid-tree[dot].l+1,tree[dot].r-mid);
    ll ans = 0;
    if(mid>=l) ans += query(dot<<1,l,r);
    if(mid<r) ans += query(dot<<1|1,l,r);
    return ans;
}
int main() {
    int n,m;
    cin>>n>>m;
    for(int i = 1;i <= n;i++) cin>>a[i];
    build(1,1,n);
    while(m--) {
        ll op,x,y,k;
        cin>>op>>x>>y;
        if(op==1) {
            cin>>k;
            update(1,x,y,k);
        }
        else cout<<query(1,x,y)<<endl;
    }
    return 0;
}
