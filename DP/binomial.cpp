#include<bits/stdc++.h>
using namespace std;
int binom(int n,int k){
    int c[n+1][k+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=min(i,k);j++){
            if(j==0||j==i){
                c[i][j]=1;
            }
            else
                c[i][j]=c[i-1][j-1]+c[i-1][j];
        }
    }
    return c[n][k];
}

int main(){
    int n;
    int k;
    cin>>n;
    cin>>k;
    cout<<"C(n,k) is: "<<binom(n,k)<<endl;
    return 0;
}
