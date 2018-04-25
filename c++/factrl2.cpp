#include<bits/stdc++.h>
using namespace std;
#define ll long long
 ll arr1[10000005];
 ll ans[10000005];
 ll n[10000005];
ll multiply(ll n[],ll size,ll m){
  ll carry=0;

  for(int i=0;i<size;i++){
    ll q=n[i]*m+carry;
    carry=q/10;
    arr1[i]=q%10;
  }

  while(carry){
    arr1[size]=carry%10;
    carry/=10;
    size=size+1;
  }
  for(int i=0;i<size;i++){
    n[i]=arr1[i];
  }
  return size;
}
void factorial(ll x){
  ll i=0;

  ll y=x;
  while(y>0){
    ans[i]=y%10;
    y=y/10;
    i++;
  }
  ll size=i;

  for(int i=0;i<size;i++){
    n[i]=ans[i];
  }
  for(int j=1;j<x;j++){
    size=multiply(n, size, j);
  }
  for(int i=0;i<size;i++){
    cout<<n[size-i-1];
  }

}
int main(){
  ll t;
  cin>>t;
  while(t--){
    ll n;
    cin>>n;
    factorial(n);
    cout<<endl;
  }
  return 0;
}
