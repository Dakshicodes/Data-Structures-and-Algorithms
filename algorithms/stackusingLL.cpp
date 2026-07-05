#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};
int Isempty(struct Node*ptr){
    if(ptr==NULL){
        return 1;
    }
    else{
        return 0;
    }
}
int Isfull(struct Node *ptr){
    struct Node* p=(struct Node*)malloc(sizeof(struct Node));
    if(p==NULL){
        return 1;
    }
    else{
        return 0;
    }
}
struct Node* push(struct Node*ptr,int value){
    struct Node*p=(struct Node*)malloc(sizeof(struct Node));
    if(Isfull(ptr)){
        return ptr;
    }
    else{
        p->data=value;
        p->next=ptr;
        ptr=p;
        return ptr;
    }
}
int pop(struct Node*ptr){
    struct Node*p=ptr;
    int a;
    if(Isempty(ptr)){
        return -1;
    }
    else{
        a=ptr->data;
        ptr=ptr->next;
        free(p);
        return a;
    }
}
int main(){
    struct Node* top=NULL;
    push(top,78);
    printf("%d",Isempty(top));
}