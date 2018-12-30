#include <bits/stdc++.h>
#define Max 500005
#define il inline
using namespace std;
int head[Max],n,m,tot,dfn[Max],low[Max],cnt,ans[Max],q[Max],s[Max],vst[Max],top=0,nn;
struct node
{
	int t,nt;
}e[Max<<1];
il int read()
{
	int x=0;
	char c=getchar();
	while(c>'9'||c<'0') c=getchar();
	while(c>='0'&&c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return x;
}
il void add(int u,int v)
{
	e[++tot].t=v;
	e[tot].nt=head[u];
	head[u]=tot;
}
il void tarjan(int u)
{
	dfn[u]=low[u]=++cnt;
	s[++top]=u;
	vst[u]=1;
	for(int i=head[u];i;i=e[i].nt)
	{
		int v=e[i].t;
		//printf("%d %d\n",u,v);
		if(!dfn[v])
		{
			//
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
		int num=0;
		while(s[top--])
        {
            int v=s[top+1];
        	q[++num]=v;
            vst[v]=0;
            if(u==v) break;
        }
		if(num>nn)
		{
			nn=num;
			for(int i=1;i<=num;i++)
			{
				ans[i]=q[i];
				vst[ans[i]]=0;
				if(ans[i]==u) break;
			}
			sort(ans+1,ans+1+nn);
		}
		else if(num==nn)
		{
			sort(q+1,q+1+num);
			int qwq=1;
			while(ans[qwq]==q[qwq])qwq++;
			if(q[qwq]<ans[qwq])
			{
				for(int i=1;i<=num;i++)
				{
					ans[i]=q[i];
				}
			}
		}
	}
}
int main()
{
	n=read(),m=read();
	for(int i=1;i<=m;i++)
	{
		int u=read(),v=read(),opt=read();
		add(u,v);//printf("add:%d %d\n",u,v);
		if(opt==2) add(v,u);//printf("add:%d %d\n",v,u);
	}
	for(int i=1;i<=n;i++)
		if(!dfn[i]) tarjan(i);
	printf("%d\n",nn);
	for(int i=1;i<=nn;i++)
		printf("%d ",ans[i]);
	//for(int i=1;i<=n;i++)
	{
		//printf("i:%d low:%d,dfn:%d\n",i,low[i],dfn[i]);
	}
}
