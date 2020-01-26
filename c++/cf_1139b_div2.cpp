#include<bits/stdc++.h>
using namespace std;
long long int arr[10000005];
long long int choclate(long long int arr[], long long int n){
  long long sum=arr[n-1];
  long long x=arr[n-1];
  for(long long int i=n-2;i>=0;i--){
    if(x==1){
      break;
    }
    //x=min(x-1,arr[i]);
    if(x-1<=arr[i]){
      sum+=x-1;
      x=x-1;
    }
    else{
      sum+=arr[i];
      x=arr[i];
    }
  }
  return sum;
}

int main(){
  long long int n;
  cin>>n;
  for(long long int i=0;i<n;i++){
    cin>>arr[i];
  }
  cout<<choclate(arr,n);

}