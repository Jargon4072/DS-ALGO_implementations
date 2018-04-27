#include<bits/stdc++.h>
using namespace std;
#define MAX 1000005
int lcs(string str1,string str2,int n,int m){
    int f[n+1][m+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i==0||j==0){
                f[i][j]=0;
            }
            else if(str1[i-1]==str2[j-1]){
                f[i][j]=1+f[i-1][j-1];
            }
            else{
                f[i][j]=max(f[i-1][j],f[i][j-1]);
            }
        }
    }
    return f[n][m];
}
int main(){
    string str1;
    string str2;
    cin>>str1;
    cin>>str2;
    cout<<"lcs length is: "<<lcs(str1,str2,str1.length(),str2.length())<<endl;
    return 0;
}
