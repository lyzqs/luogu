#include <bits/stdc++.h>
#define il inline
#define Max 500005
#define ll long long
using namespace std;
int head[Max],cnt,tot,dfn[Max],low[Max],vst[Max],cut[Max],Cnt=1,cl,n,m,ans1,Cut,num,rt,rs;
ll ans2;
struct node
{
	int t,nt;
}e[Max<<1];
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
il void init()
{
	memset(head,0,sizeof(head));
	memset(dfn,0,sizeof(dfn));
	memset(low,0,sizeof(low));
	memset(cut,0,sizeof(cut));
	memset(vst,0,sizeof(vst));
	tot=cnt=n=ans1=cl=0;
	ans2=1;
}
il void add(int u,int v)
{
	e[++tot].t=v;
	e[tot].nt=head[u];
	head[u]=tot;
}
il void tarjan(int u,int fa)
{
	dfn[u]=low[u]=++cnt;
	for(int i=head[u];i;i=e[i].nt)
	{
		int v=e[i].t;
		if(!dfn[v])
		{
			tarjan(v,u);
			low[u]=min(low[u],low[v]);
			if(low[v]>=dfn[u])
			{
				if(u!=rt) cut[u]=1;
				else rs++;
			}
		}
		else if(v!=fa) low[u]=min(low[u],dfn[v]);
	}
}
il void dfs(int u)
{
	vst[u]=cl;
	num++;
	for(int i=head[u];i;i=e[i].nt)
	{
		int v=e[i].t;
		if(cut[v]&&vst[v]!=cl)
		{
			Cut++;
			vst[v]=cl;
		}
		if(!vst[v]) dfs(v);
	}
}
int main()
{
	while(m=read())
	{
		//cout<<m<<endl;
		init();
		for(int i=1;i<=m;i++)
		{
			int u=read(),v=read();
			//cout<<u<<' '<<v<<endl;
			add(u,v),add(v,u);
			n=max(u,max(n,v));
		}
		for(int i=1;i<=n;i++)
		{
			if(!dfn[i])
			{
				rt=i;
				rs=0;
				tarjan(i,i);
				if(rs>=2) cut[i]=1;
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(!vst[i]&&!cut[i])
			{
				++cl;
				num=Cut=0;
				dfs(i);
				if(Cut==0)
				{
					ans1+=2;
					ans2*=(num-1)*num/2;
				}
				if(Cut==1)
				{
					ans1+=1;
					ans2*=num;
				}
			}
		}
		printf("Case %d: %d %lld\n",Cnt++,ans1,ans2);
	}
}
