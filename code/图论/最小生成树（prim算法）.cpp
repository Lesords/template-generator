#include<stdio.h>
#define min(x,y) ((x<y)?x:y)
int n,map[105][105];
void prim(int u) {
	int sum_mst=0,lowc[105],mst[105];
	for(int i=1;i<=n;i++) {//第一次初始化lowc数组 
		lowc[i]=map[u][i];
		mst[i]=u;//集合数值统一设为起始点 
	}
	mst[u]=-1;//-1表示该点已经连接 
	for(int i=1;i<n;i++) {
		int v=-1,minn=999999;//v表示点，minn表示边 
		for(int j=1;j<=n;j++) {
			if(mst[j]!=-1&&minn>lowc[j]) {
				minn=lowc[j];//取得最小边 
				v=j;//取得相应的点 
			} 
		}
		if(v!=-1) {
			printf("%d %d %d\n",mst[v],v,lowc[v]);//输出起点 末点 路径大小 
			mst[v]=-1;//v点已连接 
			sum_mst+=lowc[v];
			for(int j=1;j<=n;j++) {//再次优化lowc数组 
				if(mst[j]!=-1&&lowc[j]>map[v][j]) {
					lowc[j]=map[v][j];
					mst[j]=v;//集合数值统一设为起始点
				}
			}
		}
	}
	printf("%d\n",sum_mst);
	return ;
}
int main() {
	int m,u,v,w;
	scanf("%d%d",&n,&m);//n为点的数量,m为路径数 
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=n;j++)
			map[i][j]=map[j][i]=(i==j)?0:999999;//初始化数组 
	}
	for(int i=1;i<=m;i++) {
		scanf("%d%d%d",&u,&v,&w);
		map[u][v]=map[v][u]=min(w,map[u][v]);//储存路径 
	}
	prim(1);
	return 0;
} 
