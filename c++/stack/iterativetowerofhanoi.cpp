/*_______________________________________________________
|                                                        |
|      Author: Chandan Dwivedi                           |
|  'Life isn't about finding yourself.                   |
|          Life is about creating yourself.'             |
|_______________________________________________________*/

//iterative solution of tower of hanoi using stack.
#include<bits/stdc++.h>
using namespace std;

void iterativetowerhanoi(int n){
  stack<int> st;
  stack<int> ax;
  stack<int> dest;
  st.push(1000000);          //1000000 here represents empty tower.
  ax.push(1000000);
  dest.push(1000000);
  int m=pow(2,n)-1;
  for(int i=1;i<=n;i++){
    cout<<"disk:"<<i<<endl;
    st.push(n-i+1);
  }
  for(int i=1;i<=m;i++){
    if(i%3==1){                  //if i%3=1, legal move between s & d
      if(st.top()<=dest.top()||dest.top()==1000000){
        cout<<"move disk "<<st.top()<<" from S to D"<<endl;
        int p=st.top();
        dest.push(p);
        st.pop();
      }
      else if(dest.top()<=st.top()||st.top()==1000000){
        cout<<"move disk "<<dest.top()<< " from D to S"<<endl;
        int q=dest.top();
        dest.pop();
        st.push(q);
      }
    }
    else if(i%3==2){                //if i%3=2, legal move between s & a
      if(st.top()<=ax.top()||(ax.top()==1000000)){
        cout<<"move disk "<<st.top()<< " from S to A"<<endl;
        int r=st.top();
        ax.push(r);
        st.pop();
      }
      else if(ax.top()<=st.top()||st.top()==1000000){
        cout<<"move disk "<<ax.top()<<" from A to S"<<endl;
        int t=ax.top();
        ax.pop();
        st.push(t);
      }
    }
    else if(i%3==0){                   //if i%3=0, legal move between a & d
      if(ax.top()<=dest.top()||dest.top()==1000000){
        cout<<"move disk "<<ax.top()<< " from A to D"<<endl;
        int u=ax.top();
        dest.push(u);
        ax.pop();
      }
      else if(dest.top()<=ax.top()||ax.top()==1000000){
        cout<<"move disk "<<dest.top()<<" from D to A"<<endl;
        int v=dest.top();
        dest.pop();
        ax.push(v);
      }
    }
  }
}
int main(){
  int z;
  cin>>z;
  iterativetowerhanoi(z);
  return 0;
}
