#include <bits/stdc++.h>
#define il inline
#define Max 1000005
using namespace std;
typedef long long ll;
struct node
{
	ll t,nt;
}e[Max<<1];
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
ll n,rt,f[Max],vst[Max],w[Max],g[Max][2],ans,tot,head[Max];
il void add(int u,int v)
{
	e[++tot].t=v;
	e[tot].nt=head[u];
	head[u]=tot;
}
il void dfs(ll u)
{
	vst[u]=1;
	g[u][1]=w[u];
	g[u][0]=0;
	for(int i=head[u];i;i=e[i].nt)
	{
		ll v=e[i].t;
		//cout<<v<<endl;
		if(v!=rt)
		{
			dfs(v);
			g[u][0]+=max(g[v][0],g[v][1]);
			g[u][1]+=g[v][0];
		}
		else g[v][1]=-1e18;
		//cout<<v<<endl;
	}
}
il void find(ll u)
{
	vst[u]=1;
	rt=u;
	while(!vst[f[rt]])
	{
		rt=f[rt];
		vst[rt]=1;
		//cout<<"qwq\n";
	}
	dfs(rt);
	ll t=max(g[rt][0],g[rt][1]);
	vst[rt]=1;
	rt=f[rt];
	dfs(rt);
	ans+=max(t,max(g[rt][0],g[rt][1]));
}
int main()
{
	n=read();
	for(int i=1;i<=n;i++)
	{
		w[i]=read();
		ll v=read();
		f[i]=v;
		//add(i,v);
		add(v,i);
	}
	for(int i=1;i<=n;i++)
	{
		if(!vst[i]) find(i);
	}
	cout<<ans;
}
