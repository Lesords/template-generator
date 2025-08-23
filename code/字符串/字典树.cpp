#include<iostream>
#include<cstring>
#include<bitset>
#include<algorithm>
using namespace std;

//字典树，插入字符串的时候，会标记最后一个节点
//所以我们操作的时候可以直接对末节点操作

struct Trie {
    static const int SIZE = 2e5+5;
    int nex[SIZE][26], cnt;
//    bool exist[SIZE];  // 该结点结尾的字符串是否存在
    void init() {
        cnt = 0;//0为根节点，无对应值
        memset(nex, 0, sizeof(nex));
//        memset(exist, 0, sizeof(exist));
    }
    int insert(char *s, int l) {  // 插入字符串
        int p = 0;
        for (int i = 0; i < l; i++) {
            int c = s[i] - 'a';
            if (!nex[p][c]) nex[p][c] = ++cnt;  // 如果没有，就添加结点
            p = nex[p][c];
        }
//        exist[p] = 1;
        return p;
    }
    int find(char *s, int l) {  // 查找字符串
        int p = 0;
        for (int i = 0; i < l; i++) {
            int c = s[i] - 'a';
            if (!nex[p][c]) return 0;
            p = nex[p][c];
        }
        return p;
//        return exist[p];//用bool类型时使用
    }
}t;

const int MAX = 5e6+5;
char s[33];
bitset<1001> b[MAX];//记录对应节点是否在对应行出现过
int main() {
    t.init();
    int n,m;
    cin>>n;
    for(int i = 1;i <= n;i++) {
        int tmp;
        cin>>tmp;
        while(tmp--) {
            cin>>s;
            int len = strlen(s);
            b[t.insert(s, len)][i] = 1;//插入一个字符串之后，对末节点进行操作
        }
    }
    cin>>m;
    while(m--) {
        cin>>s;
        int len = strlen(s);
        int pos = t.find(s, len);//s字符串的末节点
        //0表示不存在
        if(pos) for(int i = 1;i <= n;i++) {
            if(b[pos][i]==1) {
                cout<<i<<" ";
            }
        }
        cout<<"\n";
    }
    return 0;
}
