#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*prev;
    struct node*next;
};
struct node* head;
struct node* createnode(int value){
    struct node*ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=value;
    ptr->prev=NULL;
    ptr->next=NULL;
    return ptr;
}
void insertatanyposition(int position){
    int val;
    printf("enter the value to insert \n");
    scanf("%d",&val);
    struct node*newnode=createnode(val);
    struct node*p=head;
    struct node*q=head->next;
    for(int i=1;i<position-1;i++){
        p=p->next;
        q=q->next;
    }
    p->next=newnode;
    q->prev=newnode;
    newnode->prev=p;
    newnode->next=q;
}
void deleteatanyposition(int position){
    struct node*p=head;
    struct node*q=head->next;
    for(int i=1;i<position-1;i++){
        p=p->next;
        q=q->next;
    }
    p->next=q->next;
    (q->next)->prev=p;
    q->prev=NULL;
    q->next=NULL;
    free(q);
}
void linkedlisttraversal(void){
    printf("the final linked list \n");
    struct node*p=head;
    while(p!=NULL){
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}
int main(){
    int T;
    printf("enter the number of testcases");
    scanf("%d",&T);
    while(T--){
        int N,Q;
        printf("enter the number of elements in the doublyLL and number of queries \n");
        scanf("%d  %d",&N,&Q);
        struct node* temp;
        struct node* newnode;
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
                newnode->prev=temp;
                temp->next=newnode;
                temp=newnode;
            }
        }
        temp=NULL;
        for(int i=1;i<=Q;i++){
            int b;
            printf("1 for insertion 2 for deletion \n");
            scanf("%d",&b);
            int position;
            printf("enter the positon \n");
            scanf("%d",&position);
            if(b==2){
                deleteatanyposition(position);
            }
            else{
                insertatanyposition(position);
            }
        }
        linkedlisttraversal();
        T--;
    }
}