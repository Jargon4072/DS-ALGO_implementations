#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin>>n;
  vector<int> vec;
  cin.ignore();
  string str;
  getline(cin,str);
  int p;
  istringstream ss(str);
  while(ss>>p){
    vec.push_back(p);
  }
  int sum=0;
  for(int i=0;i<vec.size();i++){
    sum+=vec[i];
  }
  int sum1=0;
  int z=0;
/*  for(int i=0;i<vec.size();i++){
    sum1+=vec[i];
    if(sum1>((sum+1)/2)){
      z=i;
      break;
    }
  }
  int flag=0;
  for(int i=0;i<=z;i++){
    if(sum1-vec[i]==(sum+1)/2){
      flag=1;
      break;
    }
  }*///wrong implementation............
  if(flag==1){
    cout<<"YES"<<endl;
  }
  else {
    cout<<"NO"<<endl;
  }
  return 0;
}
