#include<bits/stdc++.h>
using namespace std;
void arr_subset_chk(int arr1[],int arr2[],int n,int m){
    if(m>n){
        cout<<"No"<<endl;
        return;
    }
    cout<<"";
    int count[100005]={0};
    for(int i=0;i<n;i++){
        count[arr1[i]]++;
    }
    for(int i=0;i<m;i++){
        if(count[arr2[i]]<1){
            cout<<"No"<<endl;
            return;
        }
    }
    cout<<"Yes"<<endl;
}
int main(){
    int n,m;
    int arr1[100005];
    int arr2[100005];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr1[i];
    }
    cin>>m;
    for(int i=0;i<m;i++){
        cin>>arr2[i];
    }
    arr_subset_chk(arr1,arr2,n,m);
    return 0;
}
