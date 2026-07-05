#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void input_vector(vector<int>&v){
    for(int i=0;i<int(v.size());i++){
        cin>>v[i];
    }
    cout<<"the vector has been appended"<<endl;
}
int binary_search(vector<int>v,int k){
    int left=0;
    int right=int(v.size())-1;
     int middle;
    while(left<=right){
        middle=left+(right-left)/2;
        if(v[middle]==k)break;
        else if(v[middle]>k)right=middle-1;
        else left=middle+1;
    }
    return middle;
}
int main(){
    int n;
    cout<<"enter the size of your sequence"<<endl;
    cin>>n;
    vector<int> vec(n); 
    input_vector(vec);
    sort(vec.begin(),vec.end());
    int k;
    cout<<"enter the element that you want to search"<<endl;
    cin>>k;
    int element_position=binary_search(vec,k);
    if(element_position==-1){
        cout<<"element is not there in the sequence "<<endl;
    }
    else{
        cout<<"the index of the element is "<<element_position<<endl;
    }

    return 0;
}