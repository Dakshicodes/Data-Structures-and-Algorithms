#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node*next;
};

void linkedlisttraversal(struct Node*head){
     struct Node* ptr=(struct Node*)malloc(sizeof(struct Node));   
     ptr=head;
     while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->next;
     }
}

struct Node* deletebeginning(struct Node* head){
    struct Node*ptr=(struct Node*)malloc(sizeof(struct Node));
    ptr=head;
    head=head->next;
    free(ptr);
    return head;
}

struct Node* deleteinbtw(struct Node* head){
    int index;
    printf("enter the index of the element which you want to delete ");
    scanf("%d",&index);
    struct Node* ptr=(struct Node*)malloc(sizeof(struct Node));
    ptr=head;
    int i=0;
    while(i<index-1){
        ptr=ptr->next;
        i++;
    }
    struct Node*q=(struct Node*)malloc(sizeof(struct Node));
    q=ptr->next;
    ptr->next=q->next;
    free(q);
    return head;
}
struct Node* deleteinend(struct Node* head){
    struct Node* ptr=(struct Node*)malloc(sizeof(struct Node));
    ptr=head;
    struct Node*q=(struct Node*)malloc(sizeof(struct Node));
    q=ptr->next;
    while(q->next!=NULL){
        ptr=ptr->next;
        q=q->next;
    }
    ptr->next=NULL;
    return head;
}

int main(){
    struct Node*head=(struct Node*)malloc(sizeof(struct Node));
    struct Node*second=(struct Node*)malloc(sizeof(struct Node));
    struct Node*third=(struct Node*)malloc(sizeof(struct Node));
    struct Node*fourth=(struct Node*)malloc(sizeof(struct Node));
    head->data=56;
    head->next=second;
    second->data=98;
    second->next=third;
    third->data=76;
    third->next=fourth;
    fourth->data=34;
    fourth->next=NULL;
    head=deleteinbtw(head);
    linkedlisttraversal(head);

    return 0;
}