#include<bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin>>t;
  int x=0;
  while(t--){

    string str;
    cin>>str;
    if(str[0]=='+'){
      ++x;
    }
    if(str[0]=='-'){
      --x;
    }
    if(str[2]=='+'){
      x++;
    }
    if(str[2]=='-'){
      x--;
    }

  }
  cout<<x<<endl;
  return 0;
}
