//
// Created by krishna_warrior on 2/12/17.
//
#include<bits/stdc++.h>
using namespace std;

int main(){
    long long t;
    cin>>t;
    while(t--){
        long long n,m,s;
        cin>>n>>m>>s;
        long long size=(2*s)/(n+m);
        long long d=(m-n)/(size-5);
        long long a=(n-2*d);
        long long sum=a;
        cout<<size<<endl;
        for(int i=0;i<size;i++){
            cout<<sum<<" ";
            sum+=d;
        }
        cout<<endl;
    }
    return 0;
}
