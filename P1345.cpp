#include <bits/stdc++.h>
#define il inline
#define Max 2005
#define inf 0x3f3f3f3f
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
	int t,nt,w;
}e[Max<<1];
int head[Max],tot=1,n,m,s,t,vst[Max],d[Max];
il void add(int u,int v,int w)
{
	e[++tot].t=v;
	e[tot].nt=head[u];
	e[tot].w=w;
	head[u]=tot;
}
queue<int> q;
il bool bfs()
{
	memset(d,0x3f,sizeof(d));
	while(!q.empty()) q.pop();
	q.push(s);
	d[s]=0;
	while(!q.empty())
	{
		//cout<<"qwq\n";
		int u=q.front();
		q.pop();
		for(int i=head[u];i;i=e[i].nt)
		{
			int v=e[i].t,w=e[i].w;
			if(d[v]==inf&&w)
			{
				d[v]=d[u]+1;
				q.push(v);
				if(v==t) return 1;
			}
		}
	}
	return 0;
}
il int dfs(int u,int flow)
{
	//cout<<"qwq\n";
	if(u==t) return flow;
	for(int i=head[u];i;i=e[i].nt)
	{
		int v=e[i].t,w=e[i].w,res;
		if((d[v]==d[u]+1)&&(w))
		{
			res=dfs(v,min(w,flow));
			if(!res) continue;
			e[i].w-=res;
			e[i^1].w+=res;
			return res;
		}
	}
	return 0;
}
il int dinic()
{
	int res=0,flw;
	while(bfs())
	{
		while((flw=dfs(s,inf)))
			res+=flw;
	}
	return res;
}
int main()
{
	//freopen("P1345.in","r",stdin);
	n=read(),m=read();s=read(),t=read();
	s+=n;
	for(int i=1;i<=n;i++)
	{
		add(i,i+n,1);
		add(i+n,i,0);
	}
	for(int i=1;i<=m;i++)
	{
		int u=read(),v=read();
		add(u+n,v,inf);
		add(v+n,u,inf);
	}
	printf("%d\n",dinic());
}
