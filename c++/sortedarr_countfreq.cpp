/**
 * @Author: Dwivedi Chandan
 * @Date:   2019-04-21T13:46:59+05:30
 * @Email:  chandandwivedi795@gmail.com
 * @Last modified by:   Dwivedi Chandan
 * @Last modified time: 2019-04-21T23:02:12+05:30

  program to count frequency of each element in a sorted array.
 */

#include<bits/stdc++.h>
using namespace std;
void count_freq_utils(int arr[], int l,int r,vector<int>& freq){
    if(arr[l]==arr[r]){
      freq[arr[l]]=r-l+1;
    }
    else{
      int mid=(l+r)/2;
      count_freq_utils(arr,l,mid,freq);
      count_freq_utils(arr,mid+1,r, freq);
    }
}

void count_freq(int arr[],int n){
  vector<int> freq(arr[n-1]+1,0);   //creates a vector of size arr[n-1]+1 with all values as zero.
  count_freq_utils(arr,0,n-1,freq);

  for(int i=0;i<=arr[n-1];i++){   //TODO: use map insted of vector here.
    if(freq[i]!=0){
      cout<<i<<"comes "<<freq[i]<<"times"<<endl;
    }
  }
}

int arr[10000005];

int main(){
  int n;
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  cout<<freq_arr(arr,n);
}