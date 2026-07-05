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
struct node* middle_element(struct node* head){
    struct node* p=head;
    int counter=1;
    while(p->next!=NULL){
        p=p->next;
        counter++;
    }
    if(counter%2==0){
        p=head;
        int mid=counter/2;
        for(int i=1;i<mid;i++){
            p=p->next;
        }
        return p->next;
        
    }
    else{
        p=head;
        int mid=(counter+1)/2;
        for(int i=1;i<mid;i++){
            p=p->next;
        }
        return p;
    }
}
int main(){
    int T;
    printf("enter the number of test cases \n");
    scanf("%d",&T);
    while(T){
        int N;
        printf("enter the length of your linked list \n");
        scanf("%d",&N);
        struct node* head;
        struct node* newnode;
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
        printf("the middle element of the linked list %d \n",(middle_element(head))->data);
        T--;
    }
}