#include <bits/stdc++.h>
#define il inline
#define ll long long
#define Max 1000005
using namespace std;
struct node
{
    int t,nt,w;
}e[Max<<1];
int head[Max],tot=1,d[Max],n,s;
ll ans=0;
il int read()
{
    char c=getchar();
    int x=0,f=1;
    while(c>'9'||c<'0')
    {
        if(c=='-') f=-1;
        c=getchar();
    }
    while(c<='9'&&c>='0')
    {
        x=x*10+c-'0';
        c=getchar();
    }
    return x*f;
}
il void add(int u,int v,int w)
{
    e[++tot].t=v;
    e[tot].nt=head[u];
    e[tot].w=w;
    head[u]=tot;
}
il void dfs(int u,int fa)
{
    for(int i=head[u];i;i=e[i].nt)
    {
        int v=e[i].t;
        if(v==fa) continue;
        dfs(v,u);
    }
    for(int i=head[u];i;i=e[i].nt)
    {
        int v=e[i].t,w=e[i].w;
        if(v==fa) continue;
        d[u]=max(d[u],w);
    }
    for(int i=head[u];i;i=e[i].nt)
    {
    	int v=e[i].t,w=e[i].w;
    	if(v==fa) e[i^1].w+=d[u];
    	else ans+=d[u]-w;
	}
}
int main()
{
	n=read(),s=read();
	for(int i=1;i<=n-1;i++)
	{
		int u=read(),v=read(),w=read();
		add(u,v,w);
		add(v,u,w);
	}
	dfs(s,0);
	cout<<ans;
}
