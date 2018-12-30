#include <bits/stdc++.h>
#define il inline
#define lowbit(x) (x&-x)
using namespace std;
int n,m,f[20000005];
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
il void add(int x,int y)
{
	while(x<=n)
	{
		f[x]+=y;
		x+=lowbit(x);
	}
}
il int get(int x)
{
	int res=0;
	while(x>0)
	{
		res+=f[x];
		x-=lowbit(x);
	}
	return res;
}
int main()
{
	n=read(),m=read();
	int opt;
	for(int i=1;i<=m;i++)
	{
		opt=read();
		if(opt==0)
		{
			add(read(),1);
			add(read()+1,-1);
		}
		else printf("%d\n",get(read()));
	}
}
