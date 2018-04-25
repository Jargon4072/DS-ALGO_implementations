#include<bits/stdc++.h>
using namespace std;
#define MAX 1000005
long long  arr[MAX];

int  main(){
  long long  n,w;
  cin>>n>>w;
  long long  half_sum=0;
    long long  arr1[MAX];
  for(long long  i=1;i<=n;i++){
    cin>>arr[i];
    arr1[i]=((arr[i]+1)/2);
    half_sum+=arr1[i];
  }


  if(half_sum>w){
    cout<<"-1"<<endl;
    return 0;
  }
  else{
    w-=half_sum;
    while (w) {
      long long  z=0;
      for (long long  i = 1; i <=n; i++) {
        if(arr1[i]<arr[i]&& arr[i]>arr[z]){
          z=i;
        }
      }
      arr1[z]++;
      w--;

    }
    for (long long  i = 1; i <=n; i++) {
      cout<<arr1[i]<<" ";

    }
    cout<<endl;
    return 0;
  }

}
