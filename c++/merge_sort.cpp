/**
 * @Author: Dwivedi Chandan
 * @Date:   2020-01-26T18:33:59+05:30
 * @Email:  chandandwivedi795@gmail.com
 * @Last modified by:   Dwivedi Chandan
 * @Last modified time: 2020-01-26T23:21:18+05:30
 */



#include<bits/stdc++.h>
using namespace std;

void merge(int arr[],int l,int m,int r){
  int larr[100005];
  int rarr[100005];
  int x,y,k;
  for(int i=0;i<m-l+1;i++){
    larr[i]=arr[l+i];
  }
  for(int j=0;j<r-m;j++){
    rarr[j]=arr[j+m+1];
  }

  x=0;
  y=0;
  k=l;
  while(x<m-l+1 && y<r-m){
    if(larr[x]>=rarr[y]){
      arr[k]=larr[x];
      x++;
    }
    else{
      arr[k]=rarr[y];
      y++;
    }
    k++;
  }
  while(x<m-l+1){
    arr[k]=larr[x];
    x++;
    k++;
  }
  while(y<r-m){
    arr[k]=rarr[y];
    y++;
    k++;
  }
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l+(r-l)/2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);

        merge(arr, l, m, r);
    }
}

void mergesort(int arr[], int n){
  int s=0;
  int l=n-1;
  mergeSort(arr,s,l);
}

int main(){
  int arr[100005];
  int n;
  cin>>n;
  for (int i =0;i<n;i++){
    cin>>arr[i];
  }
  mergesort(arr,n);
  for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
  }
  cout<<endl;
}