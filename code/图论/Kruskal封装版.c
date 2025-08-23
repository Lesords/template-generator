#include<iostream>//不推荐
#include<vector>
#include<algorithm>
using namespace std;
struct Kruskal{
    int n,m;
    struct node{
        int x,y,z;
        friend bool operator < (node a,node b) {
            return a.z < b.z;
        }
    }a[200005];//爆本地栈
    int dis[5005];
    Kruskal(int n,int m){
        this->n = n;
        this->m = m;
        for(int i = 1;i <= n;i++) this->dis[i] = i;
    }
    int getf(int p) {
        return (this->dis[p])==p?p:(this->dis[p]) = getf(this->dis[p]);
    }
    int cal() {
        int ans = 0;
        sort(this->a+1,this->a+1+this->m);
        for(int i = 1;i <= this->m;i++) {
            node tmp = this->a[i];
            if(this->getf(tmp.x)!=this->getf(tmp.y)) {
                ans += tmp.z;
                this->dis[this->getf(tmp.x)] = this->dis[this->getf(tmp.y)];
            }
        }
        return ans;
    }
};
int main() {
    int n,m;
    cin>>n>>m;
    Kruskal k(n,m);
    for(int i = 1;i <= m;i++) {
        int x,y,z;
        cin>>x>>y>>z;
        k.a[i] = {x,y,z};
    }
    cout<<k.cal();
    return 0;
}
