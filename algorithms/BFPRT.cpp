#include<iostream>//blum floyd pratt rivest tarjan algorithm- finding the kth smallest element in a sequence.
#include<vector>
#include<algorithm>
using namespace std;
void input_vector(vector<int> &v){
    for(int i=0;i<(int)v.size();i++){
        cin>>v[i];
    }
    cout<<"the vector has been appended"<<endl;
}
int BFPRT(vector<int>&v,int k){
    if(v.size()<=5){
        sort(v.begin(),v.end());
        return v[k-1];
    }
    vector<int> medians;
    for (int i = 0; i < (int)v.size(); i += 5) {
        int l = i;
        int r = min(i+4,(int)v.size()-1);

        sort(v.begin()+l,v.begin()+r+1);                                                            
        int median = v[l + (r - l) / 2];
        medians.push_back(median);
    }

    int medians_of_median=BFPRT(medians,(medians.size()/2));
    vector<int> left;
    vector<int> right;
    for(int i=0;i<(int)v.size();i++){
        if(v[i]<medians_of_median){
            left.push_back(v[i]);
        }
        else{
            right.push_back(v[i]);
        }
    }
    if(k==((int)left.size()+1)){
        return medians_of_median;
    }
    else if(k<=(int)left.size()){
        return BFPRT(left,k);
    }
    else{
        return BFPRT(right,k-(left.size()));
    }
}
int main(){
    int n;
    cout<<"enter the size of your sequence"<<endl;
    cin>>n;
    vector<int> vec(n);
    input_vector(vec);
    int k;
    cout<<"enter the kth position"<<endl;
    cin>>k;
    cout<<"the value of the kth smallest element "<<BFPRT(vec,k)<<endl;

    return 0;
}
