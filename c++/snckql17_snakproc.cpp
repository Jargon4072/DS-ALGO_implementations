#include<bits/stdc++.h>
using namespace std;

int main(){
  long long t;
  cin>>t;
  while(t--){
    long long p;
    cin>>p;
    string str;
    vector<string> vec;
    cin.ignore();
    getline(cin,str);
    vec.push_back(str);
    long long countt=0;
    long long counth=0;
    long long t=0;
    long long h=0;
    long long z=1;
    string str1="HT";
    for(long long i=0;i<str.size();i++){
      if(str[i]==str1[1]){
        countt++;
        t++;
        h=0;

      }
      if(str[i]==str1[0]){
        counth++;
        h++;
        t=0;
      }
      if(countt>=1&&counth==0){
         z=0;
        break;
      }
      if(t>1||h>1){
          z=0;
        break;
      }
    }
    if(countt!=counth||z==0){
      cout<<"Invalid"<<endl;
      z=0;
    }else{
    if(z==1/*&& (!(countt>=1&&counth==0))*/){
    cout<<"Valid"<<endl;
  }
}
  }
  return 0;
}
