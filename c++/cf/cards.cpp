#include<bits/stdc++.h>
using namespace std;

int main(){
	 int n;
	 string s;
	 cin>>n>>s;
	 int  z,k=0;
	 for(int i=0;i<n;i++){if(s[i]=='n') 
	k++;
	else if(s[i]=='z')
		z++;
	else continue;
	 }
	for(int i=0;i<k;i++)
		cout<<k<<" ";
for(int i=0;i<z;i++)
		cout<<z<<" ";
	return 0;
}