#include <bits/stdc++.h>
#define Max 100006
#define il inline
using namespace std;
int n,tot,ans[Max],dfn[Max],s[Max],ins[Max],top=1,cnt,clr,c[Max],sz[Max],low[Max],head[Max],nxt[Max];
struct node
{
	int t,nt;
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
il void add(int u,int v)
{
	e[++tot].t=v;
	e[tot].nt=head[u];
	head[u]=tot;
}
il void tarjan(int u)
{
	dfn[u]=low[u]=++cnt;
	s[top]=u;
	top++;
	ins[u]=1;
	for(int i=head[u];i;i=e[i].nt)
	{
		int v=e[i].t;
		if(!ins[v])
		{
			tarjan(v);
			low[u]=min(low[u],low[v]);
		}
		else if(ins[v]==1) low[u]=min(low[u],dfn[v]);
	}
	if(dfn[u]==low[u])
	{
		clr++;
		do
		{
			top--;
            c[s[top]]=clr;
            ins[s[top]]=-1;
		}while(s[top]!=u);
	}
	return;
}
il void dfs(int rt,int x,int st)
{
	if(ans[x])
	{
		ans[rt]=ans[x]+st;
		return;
	}
	else dfs(rt,nxt[x],st+1);
}
int main()
{
	//freopen("P2921.in","r",stdin);
	n=read();
	int qwq;
	for(int i=1;i<=n;i++) {qwq=read();nxt[i]=qwq;add(i,qwq);if(i==qwq) ans[i]=1;}
	for(int i=1;i<=n;i++) if(!ins[i]) tarjan(i);
	for(int i=1;i<=n;i++) sz[c[i]]++;
	for(int i=1;i<=n;i++) if(sz[c[i]]!=1) ans[i]=sz[c[i]];
	for(int i=1;i<=n;i++) if(!ans[i]) dfs(i,nxt[i],1);
	for(int i=1;i<=n;i++) printf("%d\n",ans[i]);
}
