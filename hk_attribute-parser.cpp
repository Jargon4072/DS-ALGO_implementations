#include <iostream>
#include <string>
#include <sstream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n,q;
  cin>>n>>q;
  int tp=n,p=q;
  string temp;
  vector<string> vect;
  vector<string> query;
  cin.ignore();
  while(tp--){
    getline(cin,temp);
    vect.push_back(temp);
  }
  while (p--) {
    getline(cin,temp);
    query.push_back(temp);
  }
  map<string,string> map1;
  vector<string> t;
  for(int i=0;i<n;i++){
    temp=vect[i];
    temp.erase(remove(temp.begin(),temp.end(),'\"'),temp.end());
    temp.erase(remove(temp.begin(),temp.end(),'>'),temp.end());
    if (temp.substr(0,2)=="</") {
      t.pop_back();
    }
    else{
      stringstream ss;
       ss.str("");
       ss<<temp;
       string t1,p1,v1;
       char ch;
       ss>>ch>>t1>>p1>>ch>>v1;
       string temp1="";
       if(t.size()>0)
       {
           temp1=*t.rbegin();
           temp1=temp1+"."+t1;
       }
       else
           temp1=t1;
       t.push_back(temp1);
       map1[*t.rbegin()+"~"+p1]=v1;
       while(ss)
       {
           ss>>p1>>ch>>v1;
           map1[*t.rbegin()+"~"+p1]=v1;
       }
    }
  }
  for(int i=0;i<q;i++){
    if (map1.find(query[i]) == map1.end())
        cout << "Not Found!\n";
    else
        cout<<map1[query[i]]<<endl;
}
return 0;
}
