#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
  ll n;
  ll ans=0;
  string str;
  cin>>str;
  ll m=str.size();
  ll p=stoi(str);
  if(m==1){
    ans=1;
  }
  else{
    ll f1=str[0]-'0';
    ans=(f1+1)*(pow(10,m-1))-p;
  }
  cout<<ans<<endl;
  return 0;
}
