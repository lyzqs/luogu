#include <bits/stdc++.h>
#define il inline
#define Max 500005
using namespace std;
struct node
{
	int t,nt,w;
}e[Max<<2];
int n,m,head[Max<<2],tot,d[Max<<2],vst[Max<<2],val[Max];
il void add(int u,int v,int w)
{
	e[++tot].t=v;
	e[tot].nt=head[u];
	e[tot].w=w;
	head[u]=tot;
}
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
il void spfa()
{
	memset(d,~0x3f,sizeof(d));
	d[1]=0;vst[1]=1;
	queue<int> q;
	q.push(1);
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
				if(!vst[v])q.push(v);
				vst[v]=1;
			}
		}
	}
}
int main()
{
	n=read(),m=read();
	for(int i=1;i<=n;i++) val[i]=read();
	for(int i=1;i<=m;i++)
	{
		int u=read(),v=read(),opt=read();
		add(u,v,0);
		add(u+n,v+n,0);
		add(u+n*2,v+n*2,0);
		add(u,v+n,-val[u]);
		add(u+n,v+n*2,val[u]);
		if(opt==2)
		{
			swap(u,v);
			add(u,v,0);
			add(u+n,v+n,0);
			add(u+n*2,v+n*2,0);
			add(u,v+n,-val[u]);
			add(u+n,v+n*2,val[u]);
		}
	}
	add(n,3*n+1,0);
	add(n*3,3*n+1,0);
	n=n*3+1;
	spfa();
	cout<<d[n];
}
