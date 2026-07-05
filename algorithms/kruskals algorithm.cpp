#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int parent[N];
int size[N];
void make(int v){//creates a new node.
    parent[v]=v;
    size[v]=1;
}
int find(int v){//finds the parent of the element.
    if(v==parent[v]){
        return v;
    }
    return parent[v]=find(parent[v]);
}
void Union(int a,int b){
    a=find(a);
    b=find(b);
    if(a!=b){//union by size;
        if(size[a]<size[b]){
            swap(a,b);
        }
        parent[b]=a;
        size[a]+=size[b];
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<pair<int,pair<int,int>>> edges;
    for(int i=0;i<m;i++){
        int wt,u,v;
        cin>>wt>>u>>v;
        edges.push_back({wt,{u,v}});
    }
    sort(edges.begin(),edges.end());
    for(int i=1;i<(n+1);i++){
        make(i);
    }
    int Total_cost=0;
    for(auto &edge:edges){
        int wt=edge.first;
        int u=edge.second.first;
        int v=edge.second.second;
        if(find(u)==find(v)){
            continue;
        }
        Union(u,v);
        Total_cost+=wt;
        cout<<u<<"->"<<v<<endl;
    }
    cout<<"the total cost of the mst is "<<Total_cost;
    return 0;
}
