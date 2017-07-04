/*_______________________________________________________
|                                                        |
|      Author: Chandan Dwivedi                           |
|  'Life isn't about finding yourself.                   |
|          Life is about creating yourself.'             |
|_______________________________________________________*/

//program to evaluate a postfix expression.
#include<bits/stdc++.h>
using namespace std;

void postfixvalue(string s){
  stack<char> st;
  st.push('N');
  int l=s.length();
  string str;
  for(int i=0;i<l;i++){
    st.push(s[l-i-1]);       //special care! push in reverse order.
  }
  stack<int> x;
  while(st.top()!='N'){
    if(!(st.top()=='*'||st.top()=='/'||st.top()=='^'||st.top()=='+'||st.top()=='-')){    //when no operator.
      int y=st.top()-'0';       //convert to int.
      x.push(y);                  //push in stack
      st.pop();
    }
    else{
      int a=x.top();
      x.pop();
      int b=x.top();
      x.pop();
      char c=st.top();
      int z;
      switch(c){
        case '+':
                z=a+b;
                break;
        case '-':
                z=b-a;      //again the order should be b-a not a-b!.
                break;
        case '*':
                z=a*b;
                break;
        case '/':
                z=b/a;
        case '^':
                z=b^a;
                break;
        default :
                z=z*1;
      }
      x.push(z);
      st.pop();
    }

  }
  cout<<x.top();
}
int main(){
  string str;
  getline(cin,str);
  postfixvalue(str);
}
