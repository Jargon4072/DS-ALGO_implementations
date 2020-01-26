#include<bits/stdc++.h>
using namespace std;

int res(int sum, int x, int y, int z){
  int dp[1000005];
  if(sum<1){
    return 0;
  }
  dp[0]=1;
  dp[n]=solve(sum-x)+solve(sum-y)+solve(sum-z);
}

int main(){
  int x,y,z;
  cin>>x>>y>>z;
  int sum;
  cin>>sum;
  cout<<res(sum,x,y,z);
  return 0;
}