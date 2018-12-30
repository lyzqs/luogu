#include <bits/stdc++.h>
#define il inline
#define inf 0x3f3f3f3f
#define Max 500005
using namespace std;
struct node
{
	int t,nt,w;
}e[Max];
int head[Max],tot,n,m,vst[Max],d[Max];
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
il void add(int u,int v,int w)
{
	e[++tot].t=v;
	e[tot].nt=head[u];
	e[tot].w=w;
	head[u]=tot;
}
int main()
{
	m=read();
	for(int i=1;i<=m;i++)
	{
		int u=read(),v=read(),w=read();
		n=max(u,max(v,n));
		add(u-1,v,w);
	}
	for(int i=1;i<=n;i++)
	{
		add(i,i-1,-1);
		add(i-1,i,0);
	}
	queue<int> q;
	memset(d,-inf,sizeof(d));
	d[0]=0;q.push(0);
	vst[0]=1;
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		vst[u]=0;
		for(int i=head[u];i;i=e[i].nt)
		{
			int v=e[i].t,w=e[i].w;
			if(d[v]<d[u]+w)
			{
				d[v]=d[u]+w;
				if(!vst[v]) q.push(v),vst[v]=1;
			}
		}
	}
	cout<<d[n];
}
