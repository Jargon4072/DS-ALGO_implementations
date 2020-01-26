#include<bits/stdc++.h>
using namespace std;
int arr[10000000];
void next_small_ele(int a[], int n){
  stack<int> st;
  st.push(a[0]);
  map<int,int> m;
  for(int i=1;i<n;i++){
    if(st.empty()){
      st.push(arr[i]);
      continue;
    }
    while(!st.empty() && st.top()>a[i]){
      m[st.top()]=a[i];
      st.pop();
    }
    st.push(a[i]);
  }
  while(!st.empty()){
    m[st.top()]=-1;
    st.pop();
  }
  for(int i=0;i<n;i++){
    cout<<m[arr[i]]<<" ";
  }
  cout<<endl;
}
int main(){
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
      cin>>arr[i];
    }
    next_small_ele(arr, n);
  }
}
