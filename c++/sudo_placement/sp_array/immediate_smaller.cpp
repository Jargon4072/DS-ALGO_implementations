#include<bits/stdc++.h>
using namespace std;
long long int arr[10000000];
void imm_small(long long int a[],long long int n){
  long long int x;
  for(long long int i=0;i<n-1;i++){
    if(a[i+1]<a[i]){
      cout<<a[i+1]<<" ";
    }
    else {
      x=-1;
      cout<<x<<" ";
    }
  }
  long long int p=-1;
  cout<<p<<endl;;
}
int main(){
  //cout<<"enter t: "<<endl;
  long long int t;
  cin>>t;
  while(t--){
    long long int n;
    cin>>n;
    for(long long int i=0;i<n;i++){
      cin>>arr[i];
    }
    imm_small(arr,n);
  }
  return 0;
}