#include<bits/stdc++.h>
using namespace std;
#define MAX 10000005
long long  arr[MAX];
long long  sumwindow(long long arr[],long long  n, long long k){
  long long sum=0;
  long long  ans=0;
  for(long long i=0;i<k;i++){
    sum+=arr[i];
  }
  long long window_sum=sum;
  ans+=sum;
  for(int i=k;i<n;i++){
    window_sum+=arr[i]-arr[i-k];
    ans+=window_sum;
  }
  return ans;
}
int main(){
  long long n,k;
  cin>>n>>k;
  string str;

  /*vector<int> vec;
  cin.ignore();
  getline(cin,str);
  istringstream ss(str);
  int c;

  while(ss>>c){
    vec.push_back(c);
  }
  for(int i=0;i<vec.size();i++){
    arr[i]=vec[i];
  }*/
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  if(n<k){
    return 0;
  }
  long long sum=sumwindow(arr,n,k);
  long double avg=(long double)sum/(n-k+1);
  cout<<fixed;
  cout<<setprecision(10);
  cout<<avg<<endl;
  return 0;

}
