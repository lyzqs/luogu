#include <bits/stdc++.h>
using namespace std;
int n,m,tot,cnt,h[105][105],s[105][105],head[10000005],p[10000005],ans,vst[1000005];
char e[105][105];
struct node
{
	int t,nt;
}ed[10000005];
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
	ed[++cnt].t=v;
	ed[cnt].nt=head[u];
	head[u]=cnt;
}
bool dfs(int u)
{
	for(int i=head[u];i;i=ed[i].nt)
	{
		int v=ed[i].t;
		if(!vst[v])
		{
			vst[v]=1;
			if(!p[v]||dfs(p[v]))
			{
				p[v]=u;
				return 1;
			}
		}
	}
	return 0;
}
int main()
{
	n=read(),m=read();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>e[i][j];
	//for(int i=1;i<=n;i++){for(int j=1;j<=m;j++) printf("%c",e[i][j]);printf("\n");}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(e[i][j]=='#') continue;
			if(e[i][j-1]=='#'||j==1) tot++;
			h[i][j]=tot;
		}
	}
	for(int j=1;j<=m;j++)
		for(int i=1;i<=n;i++)
		{
			if(e[i][j]=='#') continue;
			if(e[i-1][j]=='#'||i==1) tot++;
			s[i][j]=tot;
		}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			if(e[i][j]=='#'||e[i][j]=='x') continue;
			add(h[i][j],s[i][j]);
		}	
	for(int i=1;i<=tot;i++)
	{
		memset(vst,0,sizeof(vst));
		ans+=dfs(i);
	}
	printf("%d",ans);
}
