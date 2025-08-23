#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 105;
int map[MAXN][MAXN],book[MAXN],dis[MAXN],n;
void dijkstra(int s) {
    for(int i = 1;i <= n;i++) {//初始化dis数组
        dis[i]=map[s][i];
    }
    memset(book, 0, sizeof(book));//初始化
    book[s] = 1;//标记
    for(int i = 1;i < n;i++) {
        int minn = INF,u;
        for(int j = 1;j <= n;j++) {
            if(!book[j] && dis[j]<minn) {//寻找最短路
                minn = dis[j];
                u = j;
            }
        }
        book[u] = 1;//标记该点
        for(int j = 1;j <= n;j++) {
            if(map[u][j]<INF)
                dis[j] = min(dis[j],dis[u]+map[u][j]);//更新
    	}
    }
}
int main() {
	int s,u,v,w,m;
	cin>>n>>m;
	for(int i = 1;i <= n;i++)//初始化
		for(int j = i;j <= n;j++)
		map[i][j] = map[j][i] = (i==j)?0:INF;
	for(int i = 1;i <= m;i++) {
		cin>>u>>v>>w;
		map[u][v] = map[v][u] = min(w, map[u][v]);
	}
	cin>>s;//起点
	dijkstra(s);
	for(int i = 1;i <= n;i++) {
		cout<<dis[i]<<' ';
	}
	cout<<endl;
	return 0;
}
