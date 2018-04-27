#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll zcy(ll val){
  ll p=val;
  while(val>0){
    ll q=val%10;
    p=p*10+q;
    val/=10;
  }
  return p;
}
int main(){
  ll k,p;
  cin>>k>>p;
  ll sum=0;
  for(ll i=1;i<=k;i++){
    sum=(sum+zcy(i))%p;
  }
  cout<<sum<<endl;
  return 0;
}