#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node* left;
    struct node* right;
}node;
node* createnode(int value){
     node* ptr=(node*)malloc(sizeof(node));
     ptr->data=value;
     ptr->left=NULL;
     ptr->right=NULL;
     return ptr;
}
void insert(node**root_pointer,int data){
    if(*root_pointer==NULL){
        *root_pointer=createnode(data);
        return;
    }
    node*ptr=*root_pointer;
    node*prev=NULL;
    while(ptr!=NULL){
        prev=ptr;
        if(data==ptr->data){
            printf("data already exist\n");
            return;
        }
        else if(data<ptr->data){
            ptr=ptr->left;
        }
        else{
            ptr=ptr->right;
        }
    }
    if(data<prev->data){
        prev->left=createnode(data);
    }
    else{
        prev->right=createnode(data);
    }
}
void inorder(node* root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}
node* search(node*root,int value){
    if(root==NULL){
        return NULL;
    }
    
}
int main(){
    int T;
    printf("Enter the number of testcases \n");
    scanf("%d",&T);
    while(T--){
        int N;
        printf("Enter the number of elements in your bst\n");
        scanf("%d",&N);
        node* root=NULL;
        for(int i=0;i<N;i++){
            int k;
            printf("Enter the value to insert \n");
            scanf("%d",&k);
            insert(&root,k);
        }
        inorder(root);

    }
}