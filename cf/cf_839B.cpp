#include<bits/stdc++.h>
using namespace std;


int main(){
    int n,k;
    int a[1000005];
    cin>>n;
    cin>>k;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int sum=8*n;
    for(int i=0;i<n;i++){
        while(sum>=0){
            if(a[i]>=4){
                sum-=4;
                a[i]=a[i]-4;
            }
        }
    }
}
