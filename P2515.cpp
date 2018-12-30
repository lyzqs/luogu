#include <bits/stdc++.h>
#define il inline
#define Max 2005
using namespace std;
il int read()
{
    char c=getchar();
    int x=0,f=1;
    while(c>'9'||c<'0')
    {
        if(c=='-') f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9')
    {
        x=x*10+c-'0';
        c=getchar();
    }
    return x*f;
}
struct node
{
    int t,nt;
}e[Max<<1];
int head[Max],w[Max],v2[Max],w2[Max],n,m,tot,cnt,dfn[Max],low[Max],s[Max],f[2005][2005],v[Max],to[Max],top,cl,col[Max],vst[Max],rd[Max];
il void add(int u,int v)
{
    e[++tot].t=v;
    e[tot].nt=head[u];
    head[u]=tot;
}
il void tarjan(int u)
{
    dfn[u]=low[u]=++cnt;
    vst[u]=1;
    s[++top]=u;
    for(int i=head[u];i;i=e[i].nt)
    {
        int v=e[i].t;
        if(!dfn[v])
        {
            tarjan(v);
            low[u]=min(low[u],low[v]);
        }
        else if(vst[v]) low[u]=min(low[u],dfn[v]);
    }
    if(low[u]==dfn[u])
    {
        ++cl;
        while(19260817)
        {
            top--;
            int v=s[top+1];
            vst[v]=0;
            col[v]=cl;
            if(v==u) break;
        }
    }
}
il void dfs(int u)
{
	for(int i=w2[u];i<=m;i++) f[u][i]=v2[u];
	for(int i=head[u];i;i=e[i].nt)
	{
		int v=e[i].t;
		dfs(v);
		for(int j=m-w2[u];j>=0;j--)
		{
			for(int k=0;k<=j;k++)
			{
				f[u][j+w2[u]]=max(f[u][j+w2[u]],f[u][j+w2[u]-k]+f[v][k]);
			}
		}
	}
}
int main()
{
    n=read();m=read();
    for(int i=1;i<=n;i++)
    {
        w[i]=read();
    }
    for(int i=1;i<=n;i++)
    {
        v[i]=read();
    }
    for(int i=1;i<=n;i++)
    {
        to[i]=read();
        if(!to[i]) continue;
        add(to[i],i);
    }
    for(int i=1;i<=n;i++) if(!dfn[i]) tarjan(i);
	//for(int i=1;i<=n;i++) cout<<i<<' '<<col[i]<<endl;
    memset(e,0,sizeof(e));
    memset(head,0,sizeof(head));
    tot=0;
    for(int i=1;i<=n;i++)
    {
        v2[col[i]]+=v[i];
        w2[col[i]]+=w[i];
        if(col[i]!=col[to[i]]&&to[i]!=0) add(col[to[i]],col[i]),rd[col[i]]++;
    }
    for(int i=1;i<=cl;i++)
    {
        if(!rd[i]) add(Max-1,i);
    }
    dfs(Max-1);
    cout<<f[Max-1][m];
}
