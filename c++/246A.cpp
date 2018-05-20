#include<bits/stdc++.h>
using namespace std;
long long arr[10000005];
int main(){
    //string str;
    char str[1000005];
    //getline(cin,str);
    scanf("%s",str);
    long long start=0,n=strlen(str),end=n-1;
    for(long long i=0;i<n;i++){
        if(str[i]=='l'){
            arr[end--]=i+1;
        }
        else{
            arr[start++]=i+1;
        }
    }
    for(long long i=0;i<n;i++){
        //cout<<arr[i]<<endl;
        printf("%lld\n",arr[i]);
    }
    return 0;
}
