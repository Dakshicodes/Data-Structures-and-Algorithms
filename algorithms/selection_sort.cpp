#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void input_vector(vector<int>&v){
    for(int i=0;i<int(v.size());i++){
        cin>>v[i];
    }
    cout<<"the list has been appended"<<endl;
}
void selection_sort(vector<int>&v){
    for(int i=0;i<int(v.size())-1;i++){
        int min_index=i;
        for(int j=i;j<int(v.size());j++){
            if(v[j]<v[min_index]){
                min_index=j;
            }
        }
        swap(v[i],v[min_index]);
    }
    cout<<"the sorting was successful"<<endl;
}
int main(){
    int n;
    cout<<"enter the size of your sequence"<<endl;
    cin>>n;
    vector<int> vec(n);
    input_vector(vec);
    selection_sort(vec);
    for(int val: vec){
        cout<<val<<" ";
    }
    
    return 0;
}