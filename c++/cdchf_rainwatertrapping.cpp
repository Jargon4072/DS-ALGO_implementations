#include<bits/stdc++.h>
using namespace std;

long long int arr[10000005];
long long int max_water(long long int arr[],long long int n){
  long long int left[n];
  long long int right[n];
  long long int water=0;
  left[0]=arr[0];
  for(long long int i=1;i<n;i++){
    left[i]=max(arr[i],left[i-1]);
  }
  right[n-1]=arr[n-1];
  for(long long int i=n-2;i>=0;i--){
    right[i]=max(right[i+1],arr[i]);
  }
    for(long long int i=0;i<n;i++){
      water+=min(left[i],right[i])-arr[i];
    }
    return water;
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
    cout<<max_water(arr,n)<<endl;
  }
}