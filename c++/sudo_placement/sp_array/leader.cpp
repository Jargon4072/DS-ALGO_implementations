#include<bits/stdc++.h>
using namespace std;
long long int arr[10000000];

void print_leaders(long long int a[], long long int n){
  vector<long long int> max_ele;
  long long int max=INT_MIN;
  for(long long int i=n-1;i>=0;i--){
    if(a[i]>max){
      max=a[i];
    }
    max_ele.push_back(max);
  }
  ///cout<<"vector output: ";
  ///for(int i=0;i<n;i++){
    //cout<<max_ele[i]<<" ";
  //}
  //cout<<endl;
  for(long long int i=0;i<n;i++){
    if(a[i]==max_ele[n-i-1]){
      cout<<a[i]<<" ";
    }
  }
  cout<<endl;
}
int main(){
  long long int t;
  cin>>t;
  while(t--){
    long long int n;
    cin>>n;
    for(long long int i=0;i<n;i++){
      cin>>arr[i];
    }
    print_leaders(arr,n);
  }
}