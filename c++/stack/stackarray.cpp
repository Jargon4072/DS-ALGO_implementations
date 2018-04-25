/*_______________________________________________________
|                                                        |
|      Author: Chandan Dwivedi                           |
|  'Life isn't about finding yourself.                   |
|          Life is about creating yourself.'             |
|_______________________________________________________*/

//code to implement stack with array.
#include<bits/stdc++.h>
using namespace std;
#define MAX 10000
class Stack{                    //s must be in capital i.e. 'S' in stack. can you tell me why?
  int top;
public:
  int a[MAX];
  Stack(){
    top=-1;
  }
  bool push(int x);
  int pop();
  bool isempty();
};
bool Stack::push(int x){
  if(top>=MAX){
    cout<<"Stack overflow"<<endl;
    return false;
  }
  else{
    top=+1;
    a[top]=x;
    return true;
  }
}
bool Stack::isempty(){
  if(top<0){
    return true;
  }
  else{
    return false;
  }

}
int Stack::pop(){
  if(top<0){
    cout<<"Stack underflow"<<endl;
    return 0;
  }
  int x= a[top--];
  return x;
}
int main(){
  struct Stack s;
  string str;
  int p;
  getline(cin,str);
  istringstream stream(str);
  while(stream>>p){
    s.push(p);
  }
  if(s.isempty()){
    cout<<"empty Stack!"<<endl;
  }
  cout<<s.pop()<<"popped from Stack."<<endl;
}
