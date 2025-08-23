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
const int MAXN = 2e5+5;
const int MOD = 1e9+7;
const double pi = acos(double(-1));

struct BigInt {
	const static int mod = 10000;
	const static int DLEN = 4;
	const static int MAX = 700;
	int a[MAX], len;
	BigInt() {
		memset(a, 0, sizeof(a));
		len = 1;
	}
	BigInt(int v) {
		memset(a, 0, sizeof(a));
		len = 0;
		do {
			a[len++] = v%mod;
			v /= mod;
		}while(v);
	}
	BigInt(const char s[]) {
		memset(a, 0, sizeof(a));
		int L = strlen(s);
		len = L/DLEN;
		if(L%DLEN) len++;
		int index = 0;
		for(int i = L-1;i >= 0;i -= DLEN) {
			int t = 0;
			int k = i - DLEN + 1;
			if(k < 0) k = 0;
			for(int j = k;j <= i;j++) 
				t = t*10 + s[j] - '0';
			a[index++] = t;
		}
	}
	BigInt operator + (const BigInt &b) const {
		BigInt res;
		res.len = max(len, b.len);
		for(int i = 0;i <= res.len;i++) 
			res.a[i] = 0;
		for(int i = 0;i <res.len;i++) {
			res.a[i] += ((i < len)?a[i]:0)+((i < b.len)?b.a[i]:0);
			res.a[i+1] += res.a[i]/mod;
			res.a[i] %= mod;
		}
		if(res.a[res.len] > 0) res.len++;
		return res;
	}
	BigInt operator *(const BigInt &b) const {
		BigInt res;
		for(int i = 0;i < len;i++) {
			int up = 0;
			for(int j = 0;j < b.len;j++) {
				int temp = a[i]*b.a[j] + res.a[i+j] + up;
				res.a[i+j] = temp%mod;
				up = temp/mod;
			}
			if(up != 0) 
				res.a[i + b.len] = up;
		}
		res.len = len + b.len;
		while(res.a[res.len - 1] == 0 && res.len > 1) res.len--;
		return res;
	}
	void output() {
		printf("%d", a[len-1]);
		for(int i = len-2;i >= 0;i--) 
			printf("%04d", a[i]);
		printf("\n");
	}
};


int main() {
	fast;
	char a[3006], b[3006];
	cin>>a>>b;
	BigInt A(a), B(b);
	// A = A+B;
	A = A*B;
	A.output();
    return 0;
}
