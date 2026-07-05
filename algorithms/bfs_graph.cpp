#include<iostream>//normal
#include<queue>//explored nodes ke liye queue use kar rhe hain.
#include<vector>//visited nodes ka vector banega.
#include<list>//adjacency list banane ke liye iska use.
using namespace std;
class Graph{
    int V;
    list<int> *l;
    public:
       Graph(int number){
        V=number;
        l=new list<int>[V];
       }
       void addEdge(int u,int v){
        l[u].push_back(v);  
        l[v].push_back(u);  
       }
       void bfs();
};
void Graph:: bfs(){
    queue<int> explored_nodes;
    vector<bool> visited_nodes(V,false);
    explored_nodes.push(0);
    visited_nodes[0]=true;
    while(explored_nodes.size()>0){
        int u=explored_nodes.front();
        explored_nodes.pop();
        cout<<u<<" ";
        for(int val: l[u]){
            if(!visited_nodes[val]){
                visited_nodes[val]=true;
                explored_nodes.push(val);
            }
        }
    }
}
int main(){
    Graph g(5);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(2,3);
    g.addEdge(2,4);
    
    g.bfs();
    return 0;
}