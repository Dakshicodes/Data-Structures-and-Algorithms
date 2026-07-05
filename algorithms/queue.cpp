#include<stdio.h>
#include<stdlib.h>
struct Queue{
    int storage;
    int findex;
    int bindex;
    int *arr;
};
int Isfull(struct Queue* ptr){
    if((ptr->bindex)-(ptr->findex)==ptr->storage){
        return 1;
    }
    else{
        return 0;
    }
}
int Isempty(struct Queue *ptr){
    if(ptr->bindex==ptr->findex){
        return 1;
    }
    else{
        return 0;
    }
}
void enqueue(struct Queue *ptr,int value){
    if(Isfull(ptr)){
        printf("Queue Overflow");
    }
    else{
        ptr->bindex+=1;
        ptr->arr[ptr->bindex]=value;
        printf("enqueue successful! \n");
    }
}
int dequeue(struct Queue* ptr){
    if(Isempty(ptr)){
        return -1;
    }
    else{
        ptr->findex+=1;
        return ptr->arr[ptr->findex];
    }

}

int main(){
    struct Queue *q;
    printf("enter the queue storage \n");
    scanf("%d",&(q->storage));
    q->findex=-1;
    q->bindex=-1;
    q->arr=(int*)malloc(q->storage*sizeof(int));
    enqueue(q,15);
    enqueue(q,17);
    dequeue(q);
    dequeue(q);

    printf("%d ",Isempty(q));

    return 0;
}