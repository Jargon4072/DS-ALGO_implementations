#include<bits/stdc++.h>
using namespace std;

int main(){
  long long t;
  cin>>t;
  while(t--){
    long long n,m;
    cin>>n;
    cin>>m;
    vector<long long > vec;
    long long p;
    for(long long i=0;i<2*m;i++){
      cin>>p;
      vec.push_back(p);
    }
    long long z=2*m;
    if((n-z)%2==0){
      cout<<"yes"<<endl;
    }
    else{
      cout<<"no"<<endl;
    }
  }
  return 0;
}
