#include<bits/stdc++.h>
#define MAX 1000005
using namespace std;
void zerosumrect(int a[][],int n,int m){

}
int main(int argc, char const *argv[]) {
  int a[MAX][MAX];
  int n,m;
  cin>>n>>m;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      cin>>a[i][j];
    }
  }
  zerosumrect(a,n,m);
  return 0;
}
