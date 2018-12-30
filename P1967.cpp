#include <bits/stdc++.h>
#define il inline
#define Max 500005
#define inf 0x3f3f3f3f
using namespace std;
int n,m,f[Max],tot,head[Max],cnt=0,d[Max],p[Max][30],wt[Max][30];
struct node
{
	int t,nt,w;
}e[Max<<1];
struct edge
{
	int u,v,w;
}ed[Max];
il int find(int x)
{
	if(x==f[x]) return x;
	else return f[x]=find(f[x]);
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
il bool cmp(edge a,edge b)
{
	return a.w>b.w;
}
il void add(int u,int v,int w)
{
	e[++tot].t=v;
	e[tot].nt=head[u];
	head[u]=tot;
	e[tot].w=w;
}
il void kru()
{
	for(int i=1;i<=n;i++) f[i]=i;
	for(int i=1;i<=m;i++)
	{
		int u=find(ed[i].u);
		int v=find(ed[i].v);
		int w=ed[i].w;
		if(u==v)continue;
		f[u]=v;
		add(u,v,w);
		add(v,u,w);
	}
}
il void dfs(int u,int fa)
{
	d[u]=d[fa]+1;
	p[u][0]=fa;
	for(int i=1;(1<<i)<=d[u];i++)
	{
		p[u][i]=p[p[u][i-1]][i-1];
		wt[u][i]=min(wt[u][i-1],wt[p[u][i-1]][i-1]);
	}
	for(int i=head[u];i;i=e[i].nt)
	{
		int v=e[i].t;
		if(v==fa) continue;
		wt[v][0]=e[i].w;
		dfs(v,u);
	}
}
il int lca(int u,int v)
{
	if(find(u)!=find(v)) return -1;
	int ans=inf;
	if(d[u]>d[v]) swap(u,v);
	for(int i=20;i>=0;i--)
	{
		if(d[p[v][i]]>=d[u])
		{
			ans=min(ans,wt[v][i]);
			v=p[v][i];
		}
	}
	if(u==v) return ans;
	for(int i=20;i>=0;i--)
	{
		if(p[u][i]!=p[v][i])
		{
			ans=min(ans,min(wt[u][i],wt[v][i]));
			u=p[u][i],v=p[v][i];
		}
	}
	ans=min(ans,min(wt[u][0],wt[v][0]));
	return ans;
}
int main()
{
	n=read(),m=read();
	for(int i=1;i<=m;i++)
	{
		ed[i].u=read(),ed[i].v=read(),ed[i].w=read();
	}
	sort(ed+1,ed+1+m,cmp);
	kru();
	memset(wt,inf,sizeof(wt));
	for(int i=1;i<=n;i++) if(!d[i]) dfs(i,d[i]);
	int q=read();
	while(q--)
	{
		int u=read(),v=read();
		printf("%d\n",lca(u,v));
	}
}
