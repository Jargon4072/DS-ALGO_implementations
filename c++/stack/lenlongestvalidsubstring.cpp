/*_______________________________________________________
|                                                        |
|      Author: Chandan Dwivedi                           |
|  'Life isn't about finding yourself.                   |
|          Life is about creating yourself.'             |
|_______________________________________________________*/

//program to find longest valid substring of ().
#include<bits/stdc++.h>
using namespace std;
/*int lenlongvalsubstr(string s){    //this function is working for exp of type (((())) but not of type ()((())).will check later.
  stack<char> st;              */  //TODO: check this function for expression like ()(()))))
  /*int l=s.length();
  string str;
  st.push('N');
  for(int i=0;i<l;i++){      //push given string in stack st in reverse order.
    st.push(s[l-i-1]);
  }
  stack<char> x;
  x.push('N');
  int count=0;
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
    count=count+2;
  }
}
return count;
}*/
int lenlongvalsubstr(string s){   //function to find length of substr.
  stack<int> st;
  st.push(-1);
  int l=s.length();
  int result=0;
  for(int i=0;i<l;i++){
    if(s[i]=='('){
      st.push(i);
    }
    else{
      st.pop();
      if(!st.empty())
      result=max(result,i-st.top());

      else st.push(i);
    }
  }
  return result;
}
int main(){
  int ans;
  string str;
  getline(cin,str);
  ans=lenlongvalsubstr(str);
  cout<<"length is: "<<ans<<endl;
}
