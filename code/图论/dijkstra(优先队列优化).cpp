#include<iostream>
#include<cstring>
#include<queue>
#include<vector>
#include<algorithm>
#define ll long long
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
const int MAXN = 1e5+5;
struct edge {
    ll dot,val;
    friend bool operator < (edge a,edge b) {
        return a.val > b.val;//先小
    }
};
ll n,m,s,vis[MAXN],dis[MAXN];//vis判断当前是否已经确定，dis为长度
vector<edge> g[MAXN];//存图
void dijkstra(int dot) {
    for(int i = 1;i <= n;i++) dis[i] = INF;         //初始化
    dis[dot] = 0;                                   //源点为0
    priority_queue<edge> q;                         //优先队列
    q.push(edge{dot,0});                            //源点入队列
    while(!q.empty()) {
        edge tmp = q.top();q.pop();
        if(vis[tmp.dot]) continue;                  //跳过已确定的
        else vis[tmp.dot] = 1;                      //否则标记
        for(int i = 0;i < g[tmp.dot].size();i++) {  //遍历所有可到达点
            edge now = g[tmp.dot][i];
            if(dis[now.dot]>dis[tmp.dot]+now.val) { //松弛操作
                dis[now.dot] = dis[tmp.dot]+now.val;
                //未访问，则继续入队
                if(!vis[now.dot]) q.push(edge{now.dot,dis[now.dot]});
            }
        }
    }
}
int main() {
    cin>>n>>m>>s;
    for(int i = 1;i <= m;i++) {
        ll u,v,w;
        cin>>u>>v>>w;
        g[u].push_back(edge{v,w});                  //建图
    }
    dijkstra(s);                                    //跑dijkstra
    for(int i = 1;i <= n;i++) {
        if(i!=1) cout<<" ";
        cout<<dis[i];
    }
    return 0;
}
