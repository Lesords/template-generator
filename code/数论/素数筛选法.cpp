#include<iostream>
#include<cstring>
using namespace std;
const int MAXN = 1e6 + 5;
bool a[MAXN];
int main() {
	memset(a,false,sizeof(a));//falseÎªËØÊı
	for(int i = 2;i < MAXN;i++) {
		if(!a[i]) {
			for(int j = i + i;j < MAXN;j += i) a[j] = true;
		}
	}
	//for(int i = 2;i < 21;i++) if(!a[i]) cout<<i<<endl;
	return 0;
}
