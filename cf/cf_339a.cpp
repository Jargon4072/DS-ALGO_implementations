#include<bits/stdc++.h>
using namespace std;

int main(){
  string str;
  int c;
  vector<int> vec;
  getline(cin,str);
  istringstream ss(str);
  while(ss>>c){
    vec.push_back(c);
  }
  sort(vec.begin(),vec.end());
  for(int i=0;i<vec.size()-1;i++){
    cout<<vec.at(i)<<"+";
  }
  cout<<vec.at(vec.size()-1)<<endl;
  //cout<<endl;
  return 0;

}
