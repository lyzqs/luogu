#include <bits/stdc++.h>
#define Max 100005
#define Mod 1000000007
#define il inline
#define ll long long
using namespace std;
int f[Max][105][2][2],sz[Max],head[Max],n,k,tot;
ll g[105][2][2];
struct node
{
	int t,nt;
}e[Max<<1];
il void add(int u,int v)
{
	e[++tot].t=v;
	e[tot].nt=head[u];
	head[u]=tot;
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
il int Add(int &a,ll b)
{
	return ((a%Mod)+(int)(b%Mod))%Mod;
}
il void dfs(int u,int fa)
{
	sz[u]=1;
	f[u][0][0][0]=f[u][1][1][0]=1;
	for(int i=head[u];i;i=e[i].nt)
	{
		int v=e[i].t;
		if(v==fa) continue;
		dfs(v,u);
		int qwq=min(sz[u],k);
		for(int i=0;i<=qwq;i++)
		{
			g[i][0][0]=f[u][i][0][0],f[u][i][0][0]=0;
			g[i][0][1]=f[u][i][0][1],f[u][i][0][1]=0;
    		g[i][1][0]=f[u][i][1][0],f[u][i][1][0]=0;
			g[i][1][1]=f[u][i][1][1],f[u][i][1][1]=0;
		}
		for(int i=0;i<=qwq;i++)
		{
			for(int j=0;j<=min(k-i,sz[v]);j++)
			{
				f[u][i+j][0][0]=Add(f[u][i+j][0][0],1ll*g[i][0][0]*1ll*f[v][j][0][1]);
                f[u][i+j][1][0]=Add(f[u][i+j][1][0],1ll*g[i][1][0]*1ll*(f[v][j][0][0]+f[v][j][0][1]));
                f[u][i+j][0][1]=Add(f[u][i+j][0][1],1ll*g[i][0][0]*1ll*f[v][j][1][1]+1ll*g[i][0][1]*1ll*(f[v][j][0][1]+f[v][j][1][1]));
                f[u][i+j][1][1]=Add(f[u][i+j][1][1],1ll*g[i][1][0]*1ll*(f[v][j][1][1]+f[v][j][1][0])+1ll*g[i][1][1]*1ll*(1ll*(f[v][j][0][0]+f[v][j][0][1])+1ll*(f[v][j][1][1]+f[v][j][1][0])));
			}
		}
		sz[u]+=sz[v];
	}
}
int main()
{
	n=read(),k=read();
	for(int i=1;i<=n-1;i++)
	{
		int u=read(),v=read();
		add(u,v),add(v,u);
	}
	dfs(1,0);
	cout<<Add(f[1][k][1][1],f[1][k][0][1]);
}
