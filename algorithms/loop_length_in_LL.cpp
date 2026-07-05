#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};
struct node* createnode(int value){
    struct node*ptr=(struct node*)malloc(sizeof(struct node));
    (*ptr).data=value;
    (*ptr).next=NULL;
    return ptr;
}
struct node* createloop(struct node* head,int position,int size){
    if(position==-1){
        return head;
    }
    else{
        struct node*p=head;
        struct node*q=head;
        while(p->next!=NULL){
            p=p->next;
        }
        for(int i=1;i<position;i++){
            q=q->next;
        }
        p->next=q;
        return head;
    }
}
int member_in_loop(struct node*head){
    struct node* ptr=head;
    int count=0;
    while(ptr!=NULL){
        
    }
}
int main(){
    int N;
    scanf("%d",N);
    int M;
    scanf("%d",&M);
    struct node* head;
    struct node* temp;
    struct node* newnode;
    for(int i=1;i<=N;i++){
        int a;
        scanf("%d",&a);
        if(i==1){
            head=createnode(a);
            temp=head;
        }
        else{
            newnode=createnode(a);
            temp->next=newnode;
            temp=newnode;
        }
    }
    createloop(head,M,N);
    printf("The  no. of members in loop are %d \n",member_in_loop(head));
    return 0;
}