#include<bits/stdc++.h>
using namespace std;

int main(){
  int m,n,p,rem,ans;
  cin>>m>>n;
  if(m==1||n==1){
    if(m==1){
      ans=n/2;
    }
    else ans=m/2;
  }
  else{
  if(m%2==0||n%2==0){
  if(m%2==0){
    ans=(m/2)*n;
  }
  else{
    ans=(n/2)*m;
  }

}
else{
  ans=(m/1)*(n/2)+m/2;
}
}
cout<<ans<<endl;
return 0;
}
