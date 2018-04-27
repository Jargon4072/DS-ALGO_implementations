#include<bits/stdc++.h>
using namespace std;

int main(){
  long long t;
  cin>>t;

  while(t--){
    long long p;
    long long z=0;
    cin>>p;
      cin.ignore();
      string str;
      getline(cin,str);
      istringstream stream(str);
      long long q;
      vector<long long> vec;
      while(stream>>q){
        vec.push_back(q);
      }
      if(p%2==0){
        z=1;
      }
      vector<long long> vec1;
      vec1=vec;
      reverse(vec1.begin(),vec1.end());
      /*for(long long i=1;i<=vec.size()/2;i++){
        if((vec[i]-vec[i-1])!=1){
          z=1;
          break;
        }
      }
      for(long long i=vec.size()/2;i<vec.size();i++){
        if((vec[i]-vec[i+1])!=1){
          z=1;
          break;
        }
      }*/
      //cout<<"size: "<<vec.size()<<endl;
      for(int j=0;j<(vec.size()+1)/2;j++){
        if(vec[j]!=j+1 || vec[j]!=vec[(vec.size())-j-1]){
          z=1;
          break;
        }
      }
      if(z==1){
        cout<<"no"<<endl;
      }
      else{
        cout<<"yes"<<endl;
      }

  }
  return 0;
}
