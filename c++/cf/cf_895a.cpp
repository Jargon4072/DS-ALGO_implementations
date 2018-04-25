#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll arr[10000005];
int main(){
  ll n;
  cin>>n;
  for(ll i=0;i<n;i++){
    cin>>arr[i];
  }
  ll mid=1;
  ll min=INT_MAX;
  while(mid<=n){
  ll ans;
  ll sum=0;
  for(ll i=0;i<mid;i++){
    sum+=arr[i];
  }
  ans=(360-sum)>sum?((360-sum)-sum):(sum-(360-sum));
  if(ans<=min){
    min=ans;
  }
  for(ll i=mid;i<n;i++){
    sum-=arr[i-mid];
    sum+=arr[i];
    ans=(360-sum)>sum?((360-sum)-sum):(sum-(360-sum));
    if(ans<min){
      min=ans;
    }
  }
  mid++;
}
  cout<<min<<endl;
  return 0;
}