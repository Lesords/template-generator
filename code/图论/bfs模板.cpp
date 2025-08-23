#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring> 
#include<cstdlib>
using namespace std;
int book[105][105],n,m;
char a[105][105];//根据题目数据定类型
struct node {
	int x,y,step;
};
void bfs(int x,int y,int step) {
	queue<node> q;//定义队列
	q.push({x,y,step});//初始点（可以不加node）
	int next[4][2]={1,0,0,1,-1,0,0,-1};//四个方向
	while(!q.empty()) {
		node t = q.front();
		q.pop();
		if(t.x==n&&t.y==m) {
			cout<<t.step<<endl;
			return ;
		} 
		for(int i=0;i<4;i++) {
			int tx=t.x+next[i][0];
			int ty=t.y+next[i][1];
			if(tx<1||tx>n||ty<1||ty>m) continue;//越界
			if(a[tx][ty]=='1') continue;//墙
			if(book[tx][ty]) continue;//已走过
			book[tx][ty]=1;//标记路径
			q.push({tx,ty,t.step+1});//可以不加结构体名
		}
	}
}
int main() {
	while(cin>>n>>m) {//n行m列
		memset(book,0,sizeof(book));
		for(int i=1;i<=n;i++) 
			for(int j=1;j<=m;j++)
				cin>>a[i][j];//字符很关键
		bfs(1,1,0);//默认1,1为起点,步数为1
	}
	return 0;
} 
