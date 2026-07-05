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
void inorder(struct Node *ptr){
    if(ptr!=NULL){
        inorder(ptr->ledge);
        printf("%d ",ptr->data);
        inorder(ptr->redge);
    }
}

int isBST(struct Node*ptr){
    static struct Node*prev=NULL;
    if(ptr!=NULL){
        if(!isBST(ptr->ledge)){
            return 0;
        }
        if(prev!=NULL && ptr->data<=prev->data){
            return 0;
        }
        prev=ptr;
        return isBST(ptr->redge);
    }
    else{
        return 1;
    }
}
int main(){
    struct Node* root=createnode(13);
    struct Node* c11=createnode(11);
    struct Node* c12=createnode(15);
    root->ledge=c11;
    root->redge=c12;
    struct Node* c21=createnode(7);
    struct Node* c22=createnode(12);
    struct Node* c24=createnode(26);
    c11->ledge=c21;
    c11->redge=c22;
    c12->redge=c24;
    inorder(root);
    printf("\n");
    printf("%d",isBST(root));
    printf("\n");
    struct Node* p;
    printf("%d ",p->data);
    return 0;
}
