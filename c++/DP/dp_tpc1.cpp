#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define max 100005
int main(){
  ll s,n,v[max];
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>v[i];
  }
  ll min[max]={INT_MAX};
  cin>>s;
  min[0]=0;
  for(int i=1;i<=s;i++){
    for(int j=0;j<n;j++){
      if(v[j]<=i && min[i-v[j]]+1<min[i]){
        min[i]=min[i-v[j]]+1;
        cout<<min[i];
      }
    }
  }
  cout<<min[s];
  return 0;
}