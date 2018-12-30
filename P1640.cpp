#include <bits/stdc++.h>
#define il inline
#define Max 4000005
#define P 10000
using namespace std;
struct node
{
	int t,nt;
}e[Max<<1];
int n,to[Max],head[Max],tot,vst[Max],cnt,ans;
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
	n=read();
	for(int i=1;i<=n;i++)
	{
		int u=read(),v=read();
		add(i+P,u),add(u,i+P);
		add(i+P,v),add(v,i+P);
	}
	for(int i=1;i<=P;i++)
	{
		++cnt;
		if(dfs(i)) ans++;
		else break;
	}
	cout<<ans;
}
