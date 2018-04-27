#include<bits/stdc++.h>
using namespace std;
void stockspan(string str){     //TODO: analyze it and implement it again differently. https://github.com/Jargon4072/DS-ALGO_implementations/issues/9 id:8
  stack<int> st;
  st.push(0);
  istringstream stream(str);
  int p;
  int arr[100000];
  int k=0;
  while(stream>>p){
    arr[k]=p;
    k++;
  }
  int s[100000];
  s[0]=1;
  for(int i=1;i<k;i++){
    while(!st.empty()&&arr[st.top()]<=arr[i]){
      st.pop();
    }
    s[i]=(st.empty())?(i+1):(i-st.top());
    st.push(i);
  }
  for(int i=0;i<k;i++){
    cout<<s[i]<<" ";
  }
  cout<<endl;
}
int main(){
  string str;
  getline(cin,str);
  stockspan(str);
  return 0;
}
