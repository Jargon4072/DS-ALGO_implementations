#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll power(string str){
  ll p=0,charge=1;
  for(ll i=0;i<str.length();i++){
    if(str[i]=='S')
      p+=charge;
    else if(str[i]=='C')
      charge+=charge;
  }
  return p;
}
ll counts(string str){
  int count=0;
  for(ll i=0;i<str.length();i++){
    if(str[i]=='S')
       count++;
  }
  return count;
}
ll swap(string str, ll a){
  ll count=0;
  while(power(str)>a){
    for(int i=0;i<str.length()-1;i++){
      if(str[i]=='C'&&str[i+1]=='S'){
        str[i]='S';
        str[i+1]='C';
        count++;
        break;
      }
    }
  }
  return count;
}
int main(){
  ll t;
  cin>>t;
  ll z=t;
  while(t--){
    string str;
    ll a;
    cin>>a;
    cin>>str;
    //cout<<a;
    //cout<<" "<<str;
    //cout<<"#"<<z-t<<":"<<power(str);
    ll p=power(str);
    if(p>a){
      if(counts(str)<=a){
        cout<<"Case #"<<z-t<<": "<<swap(str,a)<<endl;
      }
      else
        cout<<"Case #"<<z-t<<": IMPOSSIBLE"<<endl;
    }

    else
      cout<<"Case #"<<z-t<<": "<<"0"<<endl;

  }
  return 0;
}
