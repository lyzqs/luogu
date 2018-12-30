#include <bits/stdc++.h>
#define ll long long
#define Max 1000005
#define il inline
using namespace std;
ll n,m,ans,head[Max],vst[Max],to[Max],tot;
struct node
{
	ll t,nt;
}e[Max];
il ll read()
{
	char c=getchar();
	ll x=0,num=1;
	while(c>'9'||c<'0')
	{
		if(c=='-') num=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return x*num;
}
il void add(ll u,ll v)
{
	e[++tot].t=v;
	e[tot].nt=head[u];
	head[u]=tot;
}
il bool dfs(ll u)
{
	for(ll i=head[u];i;i=e[i].nt)
	{
		ll v=e[i].t;
		if(!vst[v])
		{
			vst[v]=1;
			if(!to[v]||dfs(to[v]))
			{
				to[v]=u;
				return true;
			}
		}
	}
	return false;
}
int main()
{
	n=read(),m=read();
	ll x=read(),y=read();
	while(x!=-1&&y!=-1)
	{
		add(x,y);
		add(y,x);
		x=read(),y=read();
	}
	for(ll i=1;i<=n;i++)
	{
		memset(vst,0,sizeof(vst));
		if(dfs(i)) ans++;
	}
	printf("%lld\n",ans);
	for(ll i=n+1;i<=m;i++)
	{
		if(to[i]) printf("%lld %lld\n",to[i],i);
	}
}
