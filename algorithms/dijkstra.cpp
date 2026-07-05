#include<bits/stdc++.h>
using namespace std;
#define inf 1e9
int main(){
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>> adj[n+1];
    for(int i=0;i<m;i++){
        int u,v,wt;
        cin>>u>>v>>wt;
        adj[u].push_back({v,wt});
        adj[v].push_back({u,wt});
    }
    int source;
    cin>>source;
    
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    vector<int> dist_to(n+1,inf);
    dist_to[source]=0;
    pq.push({0,source});
    while(!pq.empty()){
        int dist=pq.top().first;
        int prev=pq.top().second;
        pq.pop();
        
        for(auto it:adj[prev]){
            int next=it.first;
            int nextdist=it.second;
            if(dist_to[next]>dist+nextdist){
                dist_to[next]=dist+nextdist;
                pq.push(make_pair(dist_to[next],next));
            }
        }
    }
    for(int i=1;i<n+1;i++){
        cout<<source<<"-"<<dist_to[i]<<"->"<<i<<endl;
    }
    
}