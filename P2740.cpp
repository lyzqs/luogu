#include <bits/stdc++.h>
#define il inline
#define Max 1005
using namespace std;
int n,m,d[Max],head[Max],q[10000005],s,t,tot=1;
struct node
{
	int t,nt,w;
}e[Max<<1];
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
	e[++tot].w=w;
	e[tot].t=v;
	e[tot].nt=head[u];
	head[u]=tot;
}
il bool bfs()
{
	memset(d,0x3f3f3f3f,sizeof(d));
	d[s]=0;
	int l=1,r=1;
	q[l]=s;
	while(l<=r)
	{
		int u=q[l++];
		for(int i=head[u];i;i=e[i].nt)
		{
			int v=e[i].t;
			if(d[v]>d[u]+1&&e[i].w)
			{
				d[v]=d[u]+1;
				q[++r]=v;
			}
		}
	}
	return d[t]!=0x3f3f3f3f;
}
il int dfs(int u,int low)
{
	int l=0;
	if(u==t) return low;
	for(int i=head[u];i;i=e[i].nt)
	{
		int v=e[i].t;
		if(e[i].w&&d[v]==d[u]+1)
		{
			if(l=dfs(v,min(low,e[i].w)))
			{
				e[i].w-=l;
				e[i^1].w+=l;
				return l;
			}
		}
	}
	return 0;
}
il int dinic()
{
	int flow,maxflow=0;
	while(bfs())
	{
		while(flow=dfs(s,0x3f3f3f3f)) maxflow+=flow;
	}
	return maxflow;
}
int main()
{
	n=read(),m=read();
	s=1;t=m;
	for(int i=1;i<=n;i++)
	{
		int u=read(),v=read(),w=read();
		add(u,v,w),add(v,u,0);
	}
	printf("%d",dinic());
}
