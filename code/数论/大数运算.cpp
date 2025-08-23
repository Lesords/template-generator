#include<iostream>
#include<string>
#include<cstring>
#define MAXN 2000
using namespace std;
void initial(string &a, string &b) {//初始化字符串 
    while(a.size()<b.size()) a='0'+a;
    while(b.size()<a.size()) b='0'+b;}
void del(string &a) {//删除字符串首部的'0' 
    if(a[0]=='0') a.erase(0,1);}
string bigadd(string a, string b) {//大数加法 
    initial(a, b);
    a='0'+a; b='0'+b;
    for(int i=a.size()-1;i>=0;i--) {
        int num1=a[i]-'0';
        int num2=b[i]-'0';
        if(num1+num2>9) {
            a[i-1]=a[i-1]+1;
            a[i]=(num1+num2)-10+'0';}
        else a[i]=(num1+num2)+'0';
    }
    while(a[0]=='0') del(a);
    return a;
}
void multiply(int a[], int z) {//阶乘 
    int c=0;
    for(int i=MAXN-1;i>=0;i--) {//MAXN-1保存的是个位数，从小到大开始计算 
        int x=a[i]*z+c;
        a[i]=x%10;
        c=x/10;}
}
int main() {
    int n,ans[MAXN];
    string a,b;
    while(cin>>a>>b) cout<<bigadd(a,b)<<endl;
    while(cin>>n) {
        memset(ans,0,sizeof(ans));
        ans[MAXN-1]=1;
        for(int i=2;i<=n;i++) multiply(ans,i);
        int num=0;
        for(int i=0;i<MAXN;i++) {
            if(ans[i]) {//找到非零项 
                num=i;break;}
        }
        for(int i=num;i<MAXN;i++) cout<<ans[i];//从非零项开始输出 
        cout<<endl;
    }
    return 0;
}
