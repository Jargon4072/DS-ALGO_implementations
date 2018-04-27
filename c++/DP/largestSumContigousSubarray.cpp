#include<bits/stdc++.h>
using namespace std;
int longestsum(int arr[],int n){
    int max_sum=arr[0];
    int curr_sum=arr[0];
    for (int i = 0; i < n; i++) {
        curr_sum=max(arr[i],curr_sum+arr[i]);
        max_sum=max(curr_sum,max_sum);
    }
    return max_sum;
}
int main(){
    int arr[1000005];
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"largest sum contigous subarray: "<<longestsum(arr,n)<<endl;
    return 0;
}
