#include <bits/stdc++.h>
#define il inline
#define Max 2005
#define int long long
using namespace std;
struct node
{
    int t,nt,w;
}e[Max<<1];
int n,m,sz[Max],f[Max][Max],head[Max],tot;
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
il void dfs(int u,int fa)
{
    sz[u]=1;
    f[u][0]=f[u][1]=0;
    for(int i=head[u];i;i=e[i].nt)
    {
        int v=e[i].t;
        if(v==fa) continue;
        dfs(v,u);
        sz[u]+=sz[v];
    }
    for(int i=head[u];i;i=e[i].nt)
    {
        int v=e[i].t,w=e[i].w;
        if(v==fa) continue;
        for(int j=min(m,sz[u]);j>=0;j--)
        {
            for(int k=0;k<=min(j,sz[v]);k++)
            {
                if(f[u][j-k]!=-1)
                {
                    int val=(k*(m-k)+(sz[v]-k)*(n-sz[v]-(m-k)))*w;
                    f[u][j]=max(f[u][j],f[u][j-k]+f[v][k]+val);
                }
            }
        }
    }
}
signed main()
{
    n=read(),m=read();
    m=min(m,n-m);
	for(int i=1;i<=n-1;i++)
	{
		int u=read(),v=read(),w=read();
		add(u,v,w);add(v,u,w);
	}
	memset(f,-1,sizeof(f));
	dfs(1,0);
	cout<<f[1][m];
}
