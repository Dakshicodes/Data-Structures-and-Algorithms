#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int value;
    struct node* next;
}node;
node* createnode(int value){
    node*ptr=(node*)malloc(sizeof(node));
    ptr->value=value;
    ptr->next=NULL;
    return ptr;
}
void printLL(node*head){
    if(head==NULL){
        printf("no element to print \n");
    }
    else{
        node*p=head;
        while(p!=NULL){
            printf("%d ",p->value);
            p=p->next;
        }
    }
    printf("\n");
}
node* bubblesort(node* head) {
    if (head == NULL) {
        return NULL;
    }
    else {
        node* end = NULL;
        node* ptr = head;
        
        // Find last node (yeh part sahi hai)
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        end = ptr;
        
        while (end != head) {  // Yeh condition sahi ki
            ptr = head;
            node* q = head->next;

            while (q != end->next) {  // Pehle q->next!=end tha, use q!=end kiya
                if (q->value < ptr->value) {
                    int temp = ptr->value;
                    ptr->value = q->value;
                    q->value = temp;
                }
                ptr = q;
                q = q->next;
            }
            
            end = ptr;  // end ko update karna zaroori hai
        }
    }
    return head;
}
node* bubblesort1(node* head){
    if(head==NULL){
        return NULL;
    }
    else{
       node*end=NULL;
       node*ptr=head;
       while(ptr->next!=NULL){
          ptr=ptr->next;
       }
       end=ptr;
       while(end!=head){
          ptr=head;
          node*q=head->next;
            while(q!=end){
               if(q->value<ptr->value){
                   int temp=ptr->value;
                   ptr->value=q->value;
                   q->value=temp;
               }
               q=q->next;
               ptr=ptr->next;
            }
            end=ptr;
        }
    }
    return head;
}
int main(){
    int T;
    printf("Enter the number of test cases \n");
    scanf("%d",&T);
    while(T--){
        int n;
        printf("Enter the number of elements in your linked list \n");
        scanf("%d",&n);
        node*head=NULL;
        node*temp=NULL;
        node*newnode=NULL;
        for(int i=0;i<n;i++){
            int a;
            printf("Enter the element that you want to insert \n");
            scanf("%d",&a);
            if(i==0){
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
        printLL(head);
        printLL(bubblesort(head));

    }
    return 0;
}