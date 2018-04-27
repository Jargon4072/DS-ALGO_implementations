#include<bits/stdc++.h>
using namespace std;
void stock_span(int arr[],int n){
  int s[1000005];
  int p;
  stack<int> ind;
  for(int i=0;i<n;i++){
    while(!ind.empty()){
      if(arr[i]>arr[ind.top()]){
        ind.pop();
      }
      else break;
    }
    if(ind.empty())
      p=-1;
    else p=ind.top();
    s[i]=i-p;
    ind.push(i);
  }
  cout<<"span: ";
  for(int i=0;i<n;i++){
    cout<<s[i]<<" ";
  }
  cout<<endl;
}
int main(){
  int arr[1000005];
  int n;
  string str;
  getline(cin,str);
  istringstream ss(str);
  int m;
  int i=0;
  while(ss>>m){
    arr[i]=m;
    i++;
  }
  n=i;
  stock_span(arr,n);
  return 0;
}