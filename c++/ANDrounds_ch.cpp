#include<bits/stdc++.h>
using namespace std;

void andarr(int arr[],int n){
  for(int i=0;i<n;i++){
    if(i==0){
      arr[i]=arr[i] & arr[n-1] & arr[i+1];
    }
    else if(i==n-1){
      arr[i]=arr[i] & arr[i-1] & arr[0];
    }
    else{
      arr[i]=arr[i] & arr[i-1] & arr[i+1];
    }
  }
}

int main(int argc, char const *argv[]) {
  int  t;
  cin>>t;
  int n,k;
  int arr[1000005];
  while(t--){
    cin>>n;
    cin>>k;
    for(int i=0;i<n;i++){
      cin>>arr[i];
    }
    while(k--){
      andarr(arr,n);
    }
    for (int i = 0; i < n; i++) {
      cout<<arr[i]<<" ";
    }
    cout<<endl;
  }
  return 0;
}
