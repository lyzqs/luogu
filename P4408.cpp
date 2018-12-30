#include <bits/stdc++.h>
#define il inline
#define Max 200005
#define ll long long
using namespace std;
int head[Max],tot,n,m,vst[Max];
ll d1[Max],da[Max],db[Max],ans;
struct node
{
	int t,nt,w;
}e[Max<<1];
struct node2
{
	ll ww,nn;
};
bool operator < (node2 a,node2 b)
{
	return a.ww>b.ww;
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
il void add(int u,int v,int w)
{
	e[++tot].t=v;
	e[tot].nt=head[u];
	e[tot].w=w;
	head[u]=tot;
}
il int dij(int s,ll d[])
{
	for(int i=1;i<=n;i++) d[i]=1e18;
	memset(vst,0,sizeof(vst));
	d[s]=0;
	priority_queue<node2> q;
	q.push((node2){0,s});
	while(!q.empty())
	{
		node2 qwq=q.top();
		q.pop();
		int u=qwq.nn;
		if(d[u]!=qwq.ww||vst[u]) continue;
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
	int t=1;
	for(int i=1;i<=n;i++)
		if(d[i]>d[t]) t=i;
	return t;
}
int main()
{
	n=read(),m=read();
	for(int i=1;i<=m;i++)
	{
		int u=read(),v=read(),w=read();
		add(u,v,w);
		add(v,u,w);
	}
	int a=dij(1,d1);
	int b=dij(a,da);
	dij(b,db);
	ans=da[b];
	ll maxx=0;
	for(int i=1;i<=n;i++) maxx=max(maxx,min(da[i],db[i]));
	cout<<ans+maxx;
}
