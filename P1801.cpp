#include <bits/stdc++.h>
#define il inline
#define Max 200005
using namespace std;
il int read()
{
	char c=getchar();
	int x=0,f=1;
	while(c>'9'||c<'0') 
	{
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
priority_queue<int> h2;
priority_queue<int,vector<int>,greater<int> > h1;
int n,m,a[Max],b[Max];
int main()
{
	n=read(),m=read();
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=m;i++) b[i]=read();
	int j=1;
	for(int i=1;i<=m;i++)
	{
		for(;j<=b[i];j++)
		{
			h1.push(a[j]);
		}
		int qwq=h1.top();
		h1.pop();
		h2.push(qwq);
		while(!h1.empty()&&h1.top()<h2.top())
		{
			int t=h1.top();
			qwq=h2.top();
			h1.pop(),h2.pop();
			h1.push(qwq);
			h2.push(t);
		}
		printf("%d\n",h2.top());
	}
}
