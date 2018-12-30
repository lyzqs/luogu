#include <bits/stdc++.h>
#define il inline
#define Max 100005
using namespace std;
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
struct node
{
	int t,nt;
}e[Max<<1],e2[Max<<1];
int dfn[Max],low[Max],d[Max],f[Max][25],head[Max],head2[Max],vst[Max],s[Max],id[Max],top,cnt,cl,n,m,tot,q,uu[Max],vv[Max];
il void add(int u,int v)
{
	e[++tot].t=v;
	e[tot].nt=head[u];
	head[u]=tot;
}
il void add2(int u,int v)
{
	e2[++tot].t=v;
	e2[tot].nt=head2[u];
	head2[u]=tot;
}
il void tarjan(int u,int fa)
{
	dfn[u]=low[u]=++cnt;
	s[++top]=u;
	vst[u]=1;
	for(int i=head[u];i;i=e[i].nt)
	{
		int v=e[i].t;
		if(v==fa) continue;
		if(!dfn[v])
		{
			tarjan(v,u);
			low[u]=min(low[u],low[v]);
		}
		else if(vst[v]) low[u]=min(low[u],dfn[v]);
	}
	if(low[u]==dfn[u])
	{
		cl++;
		while(19260817)
		{
			top--;
			int v=s[top+1];
			//cout<<v<<' '<<cl<<"qwq\n";
			id[v]=cl;
			if(v==u) break;
		}
	}
}
il void rebuild()
{
	tot=0;
	for(int i=1;i<=m;i++)
	{
		if(id[uu[i]]!=id[vv[i]])
			add2(id[uu[i]],id[vv[i]]),add2(id[vv[i]],id[uu[i]]);
	}
}
il void dfs(int u,int fa)
{
	d[u]=d[fa]+1;
	f[u][0]=fa;
	for(int i=1;i<=20;i++)
		f[u][i]=f[f[u][i-1]][i-1];
	for(int i=head2[u];i;i=e2[i].nt)
	{
		int v=e2[i].t;
		if(v==fa) continue;
		dfs(v,u);
	}
}
il int lca(int u,int v)
{
	if(d[u]<d[v]) swap(u,v);
	for(int i=20;i>=0;i--)
	{
		if(d[f[u][i]]>=d[v]) u=f[u][i];
	}
	if(u==v) return u;
	for(int i=20;i>=0;i--)
	{
		if(f[u][i]!=f[v][i])
			u=f[u][i],v=f[v][i];
	}
	return f[u][0];
}
void print(int ans) 
{
    if(!ans) return;
    print(ans>>1);
    printf("%d",ans&1);
}
int main()
{
	n=read(),m=read();
	for(int i=1;i<=m;i++)
	{
		uu[i]=read(),vv[i]=read();
		add(uu[i],vv[i]);
		add(vv[i],uu[i]);
	}
	for(int i=1;i<=n;i++)
	{
		if(!dfn[i]) tarjan(i,0);
		//cout<<i<<' '<<id[i]<<endl;
	}
	rebuild();
	dfs(1,0);
	q=read();
	while(q--)
	{
		int u=read(),v=read();
		u=id[u];v=id[v];
		int ans=d[u]+d[v]-(d[lca(u,v)]<<1)+1;
		//cout<<d[u]<<' '<<d[v]<<' '<<lca(u,v)<<' '<<d[lca(u,v)]<<"qwq\n";
		print(ans);
		cout<<endl;
	}
}
