#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,q;
    cin>>n;
    cin>>q;
    long long *arr=new long long[n+1]();
    while(q--){
        int a,b,k;
        cin>>a;
        cin>>b;
        cin>>k;
        arr[a]+=k;
        if(b+1<=n)
            arr[b+1]-=k;
    }
    int x=0;
    int max=0;
    for(int i=1;i<=n;i++){
        x=x+arr[i];
        if(max<x)
            max=x;
    }
    cout<<max<<endl;
    return 0;
}
