#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* ledge;
    struct node* redge;
    int height;
};
int getheight(struct node*ptr){
    if(ptr==NULL){
        return 0;
    }
    return ptr->height;
}
struct node* createnode(int data){
    struct node* p=(struct node*)malloc(sizeof(struct node));
    p->data=data;
    p->ledge=NULL;
    p->redge=NULL;
    p->height=1;
    return p;
}
int getBF(struct node* ptr){
    if(ptr==NULL){
        return 0;
    }
    return getheight(ptr->redge)-getheight(ptr->ledge);
}
struct node* rightrotate(struct node* y){
    struct node* x=y->ledge;
    struct node* t2=x->redge;
    x->redge=y;
    y->ledge=t2;
    
    y->height=max(getheight(y->redge),getheight(y->ledge))+1;
    x->height=max(getheight(x->redge),getheight(x->ledge))+1;
    return x;
}
struct node* leftrotate(struct node* x){
    struct node* y=x->redge;
    struct node* t2=y->ledge;
    y->ledge=x;
    x->redge=t2;
    y->height=max(getheight(y->redge),getheight(y->ledge))+1;
    x->height=max(getheight(x->redge),getheight(x->ledge))+1;
    
    return y;
}
struct node *insert(struct node*root,int value){
    if(root==NULL){
        return createnode(value);
    }
    if(value<root->data){
        root->ledge=insert(root->ledge,value);
    }
    else if(value>root->data){
        root->redge=insert(root->redge,value);
        return root;
    }
}