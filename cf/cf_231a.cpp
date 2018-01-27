#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin>>t;
  int countf=0;
    while(t--){
      int m,n,q,count=0;
      cin>>m>>n>>q;
      if(m==1){
        count++;
      }
      if(n==1){
        count++;
      }
      if(q==1){
        count++;
      }
      if(count>=2){
        countf++;
      }
    }
    cout<<countf<<endl;
  return 0;
}
