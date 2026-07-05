#include<bits/stdc++.h>
using namespace std;
#define inf 1e9

int main(){
    int N,M;
    cin>>N>>M;
    vector<pair<int,int>> adj[N+1];

    int u,v,wt;
    for(int i=0;i<M;i++){
        cin>>u>>v>>wt;
        adj[u].push_back(make_pair(v,wt));
        adj[v].push_back(make_pair(u,wt));
    }
    
    vector<int> parent(N+1,-1);
    vector<bool> mst(N+1,false);
    vector<int>  key(N+1,inf);

    key[1]=0;
    for(int i=0;i<N-1;i++){
        int mini=inf,a;
        for(int b=1;b<N+1;b++){
            if(mst[b]==false && key[b]<mini){
                mini=key[b];
                a=b;
            }
        }
        mst[a]=true;
        
        for(auto it:adj[a]){
            int x=it.first;
            int weight=it.second;
            if(mst[x]==false&&weight<key[x]){
                key[x]=weight;
                parent[x]=a;
            }
        }
    }
    for(int i=2;i<N+1;i++){
        cout<<parent[i]<<"-"<<key[i]<<"->"<<i<<endl;
    }
}