//find matrix with maximum stars around it
#include<bits/stdc++.h>
using namespace std;
map<char,int>m1;

int countstars(int mat[][4], int i, int j,int n,int m){
  //handle all 8 neighbours
  int count=0;
  int rnum[]={-1,-1,-1,0,0,1,1,1};
  int colnum[]={-1,0,1,-1,1,-1,0,1};   //note: this method is more good to find all eight neighbours.
  for(int k=0;k<8;k++){
    int p=i+rnum[k];
    int q=i+colnum[k];
    if(p>=0&&p<n&&q>=0&&q<m&&mat[p][q]=='*')
      count++;
  }
  return count;
}
char sol(int mat[][4], int n, int m){
  int max_num=INT_MIN;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      if(mat[i][j]!='*'){
        int p=countstars(mat,i,j,n,m);
        m1[mat[i][j]]=p;
        max_num=max(max_num,p);
      }
    }
  }
  int max=-1;
  char result='z'+1;
  for (auto x: m1){
    if(x.second>max ||(x.second==max)&& x.first<result){          //smart way to find maximum
      max=x.second;
      result=x.first;
    }
  }
  return result;
}

int main(){
  int mat[][4]= { { 'b', '*', '*', '*' },
                  { '*', '*', 'c', '*' },
                  { '*', 'a', '*', '*' },
                  { '*', '*', '*', 'd' } };
    cout<<sol(mat, 4,4)<<endl;

}