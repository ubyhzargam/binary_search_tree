#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node *lchild;
    Node *rchild;
}*root=NULL;

void Insert(int key)
{
    struct Node *p;
    struct Node *r,*t=NULL;
    r=root;
    if(root==NULL)
    {
        p=new Node;
        p->data=key;
        p->rchild=p->lchild=NULL;
        root=p;
        return;
    }
        while(r!=NULL)
        {
            t=r;
            if(key==r->data)
                return;
            else if(key<r->data)
                r=r->lchild;
            else
                r=r->rchild;
        }
        p=new Node;
        p->data=key;
        p->lchild=p->rchild=NULL;
        if(key<t->data)
            t->lchild=p;
        else
            t->rchild=p;
    }

struct Node *RecursiveInsert(struct Node *n, int key)
{
    Node *t;
    t=NULL;
    if(n==NULL)
    {
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=key;
        t->lchild=t->rchild=NULL;
        return t;
    }
    else if(n->data<key)
        n->rchild=RecursiveInsert(n->rchild,key);
    else if(n->data>key)
        n->lchild=RecursiveInsert(n->lchild,key);
    return n;
}

void Inorder(struct Node *p)
{
    if(p)
    {
        Inorder(p->lchild);
        cout<<p->data<<" ";
        Inorder(p->rchild);
    }
}

int main()
{
    root=RecursiveInsert(root,10);
    RecursiveInsert(root,5);
    RecursiveInsert(root,20);
    RecursiveInsert(root,8);
    RecursiveInsert(root,30);
    Inorder(root);
    return 0;
}
