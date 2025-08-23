#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 11e6 + 5;
char s[MAXN], ma[MAXN*2];
int mp[MAXN*2];//mp[i] 为在s中以对应位置为中心的极大子回文串的总长度+1
int Manacher(char *s, int siz){//siz为字符串长度
    int len = 0;
    ma[len++] = '$'; ma[len++] = '#';
    for(int i = 0;i < siz;i++){
        ma[len++] = s[i];
        ma[len++] = '#';
    }
    ma[len] = 0;//末尾为空字符
    int mx = 0, id = 0;//id为局部最大回文串中心点，mx为右边界
    int res = 0;
    for(int i = 0;i < len;i++) {
        //由于对于i的对称点j（j小）来说：id - j = i - id 推出 j = 2id-i
        mp[i] = mx > i ? min(mp[2*id-i], mx - i) : 1;
        while(ma[i+mp[i]] == ma[i-mp[i]]) mp[i]++;//暴力枚举
        if(i + mp[i] > mx) {//更新局部最大回文串
            mx = mp[i] + i;
            id = i;
        }
        res = max(res, mp[i] - 1);
        //mp[i]为左部分大小，但是包括了#的数量，而且#数量比原字符串多，所以需-1
    }
    return res;
}

//例如：
/* abbaaba
   i:     0 1 2 3 4 5 6 7 8 9 10 11 12 13
   Ma[i]: $ # a # b # a # a # b  #  a  #
   Mp[i]: 1 1 2 1 4 1 2 7 2 1 4  1  2  1
 */

int main() {
    cin>>s;
    int len = strlen(s);
    cout<<Manacher(s, len);
    return 0;
}
