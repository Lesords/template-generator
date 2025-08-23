#include<iostream>
#include<cstring>
#include<cstdio>
#include<string>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<algorithm>
#define ll long long
#define INF 0x3f3f3f3f
#define fi first
#define se second
using namespace std;
const int MAXN = 2e5+5;
struct node {
    int x,y;
};
vector<int> edge[MAXN],ord;//保存边和拓扑序列
vector<node> ans,both;//有向边和无向边
int in[MAXN],n,m,pos[MAXN];
bool toposort() {//拓扑排序
    queue<int> q;//保存0入度的点
    for(int i = 1;i <= n;i++) if(!in[i]) q.push(i);
    int tmp;
    while(!q.empty()) {
        tmp = q.front();q.pop();
        ord.push_back(tmp);//下标不能增加值
        for(int i = 0;i < edge[tmp].size();i++) {//所有指向点入度--
            int dot = edge[tmp][i];
            if(--in[dot]==0) q.push(dot);//入度为0的点放入队列
        }
    }
    return ord.size()==n;//为n说明无环
}
int main() {
    int _;
    cin>>_;
    while(_--) {
        cin>>n>>m;
        for(int i = 1;i <= n;i++) edge[i].clear();
        ans.clear(),both.clear(),ord.clear();
        memset(in,0,sizeof(in));//初始化！！！
        int t,x,y;
        for(int i = 1;i <= m;i++) {
            cin>>t>>x>>y;
            if(t) {//有向边
                edge[x].push_back(y);//x->y
                in[y]++;//入度
                ans.push_back(node{x,y});
            }
            else both.push_back(node{x,y});
        }
        if(toposort()) {
            cout<<"YES"<<endl;
            for(int i = 0;i < ans.size();i++) {//先输出有向边
                cout<<ans[i].x<<' '<<ans[i].y<<endl;
            }//ord从0开始
            for(int i = 0;i < n;i++) pos[ord[i]] = i;//保存对应点在拓扑序列中的位置
            for(int i = 0;i < both.size();i++) {
                int tx = both[i].x,ty = both[i].y;
                //位置小的->位置大的
                if(pos[tx]<pos[ty]) cout<<tx<<' '<<ty<<endl;
                else cout<<ty<<' '<<tx<<endl;
            }
        }
        else cout<<"NO\n";
    }
	return 0;
}
