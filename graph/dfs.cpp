#include<bits/stdc++.h>
using namespace std;
class graph{
    int V;
    list<int> *adj;
    void dfsutil(int v,bool visited[]);
public:
    graph(int V);
    void addEdge(int v,int w);
    void dfs();
};
graph::graph(int V){
    this->V=V;
    adj=new list<int>[V];
}
void graph::addEdge(int v,int w){
    adj[v].push_back(w);
}
void graph::dfsutil(int v,bool visited[]){
    visited[v]=true;
    cout<<v<<" ";
    list<int>::iterator it;
    for(it=adj[v].begin();it!=adj[v].end();++it){
        if(!visited[*it]){
            dfsutil(*it,visited);
        }
    }
}
void graph::dfs(){
    bool *visited=new bool[V];
    for(int i=0;i<V;i++){
        visited[i]=false;
    }
    for(int i=0;i<V;i++){
        if(visited[i]==false){
            dfsutil(i,visited);
        }
    }
}
int main(){
    graph g(4);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,2);
    g.addEdge(2,0);
    g.addEdge(2,3);
    g.addEdge(3,3);
    cout<<"DFS of the given graph is:"<<endl;
    g.dfs();
    return 0;
}
