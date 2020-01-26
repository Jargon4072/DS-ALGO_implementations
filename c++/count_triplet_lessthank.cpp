#include<bits/stdc++.h>
using namespace std;

int triplet_count(int arr[], int n, int sum){
  sort(arr,arr+n);
  for(int i=0;i<n;i++){
    for(int j=i)
  }
}
int arr[1000005];
int main(){
  int n;
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  int sum;
  cin>>sum;
  int count=triplet_count(arr,n,sum);
  return count;
}