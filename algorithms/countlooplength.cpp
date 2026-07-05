#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};
struct node*createnode(int value){
    struct node* ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=value;
    ptr->next=NULL;
    return ptr;
}
struct node* createcycle(struct node*ptr,int index){
    struct node* p=ptr;
    struct node* q=ptr;
    if(index<=0){
        return ptr;
    }
    else{
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
struct node* cyclestart(struct node* ptr){
    struct node* p=ptr;
    struct node* q=ptr;
    while(q!=NULL && q->next!=NULL){
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
int countlooplength(struct node*ptr){
    if(ptr==NULL){
        return -1;
    }
    else{
        struct node* p=ptr;
        struct node* q=ptr->next;
        int counter=1;
        while(q!=p){
            q=q->next;
            counter++;
        }
        return counter;
    }
}
/*void freeheap(struct node* head){
    struct node*temp;
}*/
int main(){
    int T;
    printf("enter the no. of test cases \n");
    scanf("%d",&T);
    while(T){
        int N;
        printf("enter the length of your linked list \n");
        scanf("%d",&N);
        int I;
        printf("enter the index where the cycle has to be formed \n");
        scanf("%d",&I);
        struct node* head;
        struct node* newnode;
        struct node* temp;
        for(int i=1;i<=N;i++){
            int a;
            printf("enter the value of the element \n");
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
        temp=NULL;
        head=createcycle(head,I);
        struct node*cycle=cyclestart(head);
        printf("the length of the loop in LL is %d \n",countlooplength(cycle));
        T--;
    }
    return 0;
}