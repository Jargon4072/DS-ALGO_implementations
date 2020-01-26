/**
 * @Author: Dwivedi Chandan
 * @Date:   2019-09-09T12:48:47+05:30
 * @Email:  chandandwivedi795@gmail.com
 * @Last modified by:   Dwivedi Chandan
 * @Last modified time: 2019-09-10T12:16:40+05:30
 */

#include<bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    vector<int> fibo=fibo(n);
    for(int i=0;i<fibo.size();i++){
      fibo[i]=fibo[i]%10;
    }
    while(fibo.size()>1){
      RemoveOdd(*fibo)
    }
    cout<<fibo[0]<<endl;
  }
  return 0;
}