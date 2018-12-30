#include <bits/stdc++.h>
#define il inline
#define P 1000
#define Max 100005
using namespace std;
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
struct node
{
	int t,nt;
}e[Max<<1];
int n,head[Max],tot,to[Max],cnt,vst[Max],T,ans;
il void init()
{
	memset(head,0,sizeof(head));
	memset(vst,0,sizeof(vst));
	memset(to,0,sizeof(to));
	ans=tot=cnt=0;
}
il void add(int u,int v)
{
	e[++tot].t=v;
	e[tot].nt=head[u];
	head[u]=tot;
}
il bool dfs(int u)
{
	for(int i=head[u];i;i=e[i].nt)
	{
		int v=e[i].t;
		if(vst[v]!=cnt)
		{
			vst[v]=cnt;
			if(!to[v]||dfs(to[v]))
			{
				to[v]=u;
				to[u]=v;
				return 1;
			}
		}
	}
	return 0;
}
int main()
{
	T=read();
	while(T--)
	{
		init();
		int n=read();
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(read()==1)
				{
					add(i,j+P);
					add(j+P,i);
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			cnt++;
			ans+=dfs(i);
		}
		if(ans==n) puts("Yes");
		else puts("No");
	}
}
