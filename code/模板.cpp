#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<bitset>
#include<cstdlib>
#include<cmath>
#include<set>
#include<list>
#include<deque>
#include<map>
#include<queue>
#define INF 0x3f3f3f3f
//#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const double PI = acos(-1.0);//π的值 
const double eps = 1e-6;//0.000001
const int INF = 1000000000;
const int maxn = 100;
int T,n,m;

inline char gch()
{
    static char buf[100010], *h = buf, *t = buf;
    return h == t && (t = (h = buf) + fread(buf, 1, 100000, stdin), h == t) ? EOF : *h ++;
}

template<class T>
inline void re(T &x)
{
    x = 0;
    char a; bool b = 0;
    while(!isdigit(a = gch()))
        b = a == '-';
    while(isdigit(a))
        x = (x << 1) + (x << 3) + a - '0', a = gch();
    if(b == 1)
        x *= -1;
}

int main()
{
	ios::sync_with_stdio(false);//加速输入 
    // int a; re(a);
	/*scanf("%d",&T);
	while(T--) {
		
	}*/
	printf("%f",eps);
	return 0;
}
