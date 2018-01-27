#include<bits/stdc++.h>


using namespace std;

int main(){
  string str;
  vector<char> vec;
  cin>>str;

  transform(str.begin(), str.end(), str.begin(), ::tolower);
  //cout<<str<<endl;

  for(int i=0;i<str.size();i++){
    if(!(str[i]=='a'||str[i]=='e'||str[i]=='i'||str[i]=='o'||str[i]=='u'||str[i]=='y')){
      vec.push_back('.');
      vec.push_back(str[i]);
    }
  }
  for(int i=0;i<vec.size();i++) {
  	cout << vec[i];   // for printing the vector
  }
  cout<<endl;
  return 0;
}
