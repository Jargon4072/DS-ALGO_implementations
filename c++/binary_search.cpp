/*---------------------------------
Program to search an element in a
array using binary binary search

time complexity: O(log(n))

Auther: Chandan Dwivedi
email: chandandwivedi795@gmail.com
___________________________________*/

#include<bits/stdc++.h>
using namespace std;
int arr[10000005];

int it_binary_search(int arr[],int l,int r,int k){              //this is a iterative apporach
  int mid=l+(r-1)/2;
  while(l<=r){
    if(arr[mid]==k)
      return mid;
    else if(k<arr[mid]){
      r=mid-1;
    }
    else
      l=mid+1;
  }
  return -1;
}

int rec_binary_search(int arr[], int l, int r, int k){         //this is a recursive approach
  if(l<=r){
    int mid=l+(r-1)/2;
    if(arr[mid]==k)
      return mid;
    else if(k<arr[mid])
      r=mid-1;
    else
      l=mid+1;

    return rec_binary_search(arr,l,r,k);
  }
  return -1;
}

int main(){
  int n;
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  int k;
  cin>>k;
  cout<<rec_binary_search(arr,0,n-1,k)<<endl;
  return 0;
}