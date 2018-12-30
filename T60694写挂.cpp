#include <bits/stdc++.h>
#define il inline
#define Max 300005
#define ll long long
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
il int calc2(int x)
{
	int pre=x-(x%4),res=1;
	for(int i=pre;i<x;i++)
		res^=(i+i+1);
	return res;
}
il int calc(int l,int r)
{
	return calc2(r)^calc2(l-1);
}
int q,cnt;
struct node
{
	int l,r;
}e[Max];
il bool cmp(node x,node y)
{
	return x.l<y.l;
}
il int work()
{
	int res=0,nw=1,nl,nr;
	if(cnt)res^=calc(e[1].l,e[1].r);
	for(int i=2;i<=cnt;i++)
	{
		if(e[i].r<=e[i-1].r) continue;
	}
}
int main()
{
	q=read();
	if(q<=500)
	{
		while(q--)
		{
			int opt=read();
			if(opt==1)
			{
				e[++cnt].l=read();
				e[cnt].r=read();
			}
			if(opt==2)
			{
				sort(e+1,e+1+cnt,cmp);
				printf("%d\n",work());
			}
		}
	}
}
