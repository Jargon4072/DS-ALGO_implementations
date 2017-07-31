#include<bits/stdc++.h>
using namespace std;
int cost[100][100],j,k,n,stk[100],top,v,visited[100],visit[100];
int main(){
    cin>>n;
    int m;
    cin>>m;
    for(int i=0;i<m;i++){
        cin>>j;
        cin>>k;
        cost[j][k]=1;
    }
    cin>>v;
    cout<<"DFS: "<<endl;
    cout<<v<<" ";
    visited[v]=1;
    int p;
    p=1;
    while(p<n){
        for(int i=n;i>=1;i--){
            if(cost[v][i]!=0&&visited[i]!=1&&visit[i]!=1){
                visit[i]=1;
                stk[top]=i;
                top++;
            }
        }
        v=stk[--top];
        cout<<v<<" ";
        p++;
        visit[v]=0;
        visited[v]=1;
    }
}
