#include<bits/stdc++.h>
using namespace std;
void max_diff(int arr[],int n){
    
}

int main(){
    int arr[1000005];
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=0;i<n;i++){
            int p;
            cin>>p;
            arr[i]=p;
        }
        max_diff(arr,n);
    }
    return 0;
}
