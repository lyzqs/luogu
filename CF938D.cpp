#include <bits/stdc++.h>
#define il inline
#define Max 320005
#define ll long long
using namespace std;
ll head[Max],tot,m,n,s,d[Max],vst[Max];
struct node
{
	ll t,nt,w;
}e[Max<<1];
struct node2
{
	ll ww,nn;
};
bool operator < (node2 a,node2 b)
{
	return a.ww>b.ww;
}
il void add(ll u,ll v,ll w)
{
	e[++tot].t=v;
	e[tot].nt=head[u];
	e[tot].w=w;
	head[u]=tot;
}
il ll read()
{
	char c=getchar();
	ll x=0;
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
	n=read(),m=read();
	s=n+1;
	for(ll i=1;i<=m;i++)
	{
		ll u=read(),v=read(),w=read();
		add(u,v,2*w);
		add(v,u,2*w);
	}
	for(ll i=1;i<=n;i++)
	{
		ll w=read();
		add(s,i,w);
		//add(i,s,w);
	}
	priority_queue<node2> q;
	//memset(d,0x3f,sizeof(d));
	for(ll i=1;i<=n+1;i++) d[i]=1e18;
	d[s]=0;
	q.push((node2){0,s});
	while(!q.empty())
	{
		node2 qwq=q.top();
		q.pop();
		ll u=qwq.nn;
		if(d[u]!=qwq.ww||vst[u]) continue;
		vst[u]=1;
		for(ll i=head[u];i;i=e[i].nt)
		{
			ll v=e[i].t,w=e[i].w;
			if(d[v]>d[u]+w)
			{
				d[v]=d[u]+w;
				q.push((node2){d[v],v});
			}
		}
	}
	for(ll i=1;i<=n;i++) printf("%I64d ",d[i]);
}
