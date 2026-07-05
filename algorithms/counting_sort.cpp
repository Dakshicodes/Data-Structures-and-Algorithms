#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){ cin>>arr[i];}
    int max=arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]>max){ max=arr[i];}
    }
    vector<int> count_array(max+1,0);
    for(int i=0;i<n;i++){count_array[arr[i]]+=1;}
    
    for(int i=0;i<max;i++){
        count_array[i+1]+=count_array[i];
    }
    vector<int> sorted_array(n);
    for(int i=n-1;i>=0;i--){
        count_array[arr[i]]-=1;
        sorted_array[count_array[arr[i]]]=arr[i];
    }
   for(int i:sorted_array){
       cout<<i<<"  ";
   }
    return 0;
}