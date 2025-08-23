#include<iostream>//ac
#include<vector>
#include<algorithm>
using namespace std;
const int MAXN = 2e5+5;
struct node{
    int x,y,z;
    friend bool operator < (node a,node b) {
        return a.z < b.z;//优先边权小的
    }
}a[MAXN];
int dis[MAXN];//并查集
int getf(int p) {//求祖先，路径压缩
    return dis[p]==p?p:dis[p]=getf(dis[p]);
}
int main() {
    int n,m;
    cin>>n>>m;
    for(int i = 1;i <= n;i++) dis[i] = i;
    for(int i = 1;i <= m;i++) {
        int x,y,z;
        cin>>x>>y>>z;
        a[i] = {x,y,z};//存边
    }
    sort(a+1,a+1+m);//按边权从小到大排序
    int ans = 0;
    for(int i = 1;i <= m;i++) {//在m个边里面选择
        node tmp = a[i];
        if(getf(tmp.x)!=getf(tmp.y)) {//若两个点还未连接
            ans += tmp.z;//添加边权值
            dis[getf(tmp.x)] = dis[getf(tmp.y)];//结合
        }
    }
    cout<<ans;
    return 0;
}
