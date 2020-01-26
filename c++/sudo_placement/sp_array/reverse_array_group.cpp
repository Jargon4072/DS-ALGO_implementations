#include<bits/stdc++.h>
using namespace std;
long long int arr[1000000];

int main(){
  long long int t;
  cin>>t;
  while(t--){
    long long int n;
    cin>>n;
    long long int k;
    cin>>k;
    stack<long long int> st;
    long long int p=0;
    for(long long int i=0;i<n;i++){
      cin>>arr[i];
      st.push(arr[i]);
      p++;
      if(p==k){
        while(!st.empty()){
          cout<<st.top()<<" ";
          st.pop();
          p--;
        }
      }
    }
    if(!st.empty()){
      while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
      }
    }
    cout<<endl;
  }
}