#include<bits/stdc++.h>
using namespace std;
char s[1000][1000];
int n,m;

int count_bomb(int i,int j){
  int count=0;
  for(int p=i-1;p<=i+1;p++){
    for(int q=j-1;q<=j+1;q++){
      if(s[p][q]=='*')
        count++;
    }
  }
  return count;
}

int main(int argc, char const *argv[]) {
  cin>>n>>m;
  for(int i=0;i<n;i++){
    cin>>s[i];
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      if(s[i][j]!='*'&&count_bomb(i,j)!=(s[i][j]=='.'?0:s[i][j]-'0')){
         cout<<"NO"<<endl;
         return 0;
      }
    }
  }
  cout<<"YES"<<endl;
  return 0;
}
