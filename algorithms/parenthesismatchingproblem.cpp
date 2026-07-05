#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct stack{
    int size;
    int top;
    char* arr;
};
int isempty(struct stack* ptr){
    if(ptr->top==-1){
        return 1;
    }
    else{
        return 0;
    }
}
int isfull(struct stack *ptr){
    if(ptr->top==ptr->size-1){
        return 1;
    }
    else{
        return 0;
    }
}
void push(struct stack*ptr,char element){
    if(isfull(ptr)){
        printf("stack overflow");
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top]=element;
    }
}
void pop(struct stack*ptr){
    if(isempty(ptr)){
        printf("stack underflow");
    }
    else{
        ptr->top--;
    }
}
int main(){
    struct stack *S=(struct stack*)malloc(sizeof(struct stack));
    S->size=20;
    S->top=-1;
    S->arr=(char*)malloc(sizeof(char)*S->size);
    char expression[100];
    scanf("%s",expression);
    int i;
    for(i=0;i<(int)strlen(expression);i++){
        if(expression[i]=='('){
            if(isfull(S)){
                printf("stack storage full");
            }
            else{
                push(S,'(');
            }
        }
        else if(expression[i]==')'){
            if(isempty(S)){
                printf("the expression is unbalanced");
                break;
            }
            else{
                pop(S);
            }
        }
        else{
        }
    }
    if(i==(int)strlen(expression)){
        if(isempty(S)){
            printf("the expression is balanced");
        }
        else{
            printf("the expression is not balanced");
        }
    }
    return 0;
    free(S->arr);
    free(S);
}