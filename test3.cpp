#include <iostream>
#include<bits/stdc++.h>
using namespace std;

void pair_sum(int arr1[],int arr2[],int n,int m,int sum){
	cout<<"";
    int count[1000005]={0};
    for(int i=0;i<m;i++){
        count[arr2[i]]++;
    }
    cout<<"";
    for(int i=0;i<n;i++){
        if(count[sum-arr1[i]]>=1){
            cout<<arr1[i]<<" "<<sum-arr1[i];
            if(i!=n-1){
                cout<<",";
            }
        }
    }
}
int main() {
    int t;
    while(t--){
    	int n,m;
        int arr1[1000005];
        int arr2[1000005];
        cin>>n;
        cin>>m;
        int sum;
        cin>>sum;
        for(int i=0;i<n;i++){
        	int p;
            cin>>p;
            arr1[i]=p;
        }
         for(int i=0;i<m;i++){
         	int z;
            cin>>z;
            arr2[i]=z;
        }
         for(int i=0;i<n;i++){
            cout<<arr1[i]<<" ";
        }
        cout<<endl;
        for(int i=0;i<m;i++){
            cout<<arr2[i]<<" ";
        }
        //pair_sum(arr1,arr2,n,m,sum);
        cout<<endl;
    }

	return 0;
}
