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
    cout<<v+1<<" ";
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
    int t;
    cin>>t;
    while(t--){
        int v,e;
        cin>>v;
        cin>>e;
        //cout<<"e: "<<e<<endl<<"v: "<<v<<endl;
        graph g(v);
        int p,q;
        for(int i=0;i<e;i++){
            cin>>p;
            cin>>q;
            g.addEdge(p-1,q-1);
        }
        g.dfs();
    }
    return 0;
}
