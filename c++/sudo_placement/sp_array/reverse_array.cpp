#include<bits/stdc++.h>
using namespace std;
long long int arr[1000000];

void reverse(long long int a[],long long int n){
  for(long long int i=n-1;i>=0;i--){
    cout<<a[i]<<" ";
  }
  cout<<endl;
}
int main(){
  long long int t;
  cin>>t;
  while(t--){
    long long int n;
    cin>>n;
    for(long long int i=0;i<n;i++){
      cin>>arr[i];
    }
    reverse(arr,n);
  }
  return 0;
}