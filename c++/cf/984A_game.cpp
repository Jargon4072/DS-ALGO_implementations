#include<bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]) {
  long long int n;
  cin>>n;
  long long int arr[1000005];
  for (long long int i = 0; i < n; i++) {
    cin>>arr[i];
  }
  sort(arr,arr+n);
  long long int q=n-1;
  long long int p=0;
  for(long long int i=1;i<n;i++){
    if(i%2!=0){
      q--;
    }
    else p++;
  }
  cout<<arr[p]<<endl;
  return 0;
}
