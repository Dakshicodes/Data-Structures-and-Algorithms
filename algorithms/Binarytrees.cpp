#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* ledge;
    struct Node* redge;
};
struct Node* createnode(int data){
    struct Node*ptr=(struct Node*)malloc(sizeof(struct Node));
    ptr->data=data;
    ptr->ledge=NULL;
    ptr->redge=NULL;
    return ptr;
}
void preorder(struct Node *ptr){
    if(ptr!=NULL){
        printf("%d ",ptr->data);
        preorder(ptr->ledge);
        preorder(ptr->redge);
    }
}
void postorder(struct Node *ptr){
    if(ptr!=NULL){
        postorder(ptr->ledge);
        postorder(ptr->redge);
        printf("%d ",ptr->data);        
    }
}
void inorder(struct Node *ptr){
    if(ptr!=NULL){
        inorder(ptr->ledge);
        printf("%d ",ptr->data);
        inorder(ptr->redge);
    }
}
int main(){
    struct Node* root=createnode(7);
    struct Node* c11=createnode(11);
    struct Node* c12=createnode(13);
    root->ledge=c11;
    root->redge=c12;
    struct Node* c21=createnode(12);
    struct Node* c22=createnode(26);
    struct Node* c24=createnode(15);
    c11->ledge=c21;
    c11->redge=c22;
    c12->redge=c24;
    preorder(root);
    printf("\n");
    postorder(root);
    printf("\n");
    inorder(root);
    return 0;   
}    