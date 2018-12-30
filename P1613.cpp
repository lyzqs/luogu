#include <bits/stdc++.h>
#define il inline
#define Max 5000005
using namespace std;
struct node
{
	int t,nt,w;
}e[Max<<1];
int head[Max],tot,d[60],vst[Max],n,m,f[60][60][65];
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
struct node2
{
	int ww,nn;
};
priority_queue<node2> q;
bool operator < (node2 a,node2 b)
{
	return a.ww>b.ww;
}
il void dij()
{
	memset(d,0x3f,sizeof(d));
	d[1]=0;
	q.push((node2){0,1});
	while(!q.empty())
	{
		node2 qwq=q.top();
		q.pop();
		int u=qwq.nn;
		if(qwq.ww!=d[u]||vst[u]) continue;
		vst[u]=1;
		for(int i=head[u];i;i=e[i].nt)
		{
			int v=e[i].t,w=e[i].w;
			if(d[v]>d[u]+w)
			{
				d[v]=d[u]+w;
				q.push((node2){d[v],v});
			}
		}
	}
}
int main()
{
	//freopen("P1613.in","r",stdin);
	memset(f,0,sizeof(f));
	memset(d,10,sizeof(d));
	n=read(),m=read();
	for(int i=1;i<=m;i++)
	{
		int u=read(),v=read();
		add(u,v,1);
		f[u][v][0]=1;
	}
	for(int k=1;k<=64;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int t=1;t<=n;t++)
			{
				for(int j=1;j<=n;j++)
				{
					if(f[i][t][k-1]&&f[t][j][k-1])
					{
						f[i][j][k]=1;
						add(i,j,1);
					}
				}
			}
		}
	}
	dij();
	/*
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
				*/
	cout<<d[n];
}
