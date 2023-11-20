#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node *lchild;
    Node *rchild;
}*root=NULL;

struct Node *Search(int key)
{
    struct Node *t;
    t=root;
    while(t!=NULL)
    {
        if(key==t->data)
            return t;
        else if(key<t->data)
            t=t->lchild;
        else
            t=t->rchild;
    }
    return NULL;
}

struct Node *RecursiveSearch(Node *t,int key)
{
    if(t==NULL)
        return NULL;
    else if(key==t->data)
        return t;
    else if(key<t->data)
        return RecursiveSearch(t->lchild,key);
    else
        return RecursiveSearch(t->rchild,key);
}

int Height(struct Node *p)
{
    if(p==NULL)
        return 0;
    int x,y;
    x=Height(p->lchild);
    y=Height(p->rchild);
    return x>y?x+1:y+1;
}

struct Node *Inpre(struct Node *p)
{
    while(p!=NULL&&p->rchild!=NULL)
        p=p->rchild;
    return p;
}

struct Node *InSucc(struct Node *p)
{
    while(p!=NULL&&p->lchild!=NULL)
        p=p->lchild;
    return p;
}

struct Node *Delete(struct Node *p, int key)
{
    struct Node *q;
    if(p==NULL)
        return NULL;
    if(p->lchild==NULL&&p->rchild==NULL&&p->data==key)
    {
        if(p==root)
            root=NULL;
        free(p);
        return NULL;
    }
    if(key<p->data)
        p->lchild=Delete(p->lchild,key);
    else if(key>p->data)
        p->rchild=Delete(p->rchild,key);
    else
    {
        if(Height(p->lchild)>Height(p->rchild))
        {
            q=Inpre(p->lchild);
            p->data=q->data;
            p->lchild=Delete(p->lchild,q->data);
        }
        else
        {
            q=InSucc(p->rchild);
            p->data=q->data;
            p->rchild=Delete(p->rchild,q->data);
        }
    }
    return p;
}

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
    int key;
    root=RecursiveInsert(root,50);
    RecursiveInsert(root,10);
    RecursiveInsert(root,40);
    RecursiveInsert(root,20);
    RecursiveInsert(root,30);
    Delete(root,30);
    Inorder(root);cout<<endl;
    cout<<"Enter the element you want to search in the tree using Iterative method : "<<endl;
    cin>>key;
    if(Search(key))
        cout<<"The element "<<key<<" is present in the Tree "<<endl;
    else
        cout<<"The element "<<key<<" is not present in the Tree"<<endl;
    cout<<"Enter the element you want to search in the tree using Recursive method : "<<endl;
    cin>>key;
    if(RecursiveSearch(root,key))
        cout<<"The element "<<key<<" is preent in the Tree"<<endl;
    else
        cout<<"The element "<<key<<" is not present in the Tree"<<endl;
    return 0;
}
