#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
struct tree{
    int data;
    tree *lchild,*rchild; 
};
tree *buildtree() {
    tree *t;
    int ch;
    cin>>ch;
    if(ch==0) t=NULL;
    else {
        t=(tree *)malloc(sizeof(tree));
        t->data=ch;
        t->lchild=buildtree();
        t->rchild=buildtree();
    } 
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
void postorder(tree * t) {
    if(t==NULL) return ;
    else {
        postorder(t->lchild);
        postorder(t->rchild);
        cout<<t->data<<' ';
    }
}
int main() {
    tree *t;
    t=buildtree();
    cout<<"preorder:"<<endl;
    preorder(t); 
    cout<<endl<<"inorder:"<<endl;
    inorder(t);
    cout<<endl<<"postorder:"<<endl;
    postorder(t);
    return 0;
}
//2 1 0 0 4 3 0 0 0 
