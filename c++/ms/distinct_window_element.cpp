#include<bits/stdc++.h>
using namespace std;
void distinct(int arr[],int n,int k){
    map<int,int> m;
    int ans=0;
    //int count[1000005]={0};
    //int z=0;
    for(int i=0;i<k;i++){
        if(m[arr[i]]==0){
            ans++;
        }
        m[arr[i]]+=1;
    }
    cout<<ans<<" ";
    for(int i=k;i<n;i++){
        if(m[arr[i-k]]==1){
            ans--;
        }
        m[arr[i-k]]-=1;
        if(m[arr[i]]==0){
            ans++;
        }
        m[arr[i]]+=1;
        cout<<ans<<" ";
    }
    cout<<endl;
}
int main(){
    int arr[1000005];
    int n;
    int k;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cin>>k;
    distinct(arr,n,k);
    return 0;
}
