#include <bits/stdc++.h>
#define il inline
#define Max 1000005
using namespace std;
int tot=1,n,m,s,t,d[Max],vst[Max],head[Max],q[2000005],cost=0;
struct node
{
	int t,nt,w,p;
}e[Max<<1];
struct path
{
	int fr,ed;
}pre[Max];
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
il void add(int u,int v,int w,int p)
{
	e[++tot].t=v;
	e[tot].nt=head[u];
	e[tot].w=w;
	e[tot].p=p;
	head[u]=tot;
}
il bool spfa()
{
	memset(vst,0,sizeof(vst));
	memset(pre,0,sizeof(pre));
	memset(d,0x3f3f3f3f,sizeof(d));
	int l=1,r=1;
	q[l]=s;
	vst[s]=1;
	d[s]=0;
	while(l<=r)
	{
		int u=q[l++];
		vst[u]=0;
		for(int i=head[u];i;i=e[i].nt)
		{
			int v=e[i].t;
			int w=e[i].p;
			if(d[v]>d[u]+w&&e[i].w)
			{
				d[v]=d[u]+w;
				pre[v].fr=u;
				pre[v].ed=i;
				if(!vst[v])
				{
					q[++r]=v;
					vst[v]=1;
				}
			}
		}
	}
	return d[t]!=0x3f3f3f3f;
}
il int ek()
{
	int flow=0;
	while(spfa())
	{
		int minn=0x3f3f3f3f;
		for(int i=t;i!=s;i=pre[i].fr)
			minn=min(minn,e[pre[i].ed].w);
		for(int i=t;i!=s;i=pre[i].fr)
		{
			e[pre[i].ed].w-=minn;
			e[pre[i].ed^1].w+=minn;
		}
		flow+=minn;
		cost+=minn*d[t];
	}
	return flow;
}
int main()
{
	n=read(),m=read(),s=read(),t=read();
	for(int i=1;i<=m;i++)
	{
		int u=read(),v=read(),w=read(),p=read();
		add(u,v,w,p),add(v,u,0,-p);
	}
	printf("%d ",ek());
	printf("%d",cost);
}
