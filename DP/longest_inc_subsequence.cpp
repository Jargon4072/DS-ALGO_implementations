#include<bits/stdc++.h>
using namespace std;
int lis(int arr[], int n, int *max){
    if(n==1)
        return 1;
    int ans,max_end=1;      //max_end is length of lis ending with arr[n-1]
    for(int i=1;i<n;i++){
        ans=lis(arr,i,max);
        if(arr[i-1]<arr[n-1] && ans+1>max_end){
            max_end=ans+1;
        }
    }
    if(*max<max_end)
        *max=max_end;
    return max_end;
}
int lis_arr(int arr[],int n){
    int max=1;
    lis(arr,n,&max);
    return max;
}
int main(){
    int n;
    cin>>n;
    int arr[1000005];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<lis_arr(arr,n)<<endl;
    return 0;
}
