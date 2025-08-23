#include<iostream>
using namespace std;
int num_div(int n) {
	int ans = 1;
	for(int i = 2;n!=1;i++) {
		int cnt = 1;
		while(n%i==0) {
			n /= i;
			cnt++;
		}
		ans *= cnt;
	}
	return ans;
}
int main() {
	int n;cin>>n;
	cout<<num_div(n)<<endl;
	return 0;
}
