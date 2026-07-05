#include<stdio.h>
#include<stdlib.h>
struct node{
    int coefficient;
    int power;
    struct node* next;
};
struct node* createnode(int coefficient,int power){
    struct node* ptr=(struct node*)malloc(sizeof(struct node));
    ptr->coefficient=coefficient;
    ptr->power=power;
    ptr->next=NULL;
    return ptr;
}
void LLtraversal(struct node* head){
    struct node* p=head;
    while(p->next!=NULL){
        printf("+(%dx^%d)",p->coefficient,p->power);
        p=p->next;
    }
}
struct node* derivative(struct node* head){
    struct node* ptr=head;
    while(ptr!=NULL){
        if(ptr->power!=0){
            ptr->coefficient=(ptr->coefficient)*(ptr->power);
            ptr->power=ptr->power-1;
        }
        else{
            ptr->power=0;
            ptr->coefficient=0;
        }
        ptr=ptr->next;
    }
    return head;
}
int main(){
    int N1;
    printf("enter the number of terms in first polynomial \n");
    scanf("%d",&N1);
    int N2;
    printf("enter the number of terms in the second polynomial \n");
    scanf("%d",&N2);

    struct node* head1;
    struct node* head2;
    struct node* temp;
    struct node*  newnode;

    printf("enter then first polynomial \n");
    for(int i=1;i<=N1;i++){
        int a,b;
        printf("enter the coefficient and power respectively \n");
        scanf("%d %d",&a,&b);
        if(i==1){
            head1=createnode(a,b);
            temp=head1;
        }
        else{
            newnode=createnode(a,b);
            temp->next=newnode;
            temp=newnode;
        }
    }
    temp=NULL;
    //printf("enter the second polynomial");
    for(int i=1;i<=N2;i++){
        int a,b;
        printf("enter the coefficient and power respectively \n");
        scanf("%d %d",&a,&b);
        if(i==1){
            head2=createnode(a,b);
            temp=head2;
        }
        else{
            newnode=createnode(a,b);
            temp->next=newnode;
            temp=newnode;
        }
    }
    LLtraversal(derivative(head1));
    return 0;
}