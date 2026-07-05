#include<stdio.h>
#include<stdlib.h>
void printarray(int arr[],int size){
    for(int i=0;i<size;i++){
        printf("%d ",*(arr+i));
    }
}
int main(){
    int days;
    printf("enter days of observation of stock");
    scanf("%d",&days);
    int price[days];
    int span[days];
    for(int i=0;i<days;i++){
        printf("enter the prize of stock on the %d day \n",i);
        scanf("%d",price+i);
    }
    span[0]=1;
    for(int i=1;i<days;i++){
        int k=0;
        for(int k=i;k>-1;k--){
            if(price[k]<=price[i]){
                k++;
            }
            else{
                break;
            }
        }
        span[i]=k;
    }
    printarray(span,days);
    return 0;
}