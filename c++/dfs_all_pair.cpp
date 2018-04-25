#include<bits/stdc++.h>
using namespace std;
void combutil(vector<int>& temp, vector<vector<int>>& ans,int arr[],int n,int k){
  if(k==0){
    ans.push_back(temp);
    return;
  }
  for(int i=0;i<n;i++){
    temp.push_back(arr[i]);
    combutil(temp, ans, arr, n, k-1);
    temp.pop_back();
  }
}
vector<vector<int>> comb(int arr[],int n,int k){
  vector<int> temp;
  vector<vector<int>> ans;
  combutil(temp,ans,arr,n,k);
  return ans;
}
int main(){
  int n;
  int arr[1000005];
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  vector<int> vec;
  vector<vector<int>> ans;
  ans=comb(arr,n,2);
  for(int i=0;i<ans.size();i++){
    for(int j=0;j<ans[i].size();j++){
        cout<<ans[i][j]<<" ";
    }
    cout<<endl;
  }
  return 0;
}