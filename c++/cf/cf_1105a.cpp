#include<bits/stdc++.h>
using namespace std;

int a[1000005];
int main(int argc, char const *argv[]) {
  int n;
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  int min=INT_MAX;
  int val=0;
  for(int i=1;i<101;i++){
    int cost=0;
    for(int j=0;j<n;j++){
      if(a[j]-i>1 && i<a[j]){
        cost+=a[j]-i-1;
      }
      else if(i>a[j] && i-a[j]>1){
        cost+=i-a[j]-1;
      }
      else{
        continue;
      }
    }
    if(min>cost){
      min=cost;
      val=i;
    }

  }
  cout<<val<<" "<<min<<endl;

  return 0;
}