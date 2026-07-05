#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>> adj_list[n];

    int u,v,wt;
    for(int i=0;i<m;i++){
        cin>>u>>v>>wt;
        adj_list[u].push_back({v,wt});
    }
    
    vector<int> dist_to(n,INT_MAX);
    
    int source;
    cin>>source;
    dist_to[source]=0;
    
    for(int i=1;i<n;i++){
        for(int j=0;j<n;j++){
            for(auto it:adj_list[j]){
                if(dist_to[j]!=INT_MAX&&dist_to[it.first]>dist_to[j]+it.second){
                    dist_to[it.first]=dist_to[j]+it.second;
                }
            }
        }
    }
    for(int j=0;j<n;j++){
        for(auto it:adj_list[j]){
            if(dist_to[j]!=INT_MAX&&dist_to[it.first]>dist_to[j]+it.second){
                    cout<<"negative cycle exist"<<endl;
                    return 0;
            }
        }            
    }
    cout<<"no negative cycle exists"<<endl;
    return 0;
}