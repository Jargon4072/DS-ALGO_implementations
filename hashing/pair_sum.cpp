#include <iostream>
#include<bits/stdc++.h>
using namespace std;

void pair_sum(int arr1[],int arr2[],int n,int m,int sum){
    int count[1000005]={0};
    for(int i=0;i<m;i++){
        count[arr2[i]]++;
    }
    map<int,int> M;
    for(int i=0;i<n;i++){
        if(count[sum-arr1[i]]>=1){
        	M.insert(pair<int,int> (arr1[i],sum-arr1[i]));
        }
    }
    map<int,int> :: iterator it;
    for(it=M.begin();it!=M.end();it++){
    	cout<<it->first<<" "<<it->second;
    	if(it!=--M.end()){
    		cout<<", ";
    	}
    }
}
int main() {
    int t;
    cin>>t;
    while(t--){
    	int n,m;
        int arr1[100005];
        int arr2[100005];
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
        pair_sum(arr1,arr2,n,m,sum);
        cout<<endl;
    }

	return 0;
}
