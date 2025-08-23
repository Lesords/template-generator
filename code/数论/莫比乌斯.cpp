#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<sstream>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<utility>
#include<bitset>
#include<algorithm>
#define fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define ll long long
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define pii pair<int,int>
#define fi first
#define se second
#define eps 1e-6
using namespace std;
// const int MAXN = 2e5+5;
const int MOD = 1e9+7;
const double pi = acos(double(-1));

const int MAXN = 1000000;
bool check[MAXN+10];
int prime[MAXN+10], mu[MAXN+10];
void Moblus(){
	memset(check,false,sizeof(check));
	mu[1] = 1;
	int tot = 0;
	for(int i = 2; i <= MAXN; i++) {
		if(!check[i]) {
			prime[tot++] = i;
			mu[i] = -1;
		}
		for(int j = 0; j < tot; j++) {
			if(i * prime[j] > MAXN) break;
			check[i * prime[j]] = true;
			if( i % prime[j] == 0){
				mu[i * prime[j]] = 0;
				break;
			}
			else{
				mu[i * prime[j]] = -mu[i];
			}
		}
	}
}


int main() {
    int t;
    cin>>t;
    while(t--) {
    	
    }
    return 0;
}
