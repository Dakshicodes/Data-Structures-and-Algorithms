#include <stdio.h>
#include <stdlib.h>
struct stack
{
    int size;
    int top;
    int *arr;
};
int IsEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int IsFull(struct stack *ptr)
{
    if (ptr->top == (ptr->size) - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void push(struct stack *ptr)
{
    int value;
    printf("enter the element that you want push");
    scanf("%d", &value);
    if (IsFull(ptr))
    {
        printf("stack overflow");
    }
    else{
      
        ptr->top++;
        ptr->arr[ptr->top] = value;
    }
}
int pop(struct stack *ptr){
    if(IsEmpty(ptr)){
        printf("stack underflow");
        return -1;
    }
    else{
        int valuepopped=ptr->arr[ptr->top];
        ptr->top=ptr->top-1;
        return valuepopped;
    }
}
int main()
{
    struct stack *S;
    printf("enter the size of your array");
    scanf("%d",&(S->size));
    S->top = -1;
    S->arr = (int *)malloc(S->size * sizeof(int));
    *S->arr = 7;
    printf("%d \n",IsEmpty(S));
    printf("%d \n",IsFull(S));
    push(S);
    printf("%d \n",IsEmpty(S));
    printf("%d \n",IsFull(S));
    printf("%d",S->top);
    push(S);
    printf("%d \n",S->top);
    printf("%d",S->arr[S->top]);
    return 0;
}
   
