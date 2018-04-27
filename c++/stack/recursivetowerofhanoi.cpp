#include<bits/stdc++.h>
using namespace std;

void recursivetowerofhanoi(int n, char sourcerod, char auxrod, char destrod){
  if(n==1){
    cout<<"move disk 1 from rod "<<sourcerod<<" to "<<destrod<<endl;
    return;
  }
  recursivetowerofhanoi(n-1,sourcerod,destrod,auxrod);
    cout<<"move disk "<<n<<" from rod "<<sourcerod<<" to "<<destrod<<endl;
  recursivetowerofhanoi(n-1,auxrod,sourcerod,destrod);
}

int main(){
  int n;
  cin>>n;
  recursivetowerofhanoi(n,'S','A','D');
  return 0;
}
