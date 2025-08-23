#include<iostream>//ac
#include<cstdio>//HDU 1215
using namespace std;
int f(int n) {
	int ans = 1;
	for(int i = 2;n != 1;i++) {
		if(n%i==0) {
			int tmp = 1,sum = 1;
			while(n%i==0) {
				tmp *= i;
				sum += tmp;
				n /= i;
			}
			ans *= sum;
		}
	}
	return ans;
}
int main() {
	int t,tmp;
	scanf("%d",&t);
	while(t--) {
		scanf("%d",&tmp);
		printf("%d\n",f(tmp) - tmp);
	}
	return 0;
} 
