#include<iostream>//ac
#include<string>
#include<algorithm>
using namespace std;
const int MAXN = 550;
int a[MAXN],b[MAXN],pos;
string s1,s2;
void bigadd() {//大数加法
	for(int i = 1;i < MAXN;i++) {
		a[i] += b[i];
		a[i+1] += a[i]/10;
		a[i] %= 10;
	}
}
int main() {
	cin>>s1>>s2;//输入字符串，然后转数组
	for(int i = s1.size()-1,j=1;i >= 0;j++,i--) a[j] = s1[i]-'0';
	for(int i = s2.size()-1,j=1;i >= 0;j++,i--) b[j] = s2[i]-'0';
	bigadd();
	for(int i = MAXN-1;i >= 1;i--) if(a[i]) {//找pos位置
		pos = i;break;
	}//至少输出一位（即0）
	for(int i = max(pos,1);i >= 1;i--) cout<<a[i];
	return 0;
}
