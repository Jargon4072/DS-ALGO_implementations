#include<bits/stdc++.h>
using namespace std;
long long a[10000005];
long long candy_day(long long a[],long long n,long long k){
    long long sum=0;
    long long count=0;
    long long num=0;
    for(long long i=0;i<n;i++){
        a[i]=a[i]+num;
        if(k>sum){
            sum+=(a[i]>8)?8:a[i];
            num=a[i]-((a[i]>8)?8:a[i]);
            count=i+1;
        }
        else{
            break;
        }

    }
    if(k>sum)
        return -1;
    return count;
}

int main(){
    long long n,k;
    cin>>n;
    cin>>k;
    for(long long i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<candy_day(a,n,k)<<endl;
    return 0;
}
