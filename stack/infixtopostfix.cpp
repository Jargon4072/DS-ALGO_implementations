/*_______________________________________________________
|                                                        |
|      Author: Chandan Dwivedi                           |
|  'Life isn't about finding yourself.                   |
|          Life is about creating yourself.'             |
|_______________________________________________________*/

//code to convert infix to postfix.
#include<bits/stdc++.h>
using namespace std;
int prefop(char ch){           //function to check for precedence of operators.
  if(ch=='^')
  return 3;
  else if(ch=='*'||ch=='/')
  return 2;
  else if(ch=='+'||ch=='-')
  return 1;
  else
  return -1;
}
void infixtopostfix(string s){                //function to convert to postfix.
  stack<char> st;    // used only when there is operand or () for push.
  st.push('N');
  string str;
  int l=s.length();
  for (int i = 0; i < l; i++) {
    if((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z')){         //if scaned character is not a operator.
      str+=s[i];
    }
    else if(s[i]=='('){      //if '(' push it in stack.
      st.push(s[i]);
    }
    else if(s[i]==')'){
      while(st.top()!='N'&&st.top()!='('){
        char c=st.top();
        st.pop();
        str+=c;
      }
      if(st.top()=='('){           //pop '('
        char c=st.top();
        st.pop();
      }
    }
    else{                //if scanned character is a operator.
      while (st.top()!='N'&&prefop(s[i])<=prefop(st.top())) {
        char c=st.top();
        st.pop();
        str+=c;
      }
      st.push(s[i]);
    }
  }
  while(st.top()!='N'){          //pop remaining characters.
    char c=st.top();
    st.pop();
    str+=c;
  }
  cout<<str<<endl;
}
int main(){
  string input;
  cout<<"Enter infix string:";
  getline(cin,input);
  infixtopostfix(input);
  return 0;
}
