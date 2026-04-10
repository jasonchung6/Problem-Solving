#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	string s1,s2,s;
	int a,b,c,mn=1e9,mx=0;
	while(n--){
		cin>>s>>a>>b>>c;
		int x=a+100*b+10000*c;
		if(x>mx) mx=x,s1=s;
		if(x<mn) mn=x,s2=s;
	}
	cout<<s1<<'\n'<<s2;
}