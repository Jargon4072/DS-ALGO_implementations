#include<bits/stdc++.h>
#define ll long long
using namespace std;
char str[10000005];
int main(){
  ll n,m;
  cin>>n>>m;
  for(ll i=1;i<=n;i++){
    cin>>str[i];
  }
  while(m--){
    ll l,r;
    char c1,c2;
    cin>>l>>r>>c1>>c2;
    for(ll i=l;i<=r;i++){
      if(str[i]==c1){
        str[i]=c2;
      }
    }
  }
  for(ll i=1;i<=n;i++){
    cout<<str[i];
  }
  cout<<endl;
  return 0;
}