#include<bits/stdc++.h>
using namespace std;
#define ll long long
bool isprime(ll n){
  if(n!=2&&n!=3){
    if(n%2==0||n%3==0){
      return false;
    }
    for(ll i=5;i<=sqrt(n);i++){
      if(n%i==0){
        return false;
      }
    }
  }
  return true;
}
void print_prime(ll n,ll m){
  for(ll i=n;i<=m;i++){
    if(isprime(i)&&i!=1){
      cout<<i<<endl;
    }
  }
}
int main(){
  ll t;
  cin>>t;
  while(t--){
    ll n,m;
    cin>>n>>m;
    print_prime(n,m);
    cout<<endl;
  }
  return 0;
}