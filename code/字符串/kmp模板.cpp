#include<iostream>
#include<cstring>
using namespace std;

const int MAXN = 1e6+6;
int len_n,len_m,nextt[MAXN];//需要提前计算n和m的值
//nextt数组记录的是：当前位置结尾的非前缀子串等于原字符串前缀的大小
char n[MAXN],m[MAXN];//n为长串，m为短串
void get_nextt() {//自身匹配
	int i = 0,j = -1;
	nextt[i] = j;
	while(i<len_m) {//目标串长度
		if(m[i] == m[j]||j == -1) nextt[++i] = ++j;
		else j = nextt[j];//自身回退
	}
}
bool kmp() {
	int i = 0, j = 0;
	get_nextt();
	while(i<len_n&&j<len_m) {
		if(n[i]==m[j]||j==-1) i++,j++;//匹配成功都会后移！！！
		else j = nextt[j];//回退
	}
	if(j == len_m) return true;//len_m表示匹配成功
	return false;
}

int main() {
	while(cin>>n>>m) {
		len_n = strlen(n);
		len_m = strlen(m);
		if(kmp()) cout<<"匹配成功！"<<endl;
		else cout<<"匹配失败！"<<endl;
	}
	return 0;
}
