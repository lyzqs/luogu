#include <bits/stdc++.h>
#define il inline
#define Max 500005
using namespace std;
int n,m,head[Max],ot[Max],dfn[Max],low[Max],cnt,s[Max],top,cl,mp[Max],du[Max],ans,tot,vst[Max],cntcl[Max];
struct node
{
	int t,nt;
}e[Max<<1];
il int read()
{
	char c=getchar();
	int x=0,f=1;
	while(c>'9'||c<'0') 
	{
		if(c=='-') x=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
il void add(int u,int v)
{
	e[++tot].t=v;
	e[tot].nt=head[u];
	head[u]=tot;
}
il void tarjan(int u)
{
	dfn[u]=++cnt;
	low[u]=cnt;
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
	if(low[u]==dfn[u])
	{
		++cl;
		while(top--)
		{
			int v=s[top+1];
			vst[v]=0;
			mp[v]=cl;
			//du[cl]+=ot[v];
			cntcl[cl]++;
			if(v==u) break;
		}
	}
}
int main()
{
	n=read(),m=read();
	for(int i=1;i<=m;i++)
	{
		int u=read(),v=read();
		add(u,v);
		//ot[u]++;
	}
	for(int i=1;i<=n;i++) 
	{
		if(!dfn[i]) tarjan(i);
	}
	for(int u=1;u<=n;u++)
	{
		for(int j=head[u];j;j=e[j].nt)
		{
			int v=e[j].t;
			if(mp[u]!=mp[v])
			du[mp[u]]++;
		}
	}
	for(int i=1;i<=cl;i++)
	{
		if(!du[i]) 
		{
			if(ans)
			{
				printf("0");
				return 0;
			}
			ans=i;
		}
	}
	printf("%d",cntcl[ans]);
}
