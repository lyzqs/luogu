#include <bits/stdc++.h>
#define il inline
#define Max 100005
#define inf 0x3f3f3f3f
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
struct node
{
	int t,nt,w;
}e[Max<<1];
int n,m,sz[Max],head[Max],vst[Max],wsn[Max],qry[Max],ans[Max],s,c[Max],vis[10000005],q[Max],d[Max],tot,cnt,rt;
il void add(int u,int v,int w)
{
	e[++tot].t=v;
	e[tot].nt=head[u];
	e[tot].w=w;
	head[u]=tot;
}
il void getrt(int u,int fa)
{
	sz[u]=1;wsn[u]=0;
	for(int i=head[u];i;i=e[i].nt)
	{
		int v=e[i].t;
		if(v==fa||vst[v]) continue;
		getrt(v,u);
		sz[u]+=sz[v];
		wsn[u]=max(wsn[u],sz[v]);
	}
	wsn[u]=max(wsn[u],s-sz[u]);
	if(wsn[u]<wsn[rt]) rt=u;
}
il void getdis(int u,int fa)
{
	c[++cnt]=d[u];
	for(int i=head[u];i;i=e[i].nt)
	{
		int v=e[i].t,w=e[i].w;
		if(v==fa||vst[v]) continue;
		d[v]=d[u]+w;
		getdis(v,u);
	}
}
il void calc(int u)
{
	int p=0;
	for(int i=head[u];i;i=e[i].nt)
	{
		int v=e[i].t,w=e[i].w;
		if(vst[v]) continue;
		cnt=0;d[v]=w;
		getdis(v,u);
		for(int j=1;j<=cnt;j++)
			for(int k=1;k<=m;k++)
			{
				if(qry[k]>=c[j]&&vis[qry[k]-c[j]]) ans[k]=1;
			}
		for(int j=1;j<=cnt;j++)
			q[++p]=c[j],vis[c[j]]=1;
	}
	for(int i=1;i<=p;i++)
		vis[q[i]]=0;
}
il void dfs(int u)
{
	vst[u]=vis[0]=1;
	calc(u);
	for(int i=head[u];i;i=e[i].nt)
	{
		int v=e[i].t;
		if(vst[v]) continue;
		s=sz[v];wsn[rt=0]=inf;
		getrt(v,0);
		dfs(v);
	}
}
int main()
{
	//freopen("P3806.in","r",stdin);
	n=read(),m=read();
	for(int i=1;i<n;i++)
	{
		int u=read(),v=read(),w=read();
		add(u,v,w),add(v,u,w);
	}
	for(int i=1;i<=m;i++) qry[i]=read();
	wsn[rt]=s=n;
	getrt(1,0);
	dfs(rt);
	for(int i=1;i<=m;i++)
	{
		if(ans[i]) puts("AYE");
		else puts("NAY");
	}
}
