#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
const int MAXN = 1e5+5;
struct edge{
    ll dot,val;//dot为指向点，val为边值
};
ll n,m,s,dis[MAXN];         //dis保存距离
bool vis[MAXN];             //判断是否在队列中（true为可入队）
vector<edge> g[MAXN];       //存图
void spfa(int dot) {
    for(int i = 1;i <= n;++i) dis[i] = INF,vis[i] = true;//初始化
    queue<int> q;
    q.push(dot);                                //初始化入队源点
    dis[dot] = 0;                               //源点的距离为0
    vis[dot] = false;                           //不可入队
    while(!q.empty()) {                         //若队列不为空
        int tmp = q.front();q.pop();
        vis[tmp] = true;                        //出入之后修改vis
        for(int i = 0;i < g[tmp].size();++i) {
            edge now = g[tmp][i];               //指向点及边值
            if(dis[now.dot]>dis[tmp]+now.val) { //可松弛
                dis[now.dot] = dis[tmp] + now.val;//取小值
                if(vis[now.dot]) {              //判断是否可以入队
                    q.push(now.dot);
                    vis[now.dot] = false;       //更新vis
                }
            }
        }
    }
}
int main() {
    cin>>n>>m>>s;
    for(int i = 1;i <= m;i++) {
        int u,v,w;
        cin>>u>>v>>w;
        g[u].push_back(edge{v,w});          //建图
    }
    spfa(s);                                //从s点开始spfa
    for(int i = 1;i <= n;i++) {
        if(i!=1) cout<<" ";
        if(dis[i]==INF) cout<<(1<<31)-1;    //不可到的特殊答案
        else cout<<dis[i];
    }
    cout<<"\n";
    return 0;
}
