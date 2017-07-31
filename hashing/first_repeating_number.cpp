#include<bits/stdc++.h>
using namespace std;

void first_repeating(int arr[],int n){
    int count[1000005]={0};
    int p;
    for(int i=0;i<n;i++){
        count[arr[i]]++;
        if(count[arr[i]]>1){
            p=i;
            break;
        }
    }
    cout<<arr[p]<<endl;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    first_repeating(arr,n);
    return 0;
}
