#include<bits/stdc++.h>
using namespace std;
int uglyno(int n){
    int ugly[n];
    ugly[0]=1;
    int next_ugly_no=1;
    int i=0,j=0,k=0;
    int next_multiple_of2=ugly[i]*2;
    int next_multiple_of3=ugly[j]*3;
    int next_multiple_of5=ugly[k]*5;
    for(int p=1;p<n;p++){
        next_ugly_no=min(next_multiple_of2,min(next_multiple_of5,next_multiple_of3));
        ugly[p]=next_ugly_no;
        if(next_ugly_no==next_multiple_of2){
            i=i+1;
            next_multiple_of2=ugly[i]*2;
        }
        if(next_ugly_no==next_multiple_of3){
            j=j+1;
            next_multiple_of3=ugly[j]*3;
        }
        if(next_ugly_no==next_multiple_of5){
            k=k+1;
            next_multiple_of5=ugly[k]*5;
        }
    }
    return next_ugly_no;
}
int main(){
    int n;
    cin>>n;
    cout<<uglyno(n)<<endl;
}
