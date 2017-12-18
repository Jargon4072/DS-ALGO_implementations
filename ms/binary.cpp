#include<bits/stdc++.h>
using namespace std;
void binary(int n){
    int arr[1000005];
    int i=0;
    while(n){
        arr[i]=n%2;
        n=n/2;
        i++;
    }
    for(int j=i-1;j>=0;j--){
        cout<<arr[j]<<" ";
    }
    cout<<endl;
}
void binary1(int n){
    for(unsigned i=1<<31;i>0;i=i/2){
        (n&i)?cout<<"1 ":cout<<"0 ";
    }
}
void binary2(int n){
    if(n>1)
        binary2(n/2);
    cout<<n%2<<" ";
}
int main(){
    int n;
    cin>>n;
    binary2(n);
    return 0;
}
