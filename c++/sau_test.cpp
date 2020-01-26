#include<bits/stdc++.h>
using namespace std;


void printrev(int a[],int n,int d){
  for(int i=0;i<n;i+=d){
    int l=i;
    int r=min(n-1,i+d-1);
    while(l<r){
      int temp=a[l];
      a[l]=a[r];
      a[r]=temp;
      l++;
      r--;
    }
  }
  for(int i=0;i<n;i++){
    cout<<a[i]<<" ";
  }
  //for(int i=z;i<n;i++){
  //  cout<<a[n-i-1]<<" ";
  //}
  cout<<endl;
}
int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n,d;

	    cin>>n>>d;
	 int a[n];
	    for(int i=0;i<n;i++)
	    { cin>>a[i];}

	    printrev(a,n,d);	}
	return 0;
}