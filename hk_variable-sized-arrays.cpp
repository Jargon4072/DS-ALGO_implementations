#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
  int n,q;
  cin>>n>>q;
  vector<vector<int>> arrvect;
  int i=0;
  arrvect.resize(n);
  while (n--) {
    int k;
    cin>>k;
    arrvect[i].resize(k);
    for(int j=0;j<k;j++)
    {
      cin>>arrvect[i][j];
    }
    i++;
  }
  while(q--){
    int x,y;
    cin>>x>>y;
    cout<<arrvect[x][y]<<endl;

  }
  return 0;
}
