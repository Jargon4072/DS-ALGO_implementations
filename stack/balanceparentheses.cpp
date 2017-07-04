/*_______________________________________________________
|                                                        |
|      Author: Chandan Dwivedi                           |
|  'Life isn't about finding yourself.                   |
|          Life is about creating yourself.'             |
|_______________________________________________________*/

//program to check for balanced parenthesis using stack.
#include<bits/stdc++.h>
using namespace std;

void balanceparentheses(string s){
  stack<char> st;
  int l=s.length();
  string str;
  st.push('N');
  for(int i=0;i<l;i++){      //push given string in stack st in reverse order.
    st.push(s[l-i-1]);
  }
  stack<char> x;
  x.push('N');
  while(st.top()!='N'){

    if(st.top()=='('||st.top()=='{'||st.top()=='['){    //if {,( or [ push in stack x;
      char c=st.top();
      x.push(c);
      st.pop();
    }
    else{                           //if ),} or ] then check the x.top() for respective closing brackets.
      char c=st.top();

      switch(c){
        case ')':
                if(x.top()=='{'||x.top()=='[')
                cout<<"Unbalanced."<<endl;
                break;
        case '}':
                if(x.top()=='('||x.top()=='[')
                cout<<"Unbalanced."<<endl;
                break;

        case ']':
                if(x.top()=='{'||x.top()=='(')
                cout<<"Unbalanced."<<endl;
                break;
      }
    st.pop();
    x.pop();
  }
}
if(st.top()=='N'){
  cout<<"Balanced."<<endl;
}
}
int main(){
  string str;
  getline(cin,str);
  balanceparentheses(str);
  return 0;
}
