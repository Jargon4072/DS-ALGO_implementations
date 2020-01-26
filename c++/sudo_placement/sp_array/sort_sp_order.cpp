#include<bits/stdc++.h>
using namespace std;
long long int arr[1000000];

int main(){
  long long int t;
  cin >>t;

  while(t--){
    long long int n;
    cin>>n;
    for(long long int i=0;i<n;i++){
      cin>>arr[i];
      if(arr[i]%2!=0){
        arr[i]*=-1;
      }
    }
    sort(arr,arr+n);
    for(long long int i=0;i<n;i++){
      if(arr[i]<0){
        arr[i]*=-1;
      }
      cout<<arr[i]<<" ";
    }
    cout<<endl;
  }
}