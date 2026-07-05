#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void input_vector(vector<int>&v){
    for(int i=0;i<(int)v.size();i++){
        cin>>v[i];
    }
    cout<<"the vector has been appended"<<endl;
}
int main(){
    int n;
    cout<<"Enter the size of your sequence"<<endl;
    cin>>n;
    vector<int> vec(n);
    input_vector(vec);
    int current_sum=vec[0];
    int max_sum=vec[0];
    for(int i=0;i<(int)vec.size();i++){
        int current_element=vec[i]; 
        current_sum=max(current_element,current_sum+current_element);
        max_sum=max(max_sum,current_sum);
    }
    cout<<"the maximum subarray sum is equal to "<<max_sum<<endl;
}