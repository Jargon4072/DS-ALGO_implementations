#include<bits/stdc++.h>
using namespace std;
int main(){
	int ans[1<<20],i;
	char s[1<<20];
	scanf("%s",s);
	int n=strlen(s),l=0,r;
	r=n-1;
	for(int i=0;i<n;i++){
		if(s[i]=='l')
			ans[r--]=i+1;
		else ans[l++]=i+1;
	}
	for(int i=0;i<n;i++)
		printf("%d ",ans[i]);
	return 0;
}