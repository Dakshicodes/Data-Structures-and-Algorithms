#include<iostream>//5 2 8 3 1 7
#include<vector>
using namespace std;
void input_vector(vector<int> & v){
    for(int i=0;i<(int)v.size();i++){
        cin>>v[i];
    }
    cout<<"The vector has been appended"<<endl;
}
void merge_sorted(vector<int> &v,int left,int mid,int right){
    vector<int> temp;
    int i=left,j=mid+1;
    while(i<=mid&&j<=right){
        if(v[i]<=v[j]){
            temp.push_back(v[i]);
            i++;
        }
        else{
            temp.push_back(v[j]);
            j++;
        }
    }
    if(i>mid){
        while(j<=right){
            temp.push_back(v[j]);
            j++;
        }
    }
    if(j>right){
        while(i<=mid){
            temp.push_back(v[i]);
            i++;
        }
    }
    for(int i=0;i<(int)temp.size();i++){
        v[left+i]=temp[i];
    }
    return;
}
void mergesort(vector<int>&v,int left,int right){
    if(left==right){
        return ;
    }
   if(left<right){
       int middle=(left+right)/2;
       mergesort(v,left,middle);
       mergesort(v,middle+1,right);
       merge_sorted(v,left,middle,right);
       return;
   }
}
int main(){
    int n;
    cout<<"enter the number of elements in your sequence"<<endl;
    cin>>n;
    vector<int> vec(n);
    input_vector(vec);
    int l=0;
    int r=int(vec.size())-1;
    mergesort(vec,l,r);
    cout<<"the new vector after sorting is"<<endl;
    for(int val:vec){
        cout<<val<<" ";
    }
}