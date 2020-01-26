/**
 * @Author: Dwivedi Chandan
 * @Date:   2019-07-28T15:00:55+05:30
 * @Email:  chandandwivedi795@gmail.com
 * @Last modified by:   Dwivedi Chandan
 * @Last modified time: 2019-07-28T15:15:39+05:30
 */



#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	getline(cin,s);
	cout<<"entered str: "<<s<<endl;
	char a;
	int l=s.length();
	stack<char>st;
	int i;
	for(i=l-1;i>=0;i--){
		//cout<<s[i];
	//	cout<<"inside for"<<endl;
		if(s[i]==' ')
		{
		//	cout<<"inside if"<<endl;
			while(!st.empty()){

				cout<<st.top();
				st.pop();

			}
			cout<<" ";
		}
		else
		st.push(s[i]);
	}
	while(!st.empty())
	{
		cout<<st.top();
	  st.pop();
 }
	return 0;
}