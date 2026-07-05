#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};
struct node* createnode(int value){
    struct node* ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=value;
    ptr->next=NULL;
    return ptr;
}
struct node* createcycle(struct node* ptr,int index){
    if(index==1){
        struct node*p=ptr;
        struct node*q=ptr;
        while(q->next!=NULL){
            q=q->next;
        }
        q->next=p;
        return ptr;
    }
    else{
        struct node*p=ptr;
        struct node*q=ptr;
        while(q->next!=NULL){
            q=q->next;
        }
        for(int i=1;i<index;i++){
            p=p->next;
        }
        q->next=p;
        return ptr;
    }
}
struct node* cycle_start_index(struct node*ptr){
    struct node*p=ptr;
    struct node*q=ptr;
    while(q!=NULL&&q->next!=NULL){
        p=p->next;
        q=(q->next)->next;
        if(p==q){
            p=ptr;
            while(p!=q){
                p=p->next;
                q=q->next;
            }
            return p;
        }
    }
    return NULL;
}
int main(){
    int T;
    printf("enter the number of test cases");
    scanf("%d",&T);
    while(T){
        int N;
        printf("enter the size of your linked list \n");
        scanf("%d",&N);
        int I;
        printf("enter the index where the cycle starts \n");
        scanf("%d",&I);
        struct node*head;
        struct node*newnode;
        struct node* temp;
        for(int i=1;i<=N;i++){
            int a;
            printf("enter the element \n");
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
        createcycle(head,I);
        printf("the cycle start where the node value is %d \n",(cycle_start_index(head))->data);
        free(head);
        T--;   
    }
    return 0;
}