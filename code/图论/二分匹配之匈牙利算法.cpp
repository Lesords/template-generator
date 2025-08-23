#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
const int MAXN = 505;
int k,m,n;
int vis[MAXN],match[MAXN];                          //vis标记当前对象是否判断过
//match保存当前对象匹配的值（保存起点值）
vector<int> g[MAXN];                                //存图
int dfs(int u) {//起始点
    for(int i = 0;i < g[u].size();i++) {            //遍历所有指向边找匹配
        int now = g[u][i];                          //指向点
        if(vis[now]) continue;                      //跳过已判断的
        vis[now] = 1;                               //标记
        if(match[now]==0||dfs(match[now])) {        //还未匹配，或已匹配的有新的匹配对象
            match[now] = u;                         //保存匹配的值（u->now）
            return 1;
        }
    }
    return 0;//没找到，则说明不存在此增广路（匹配）
}
int hungarian() {//计算二分匹配的最大数量
    int ans = 0;
    for(int i = 1;i <= m;i++) {                     //遍历起始点集合的所有元素
        for(int j = 1;j <= n;j++) vis[j] = 0;       //标记清零
        if(dfs(i)) ans++;                           //若有找到一个匹配则增加
    }
    return ans;
}

int main() {
    while(cin>>k&&k) {
        memset(match,0,sizeof(match));              //初始化
        cin>>m>>n;
        for(int i = 1;i <= m;i++) g[i].clear();     //初始化
        for(int i = 1;i <= k;i++) {
            int x,y;
            cin>>x>>y;
            g[x].push_back(y);                      //存图
        }
        //封装后，直接调用
        cout<<hungarian()<<"\n";
    }
    return 0;
}
