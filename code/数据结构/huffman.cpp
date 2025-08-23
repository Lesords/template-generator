#include<iostream>
#include<queue>
using namespace std;
struct node {//结构体重载写法
	int x;
	friend bool operator < (node a,node b) {
		return a.x > b.x;//q.top()为小的靠前
	}
};
int main() {
	//priority_queue<node> q;//升序
	priority_queue<int, vector<int>, greater<int> > q; 
	int n,tmp,ans = 0;
	cin>>n;
	while(n--) {
		cin>>tmp;
		//q.push({tmp});
		q.push(tmp);
	}
	while(!q.empty()) {
		//node t1 = q.top();
		int t1 = q.top();
		q.pop();
		//node t2 = q.top();
		int t2 = q.top();
		q.pop();
		//ans += t1.x + t2.x;//取两个小的值相加
		ans += t1 + t2; 
		//if(q.size()) q.push({t1.x+t2.x});
		if(q.size()) q.push(t1 + t2);
		//若队列不为空，再把相加的值放入队列中
	}
	cout<<ans<<endl;
	return 0;
}
