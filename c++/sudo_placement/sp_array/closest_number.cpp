#include<bits/stdc++.h>
using namespace std;
long long int arr[10000000];

int main(){
  long long int t;
  cin>>t;
  while(t--){
    long long int n,k;
    cin>>n>>k;
    long long int m=INT_MAX;
    long long int dif,val;
    for(long long int i=0;i<n;i++){
      cin>>arr[i];
      dif=arr[i]>k?arr[i]-k:k-arr[i];
      if(dif==m){
        val=arr[i]>val?arr[i]:val;
      }
      else{
        if(dif<m){
          m=dif;
          val=arr[i];
        }
      }
    }
    cout<<val<<endl;
  }
}
