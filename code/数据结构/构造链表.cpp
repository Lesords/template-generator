#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;
struct node {
	int data;
	node *next; 
};
int main() {
	node *q,*p,*head,*t;
	head=NULL;
	int n,m;
	cin>>n;
	while(n--) {
		cin>>m;
		p=(node *)malloc(sizeof(node));
		p->data=m;
		p->next=NULL;
		if(head==NULL) {
			head=p;
		}
		else {
			q->next=p;
		}
		q=p;
	}
	t=head;
	while(t!=NULL) {
		cout<<t->data<<endl;
		t=t->next;
	}
	return 0;
} 
