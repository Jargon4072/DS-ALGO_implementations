#include <bits/stdc++.h>
using namespace std;

int main() {

  int t;
  cin>>t;
  while(t--){
      string str;
      //getline(cin,str);
      cin>>str;
      int p=str.size();
      if(p>10){
        cout<<str[0]<<p-2<<str[p-1]<<endl;
      }
      else cout<<str<<endl;
  }
  return 0;
}
