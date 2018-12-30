#include <bits/stdc++.h>
#define il inline
#define Max 10005
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
}e[Max<<1];
int head[Max],cl,id[Max],vst[Max],tot,cnt,dfn[Max],low[Max],n,m,s[Max],top;
il void add(int u,int v)
{
	e[++tot].t=v;
	e[tot].nt=head[u];
	head[u]=tot;
}
il void tarjan(int u,int fa)
{
	s[++top]=u;
	vst[u]=1;
	dfn[u]=low[u]=++cnt;
	for(int i=head[u];i;i=e[i].nt)
	{
		int v=e[i].t;
		if(v==fa) continue;
		if(!dfn[v])
		{
			tarjan(v,u);
			low[u]=min(low[u],low[v]);
		}
		else low[u]=min(low[u],low[v]);
	}
	if(dfn[u]==low[u])
	{
		cl++;
		while(19260817)
		{
			int v=s[top--];
			vst[v]=0;
			id[v]=cl;
			if(v==u) break;
		}
	}
}
il void dfs(int u,int lst)
{
	printf("%d ",u);
	vst[u]=1;
	priority_queue<int,vector<int>,greater<int> > q;
	for(int i=head[u];i;i=e[i].nt)
	{
		if(!vst[e[i].t])
		q.push(e[i].t);
	}
	while(!q.empty())
	{
		if(!vst[q.top()])
		{
			int v=q.top();
			q.pop();
			while(vst[q.top()]) q.pop();
			if(id[v]==id[lst]&&lst<v&&!vst[lst])
			{
				return;
			}
			else dfs(v,q.top());
		}
		else q.pop();
	}
}
int main()
{
	n=read(),m=read();
	for(int i=1;i<=m;i++)
	{
		int u=read(),v=read();
		add(u,v),add(v,u);
	}
	for(int i=1;i<=n;i++)
	{
		if(!dfn[i]) tarjan(i,0);
	}
	memset(vst,0,sizeof(vst));
	dfs(1,Max-1);
}
