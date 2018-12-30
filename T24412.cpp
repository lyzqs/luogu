#include <bits/stdc++.h>
#define Max 100005
using namespace std;
int n,m,tot,cnt,top,ans;
int p[Max],s[Max],T,low[Max],dfn[Max],mp[Max],in[Max],q[100000005],d[Max],head[Max],h[Max],vst[Max],flag;
struct node
{
    int t,nt,fr;
}e[Max*10],ed[Max*10];
int read()
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
void add(int u,int v)
{
    e[++tot].t=v;
    e[tot].nt=head[u];
    //e[tot].fr=u;
    head[u]=tot;
}
void tarjan(int u)
{
    low[u]=dfn[u]=++cnt;
    s[++top]=u;
    vst[u]=1;
    for(int i=head[u];i;i=e[i].nt)
    {
        int v=e[i].t;
        if(!dfn[v])
        {
            tarjan(v);
            low[u]=min(low[u],low[v]);
        }
        else if(vst[v])
        {
            low[u]=min(low[u],low[v]);
        }
    }
    if(dfn[u]==low[u])
    {
        while(s[top--])
        {
            int v=s[top+1];
            mp[v]=u;
            vst[v]=0;
            if(u==v) break;
        }
    }
}
int main()
{
	T=read();
	while(T--)
	{
		memset(low,0,sizeof(low));
		memset(dfn,0,sizeof(dfn));
		memset(vst,0,sizeof(vst));
		memset(head,0,sizeof(head));
		tot=0;
		flag=0;
		cnt=0;
		top=0;
   		n=read(),m=read();
    	//for(int i=1;i<=n;i++) p[i]=read();
    	int lastans=1;
    	for(int i=1;i<=m;i++)
    	{
    	    int u=read(),v=read();
    	    lastans=u;
    	    add(u,v);
    	}
    	tarjan(lastans);
    	for(int i=1;i<=n;i++) if(!dfn[i]) flag=1;
    	if(flag) printf("No\n");
    	else printf("Yes\n");
    }
}
