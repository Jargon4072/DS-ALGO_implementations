/**
 * @Author: Dwivedi Chandan
 * @Date:   2019-05-13T23:39:59+05:30
 * @Email:  chandandwivedi795@gmail.com
 * @Last modified by:   Dwivedi Chandan
 * @Last modified time: 2019-05-14T12:04:43+05:30
 */



#include<bits/stdc++.h>
using namespace std;

int min_stones(string str){
  long long int plus=0,minus=0;     //integer to keep count of + and -
  long long int initial=0;
  for(long long int i=0;i<str.size();i++){
    if(str[i]=='+')
      plus++;       // plus count
    else
      minus++;       //minus count
  }
  long long int start_minus=0;            //integer to count minus occured in start
  if(str[0]=='-'){
    for(long long int i=0;i<str.size();i++){
      if(str[i]=='-')
        start_minus++;        //start minuses count
      else
        break;
    }
  }
  long long int pmdiff=0;      //integer to count difference in no of + and -
  if(minus>plus)
    pmdiff=minus-plus;
  if(pmdiff>start_minus){             //if start minuses are greater than difference
    initial=pmdiff;                //intail count of stones count
  }
  else
    initial=start_minus;

  for(long long int i=0;i<str.size();i++){        //loop to perform activity on initial value
    if(str[i]=='-'){
      initial--;
      if(initial<0)
        initial=0;
    }
    else
      initial++;
  }
  return initial;

}

int main(){
  long long int n;
  cin>>n;
  string str;
  cin.ignore();
  getline(cin,str);
  cout<<min_stones(str)<<endl;
  return 0;
}