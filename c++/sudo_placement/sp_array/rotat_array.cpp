#include<bits/stdc++.h>
using namespace std;
long long int arr[10000000];
void rotat(long long int a[], long long int n, long long int d){
  for(int i=d;i<n;i++){
    cout<<a[i]<<" ";
  }
  for(long long int i=0;i<d-1;i++){
    cout<<a[i]<<" ";
  }
  cout<<a[d-1]<<endl;
}
int main(){
  long long int t;
  cin>>t;
  while(t--){
    long long int n;
    cin>>n;
    long long int p;
    cin>>p;
    for(long long int i=0;i<n;i++){
      cin>>arr[i];
    }
    rotat(arr,n,p);
  }
  return 0;
}