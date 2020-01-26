#include<bits/stdc++.h>
using namespace std;
long long int arr[10000000];

void print_pendulam(long long int a[], long long int n){
  long long int arr1[100000];
  long long int mid=(n-1)/2;
  sort(a,a+n);
  arr1[mid]=a[0];
  long long int x=1,y=1;
  for(long long int i=1;i<n;i++){
    if((i%2)==0){
      arr1[mid-x]=a[i];
      x++;
    }
    else{
      arr1[mid+y]=a[i];
      y++;
    }
  }
  for(long long int i=0;i<n;i++){
    cout<<arr1[i]<<" ";
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
    print_pendulam(arr,n);
  }
}