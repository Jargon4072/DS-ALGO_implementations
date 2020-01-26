#include<bits/stdc++.h>
using namespace std;
map<long long int,long long int> dp;
int solve(int n){
  if(n<12)
  return n;
  if(dp[n])
    return dp[n];
  return dp[n]=solve(n/2)+solve(n/3)+solve(n/4);
}

int main(){
  long long int n;
  while(cin>>n){
    cout<<solve(n)<<endl;
  }
  return 0;
}