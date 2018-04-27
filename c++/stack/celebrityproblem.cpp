#include<bits/stdc++.h>
using namespace std;
#define N 8
bool MATRIX[N][N]={{0,0,1,0},
                   {0,0,1,0},
                   {0,0,0,0},
                   {0,0,1,0}};
bool knows(int a,int b){
  return MATRIX[a][b];
}
int celebrity(int n){
  stack<int> st;
  int c;
  for(int i=0;i<n;i++){
    st.push(i);
  }
  int a=st.top();
  st.pop();
  int b=st.top();
  st.pop();
  while(st.size()>1){
    if(knows(a,b)){
      a=st.top();
      st.pop();
    }
    else{
      b=st.top();
      st.pop();
    }
  }
  c=st.top();
  st.pop();
  if(knows(c,b)){
    c=b;
  }
  if(knows(c,a)){
    c=a;
  }
  for(int i=0;i<n;i++){
    if((i!=c)&&(knows(c,i)||!knows(i,c)))
    return -1;
  }
  return c;
}
int main(){            //TODO: create a blogpost for this. https://github.com/Jargon4072/DS-ALGO_implementations/issues/2 id:1
  int n=4;
  int id=celebrity(n);
  if(id==-1){
    cout<<"No celebrity."<<endl;
  }
  else
  cout<<"celebrity  found, id:"<<id<<endl;
  return 0;
}
