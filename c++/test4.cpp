
#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  int a[n];
  for(int i=0;i<n;i++)
  cin>>a[i];
  int f=1;
  int s1=0,s2=0;
  for(int i=0;i<n/2;i++){
    if(a[i]>a[n-1-i]){
      if(f==1){
        s1+=a[i];f=0;}
        else{
          s2+=a[i]; f=1;}
}
else
{
 if(f==1)
{ s1+=a[n-1-i];f=0;}
else
{s2+=a[n-1-i]; f=1;}

}}

cout<<s1<<" "<<s2<<endl;

return 0;
}
