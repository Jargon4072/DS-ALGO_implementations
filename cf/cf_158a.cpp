#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,k;
  cin>>n>>k;
  vector<int> vec;
  cin.ignore();
  string str;
  getline(cin,str);
  int p;
  istringstream stream(str);
  while(stream>>p){
    vec.push_back(p);
  }
  int count=0;
  int c=0;

  if((k!=n)){
  for (int i = k; i < n; i++) {
    if((vec.at(i)==vec.at(k-1))&& !(vec.at(k-1)==0 && vec.at(i)==0))
    {
      c++;
    }
  }}
  for(int i=0; i<k;i++){
    if((vec.at(i)>=vec.at(k-1))&& !(vec.at(k-1)==0 && vec.at(i)==0)){
      count++;
    }
  }
  cout<<count+c<<endl;
  return 0;
}
