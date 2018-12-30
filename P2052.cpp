#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll ans;
int n,head[1000005],sz[1000005],tot=0;
struct node 
{
	int t,nt,w;
}e[2000005];
int read()
{
	char c=getchar();
	int x=0;
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return x;
}
int add(int u,int v,int w)
{
	e[++tot].t=v;
	e[tot].nt=head[u];
	head[u]=tot;
	e[tot].w=w;
}
void dfs(int nd,int fa)
{
	sz[nd]=1;
	for(int i=head[nd];i;i=e[i].nt)
	{
		int v=e[i].t;
		if(v==fa) continue;
		dfs(v,nd);
		sz[nd]+=sz[v];
		ans+=1ll*e[i].w*abs(n-2*sz[v]);
	}
}
int main()
{
	n=read();
	for(int i=1;i<=n-1;i++) 
	{
		int x=read(),y=read(),z=read();
		add(x,y,z),add(y,x,z); 
	}
	dfs(1,0);
	printf("%lld",ans);
}
