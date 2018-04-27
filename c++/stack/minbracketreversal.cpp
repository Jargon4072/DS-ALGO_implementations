/*_______________________________________________________
|                                                        |
|      Author: Chandan Dwivedi                           |
|  'Life isn't about finding yourself.                   |
|          Life is about creating yourself.'             |
|_______________________________________________________*/

//program to find minimum reversal of brackets needed to make a expression balanced.
#include<bits/stdc++.h>
using namespace std;

int minrevbracket(string str){
  stack<char> st;
  int l=str.length();
  st.push('N');

  for(int i=0;i<l;i++){
    st.push(str[l-i-1]);
  }
  stack<char> x;
    x.push('N');
  while(st.top()!='N'){
    if(st.top()=='{'){       //if '{' push in x.
      char c=st.top();
      st.pop();
      x.push(c);
    }
    else if(st.top()=='}'&&x.top()=='{'){       //if {{{}}} case pop from both st and x.
      st.pop();
      x.pop();
    }
    else if(st.top()=='}'&&x.top()!='{'){      //if }}} case push in x.
      char c=st.top();
      x.push(c);
      st.pop();
    }
  }
  int count1=0;
  int count2=0;
  while(x.top()!='N'){
    if(x.top()=='{'){
      count1++;
    }
    else if(x.top()=='}'){
      count2++;
    }
    x.pop();
  }
  return ((count1+count2)/2+ count1%2);          //result is ((count of {)+(count of })/2) + (count of {)%2.
}
int main(){
  string str;
  getline(cin,str);
  int p=minrevbracket(str);
  cout<<p<<endl;
  return 0;
}
