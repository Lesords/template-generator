#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
typedef pair<int,int> PII;
const int MAX = 0x3f3f3f3f, M = 4000010, N = 2010;

//edge e[M];
//1.由于N平方接近于M所以为稠密图
//2.最小生成树 稀疏图使用Kruskal(对边)、Prim（对点） 稠密图使用 堆优化Prim
//3.稠密图使用邻接矩阵，稀疏图使用邻接表（存边）
//4.当自己可以给自己买票时，所有与自己有间接关系的边均视为存在

int n,m,sum;
int e[N][N],dis[N];
bool book[N];
priority_queue<PII,vector<PII>,greater<PII>> que;

//inline char gch()
//{
//    static char buf[100010], *h = buf, *t = buf;
//    return h == t && (t = (h = buf) + fread(buf, 1, 100000, stdin), h == t) ? EOF : *h ++;
//}
//template<class T>
//inline void re(T &x)
//{
//    x = 0;
//    char a; bool b = 0;
//    while(!isdigit(a = gch()))
//        b = a == '-';
//    while(isdigit(a))
//        x = (x << 1) + (x << 3) + a - '0', a = gch();
//    if(b == 1)
//        x *= -1;
//}

//inline int re(int& ret) {
//    ret=0;
//    int f=1;char ch=getchar();
//    while (ch<'0'||ch>'9') {if (ch=='-') f=-f;ch=getchar();}
//    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
//    ret*=f;
//}

template<class T>
inline bool re(T &ret) {
    char c;
    int sgn;
    if(c=getchar(),c==EOF) return 0;
    while(c!='-'&&(c<'0'||c>'9')) c = getchar();
    sgn = (c=='-')?-1:1;
    ret = (c=='-')?0:(c-'0');
    while(c=getchar(),c>='0'&&c<='9') ret = ret*10+(c-'0');
    ret *= sgn;
    return 1;
}

int main(){
	freopen("tickets.in","r",stdin);
	freopen("tickets.out","w",stdout);
	re(n), re(m);
	memset(dis,0x3f,sizeof(dis));
	int minn = MAX;
	int p = -1;
	for(int i = 1; i <= m; i++){
		int u,v,w;
		re(u), re(v), re(w);
		if(e[u][v] > w){
			e[u][v] = e[v][u] = w;
			if(u == v){//具有自购能力
				if(minn > w){//获得最少时间自购的点
					minn = w;
					p = u;
				}
				//具有自购能力的都可以自成一棵树（只是类似树，因为树不具有自环）
				dis[u] = w;
			}
		}
	}

	//Prim 从最少时间自购的点开始构造最小生成树
	int count = 0;
	book[p] = true;
	sum += e[p][p];
	que.push(make_pair(e[p][p],p));
	//松弛
	for(int i = 1; i <= n; i++){
		dis[i] = min(dis[i],e[i][p]);
		que.push(make_pair(dis[i],i));
	}
	count++;

	while(count<n) {
		int num = que.top().second;
		que.pop();
		if(book[num]) continue;
		book[num] = true;
		sum += dis[num];
		count++;
		for(int i = 1; i <= n; i++) {
			if(!book[i] && dis[i] > e[num][i]){
				dis[i] = e[num][i];
				que.push(make_pair(dis[i],i));
			}
		}
	}

	cout<<sum;
	return 0;
}
