#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
struct tree{
    int data;
    tree *lchild,*rchild;
};
tree *insert(tree *t,int m) {
    if(t==NULL) {
        t=(tree *)malloc(sizeof(tree));
        t->data=m;
        t->lchild=t->rchild=NULL;
    }
    else {        
        if(m<t->data) {
            t->lchild=insert(t->lchild,m);
        }
        else {
            t->rchild=insert(t->rchild,m);
        }
    }
    return t;
}
void preorder(tree *t) {
    if(t==NULL) return ;
    else {
        cout<<t->data<<' ';
        preorder(t->lchild);
        preorder(t->rchild);
    }
}
void inorder(tree *t) {
    if(t==NULL) return ;
    else {
        inorder(t->lchild);
        cout<<t->data<<' ';
        inorder(t->rchild);
    }
}
void postorder(tree *t) {
    if(t==NULL) return ;
    else {
        postorder(t->lchild);
        postorder(t->rchild);
        cout<<t->data<<' ';
    }
}
int main() {
    int n,m,k;
    tree *head;
    cin>>n;
    head=NULL;
    for(int i=1;i<=n;i++) {
        cin>>m;
        head=insert(head,m);
    }
    cout<<"preorder:"<<endl;
    preorder(head);
    cout<<endl<<"inorder:"<<endl;
    inorder(head);
    cout<<endl<<"postorder:"<<endl;
    postorder(head);
    return 0;
}
//4 2 1 4 3
