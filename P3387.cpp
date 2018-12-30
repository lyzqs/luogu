#include <bits/stdc++.h>
#define Max 10005
using namespace std;
int n,m,tot,cnt,top,ans;
int p[Max],s[Max],low[Max],dfn[Max],mp[Max],in[Max],q[100000005],d[Max],head[Max],h[Max],vst[Max];
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
	e[tot].fr=u;
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
			p[u]+=p[v];
		}
	}
}
int tp()
{
	int l=1,r=0;
	for(int i=1;i<=n;i++)
	{
		if(mp[i]==i&&!in[i]) 
		{
			//printf("%d ",in[i]);
			q[++r]=i;
			d[i]=p[i];
		}
	}
	while(l<=r)
	{
		int u=q[l];l++;
		//printf("%d\n",u);
		for(int i=h[u];i;i=ed[i].nt)
		{
			int v=ed[i].t;
			
			d[v]=max(d[v],d[u]+p[v]);
			in[v]--;
			//printf("%d",in[v])
			//printf("v:%d %d\n",v,in[v]);
			//printf("%d\n",v);
			if(in[v]==0) q[++r]=v;
		}
	}
}
int main()
{
	n=read(),m=read();
	for(int i=1;i<=n;i++) p[i]=read();
	for(int i=1;i<=m;i++)
	{
		int u=read(),v=read();
		add(u,v);
	}
	for(int i=1;i<=n;i++)
	{
		if(!dfn[i]) tarjan(i);	
	}
	int s=0; 
	for(int i=1;i<=m;i++)
	{
		int u=mp[e[i].fr],v=mp[e[i].t];
		if(u!=v)
		{
			//printf("suv:%d %d %d\n",s,u,v);
			ed[++s].nt=h[u];
			ed[s].t=v;
			ed[s].fr=u;
			h[u]=s;
			in[v]++;
		}
	}
	tp();
	for(int i=1;i<=n;i++) ans=max(ans,d[i]);
	//for(int i=1;i<=m;i++) printf("%d ",mp[i]);printf("\n");
	printf("%d",ans);
}
