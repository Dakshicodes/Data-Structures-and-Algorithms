#include<stdio.h>
#include<stdlib.h>
struct cQueue{
    int size;
    int findex;
    int bindex;
    int *arr;
};
int Isempty(struct cQueue*Q){
    if((Q->bindex+1)%(Q->size)==Q->findex){
        return 1;
    }
    else{
        return 0;
    }
}
int Isfull(struct cQueue*Q){
    if((Q->bindex+2)%(Q->size)==Q->findex){
        return 1;
    }
    else{
        return 0;
    }
}
void enqueue(struct cQueue *Q,int value){
    if(Isfull(Q)){
        printf("queue overflow");
    }
    else{
        Q->bindex=(Q->bindex+1)%(Q->size);
        Q->arr[Q->bindex]=value;
        printf("enqueue successful \n");
    }
}
int dequeue(struct cQueue *Q){
    int a;
    if(Isempty(Q)){
        return -1;
    }
    else{
        Q->findex=(Q->findex+1)%(Q->size);
        a=Q->arr[Q->findex];
        return a;
    }
}

int main(){
    struct cQueue *Q=(struct  cQueue*)malloc(sizeof(struct cQueue));
    Q->size=6;
    Q->arr=(int*)malloc((Q->size)*sizeof(int));
    Q->findex=0;
    Q->bindex=-1;
    //enqueue(Q,56);
    printf("%d \n",Isempty(Q));
    printf("%d",Isfull(Q));
    enqueue(Q,56);
    enqueue(Q,56);
    enqueue(Q,56);
    enqueue(Q,56);
    enqueue(Q,56);
    enqueue(Q,56);
    printf("%d",Isfull(Q));
    return 0;
}