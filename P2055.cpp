#include <bits/stdc++.h>
#define il inline
#define inf 0x3f3f3f3f
#define Max 500005
using namespace std;
int head[Max],T,n,tot,to[Max],sh[Max],hm[Max],cnt,vst[Max],ans;
struct node
{
	int t,nt;
}e[Max];
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
		if(!vst[v])
		{
			vst[v]=1;
			if(!to[v]||dfs(to[v]))
			{
				to[v]=u;
				return true;
			}
		}
	}
	return false;
}
int main()
{
	T=read();
	while(T--)
	{
		memset(head,0,sizeof(head));
		tot=0;
		cnt=0;
		ans=0;
		memset(to,0,sizeof(to));
		n=read(); 
		for(int i=1;i<=n;i++) sh[i]=read();
		for(int i=1;i<=n;i++) 
		{
			hm[i]=read();
			if(!hm[i]&&sh[i]) add(i,i);
		}
		for(int i=1;i<=n;i++)
			if(!sh[i]||(sh[i]&&!hm[i])) ++cnt;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
			{
				int opt=read();
				if(opt&&sh[j]) add(i,j);
			}
		for(int i=1;i<=n;i++)
		{
			if(!sh[i]||(sh[i]&&!hm[i]))
			{
				memset(vst,0,sizeof(vst));
				if(dfs(i)) ans++;
			}
		}
		if(ans==cnt) printf("^_^\n");
		else printf("T_T\n");
	}
}
