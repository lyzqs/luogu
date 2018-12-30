#include <bits/stdc++.h>
#define ll long long
#define il inline
#define Max 500005
using namespace std;
ll n,m,s,head[Max],tot=0,size=0,vst[Max],d[Max],inque[Max],qwq;
struct node
{
	int t,nt;
	ll w;
}e[Max<<1];
struct heap
{
	ll v,num;
	bool operator <(const heap& x) const
	{
		return v>x.v;
	}
};
priority_queue<heap> q;
il void add(ll u,ll v,ll w)
{
	e[++tot].t=v;
	e[tot].nt=head[u];
	e[tot].w=w;
	head[u]=tot;
}
il ll read()
{
	ll x=0;
	char c=getchar();
	while(c>'9'||c<'0') c=getchar();
	while(c>='0'&&c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return x;
}
int main()
{
	freopen("1.in","r",stdin);
	n=read(),m=read(),s=1;qwq=read();
	memset(d,0x3f3f3f3f,sizeof(d));
	d[s]=0;
	for(int i=1;i<=m;i++)
	{
		int u=read(),v=read(),w=1;
		add(u,v,w);add(v,u,w);
	}
	q.push((heap){0,s});
	while(!q.empty())
	{
		heap k=q.top();q.pop();
		ll u=k.num,dis=k.v;
		if(d[u]!=dis) continue;
		for(int i=head[u];i;i=e[i].nt)
		{
			ll v=e[i].t,w=e[i].w;
			if(d[u]+w<d[v])
			{
				d[v]=d[u]+w;
				q.push((heap){d[v],v});
			}
		}
	}
	for(int i=1;i<=qwq;i++)
	{
		int u=read(),v=read();
		printf("%d\n",d[v]);
	}
}
