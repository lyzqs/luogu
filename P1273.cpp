#include <bits/stdc++.h>
#define Max 3005
#define inf 0x3f3f3f3f
#define il inline
#define db() printf("qwq\n")
using namespace std;
int head[Max],tot,cnt,n,m,val[Max],f[Max][Max];
struct node
{
	int t,nt,w;
}e[Max<<1];
il int read()
{
	int x=0,f=1;
	char c=getchar();
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
il void add(int u,int v,int w)
{
	e[++tot].t=v;
	e[tot].nt=head[u];
	head[u]=tot;
	e[tot].w=w;
}
il int dfs(int u)
{
	if(u>n-m) 
	{
		f[u][1]=val[u];
		return 1;
	}
	int Sum=0,st;
	for(int i=head[u];i;i=e[i].nt)
	{
		//db();
		int v=e[i].t,w=e[i].w;
		//if(v==fa) continue;
		st=dfs(v);Sum+=st;
		for(int j=Sum;j;j--)
		{
			for(int k=1;k<=st;k++)
			{
				if(j-k>=0) f[u][j]=max(f[u][j],f[u][j-k]+f[v][k]-w);
			}
		}
	}
	return Sum;
}
int main()
{
	n=read(),m=read();
	memset(f,~inf,sizeof(f));
	for(int i=1;i<=n-m;i++)
	{
		int k=read();
		for(int j=1;j<=k;j++)
		{
			int v=read(),w=read();
			add(i,v,w);
			//add(v,i,w);
		}
	}
	for(int i=1;i<=n;i++) f[i][0]=0;
	for(int i=n-m+1;i<=n;i++)
		val[i]=read();
	dfs(1);
	for(int i=m;i>=1;i--)
		if(f[1][i]>=0)
		{
			printf("%d",i);
			return 0;
		}
}
