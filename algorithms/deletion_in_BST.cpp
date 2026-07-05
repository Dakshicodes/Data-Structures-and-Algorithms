#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* ledge;
    struct Node* redge;
};
struct Node* createnode(int data){
    struct Node* ptr=(struct Node*)malloc(sizeof(struct Node));
    ptr->data=data;
    ptr->ledge=NULL;
    ptr->redge=NULL;
    return ptr;
}
void inorder(struct Node*ptr){
    if(ptr!=NULL){
        inorder(ptr->ledge);
        printf("%d ",ptr->data);
        inorder(ptr->redge);
    }
}
struct Node* inorderpred(struct Node* ptr){
     ptr=ptr->ledge;
     while(ptr->redge!=NULL){
        ptr=ptr->redge;
     }
     return ptr;
}
struct Node* dltNode(struct Node* ptr,int value){
    struct Node * ipre;
    if(ptr==NULL){
        return NULL;
    }
    if(ptr->ledge==NULL && ptr->redge==NULL){
        free(ptr);
    }
    if(value<ptr->data){
        dltNode(ptr->ledge,value);
    }
    else if(value>ptr->data){
        dltNode(ptr->redge,value);
    }
    else{
        ipre=inorderpred(ptr);
        ptr->data=ipre->data;
        dltNode(ptr->ledge,ipre->data);
    }
}
main(){
    struct Node*root=createnode(26);
    struct Node*c11=createnode(21);
    struct Node*c12=createnode(45);
    root->ledge=c11;
    root->redge=c12;
    struct Node* c21=createnode(12);
    struct Node* c22=createnode(25);
    struct Node* c24=createnode(51);
    struct Node* c31=createnode(9);
    c11->ledge=c21;
    c11->redge=c22;
    c12->redge=c24;
    c21->ledge=c31;
    inorder(root);
    printf("\n");
    struct Node *p=dltNode(root,9);
    inorder(p);
    return 0;
}
