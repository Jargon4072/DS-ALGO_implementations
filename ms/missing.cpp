#include<bits/stdc++.h>
using namespace std;
void missing(int arr[],int n){
    int sum=((n+1)*(n+2))/2;
    for(int i=0;i<n;i++){
        sum-=arr[i];
    }
    cout<<sum<<endl;
}
int main(){
    int n;
    cin>>n;
    int arr[1000005];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    missing(arr,n);
    return 0;
}
