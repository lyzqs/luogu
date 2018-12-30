#include <bits/stdc++.h>
using namespace std;
int n,hn,sn,head[100005],tot,g[100005],vst[100005],ans=0;
struct gouli
{
	int t,nt;
}e[100005];
struct mdzz
{
	int pt,mx,mn;
}h[10005],s[10005];
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
bool check(int x,int y)
{
	if(h[x].pt<s[y].mn||h[x].pt>s[y].mx) return 0;
	if(s[y].pt<h[x].mn||s[y].pt>h[x].mx) return 0;
	return 1;
}
void add(int u,int v)
{
	e[++tot].t=v;
	e[tot].nt=head[u];
	head[u]=tot;
}
bool dfs(int u)
{
	for(int i=head[u];i;i=e[i].nt)
	{
		int v=e[i].t;
		if(!vst[v])
		{
			vst[v]=1;
			if(!g[v]||dfs(g[v]))
			{
				g[v]=u;
				return 1;
			}
		}
	}
	return 0;
}
int main()
{
	//freopen("p3033.in","r",stdin);
	n=read();
	for(int i=1;i<=n;i++)
	{
		int x1=read(),y1=read(),x2=read(),y2=read();
		if(x1==x2)
		{
			h[++hn].pt=x1;
			h[hn].mx=max(y1,y2);
			h[hn].mn=min(y1,y2);
		}
		else if(y1==y2)
		{
			s[++sn].pt=y1;
			s[sn].mx=max(x1,x2);
			s[sn].mn=min(x1,x2);
		}
	}
	for(int i=1;i<=hn;i++)
		for(int j=1;j<=sn;j++)
			if(check(i,j))
				add(i,j);
	for(int i=1;i<=hn;i++)
	{
		memset(vst,0,sizeof(vst));
		//if(!th[i])
		ans+=dfs(i);
	}
	printf("%d",n-ans);
}
