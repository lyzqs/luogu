#include <bits/stdc++.h>
#define il inline
#define Max 505
using namespace std;
il int read()
{
	char c=getchar();
	int x=0;
	while(c>'9'||c<'0') c=getchar();
	while(c>='0'&&c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return x;
}
int n,h[Max];
priority_queue<int>h1;
priority_queue<int,vector<int>,greater<int> >h2;
long long ans=0;
int main()
{
	n=read();
	for(int i=1;i<=n;i++) h[i]=read(),h1.push(h[i]),h2.push(h[i]);
	int nw=0;
	for(int i=1;i<=n;i++)
	{
		if(i&1)
		{
			int to=h1.top();
			h1.pop();
			ans+=(nw-to)*(nw-to);
			nw=to;
		}
		else
		{
			int to=h2.top();
			h2.pop();
			ans+=(nw-to)*(nw-to);
			nw=to;
		}
	}
	cout<<ans;
}
