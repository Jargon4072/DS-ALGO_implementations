#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,m;
  vector<int> vec;
  string str;
  getline(cin,str);
  istringstream ss(str);
  while(ss>>m){
    vec.push_back(m);
  }
  cout<<vec.at(1)<<endl;
  cout<<vec[1]<<endl;
  return 0;
}
