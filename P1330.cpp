#include <bits/stdc++.h>
#define Max 1000005
using namespace std;
int n,m,head[Max],Sum[5],vst[Max],c[Max],ans,tot;
struct node
{
	int t,nt;
}e[1000005];
bool dfs(int u,int cl)
{
	if(vst[u]) 
	{
		if(c[u]==cl) return 1;
		else return 0;
	}
	vst[u]=1;
	c[u]=cl;
	Sum[cl]++;
	bool bl=1;
	for(int i=head[u];i;i=e[i].nt)
	{
		int v=e[i].t;
		bl=bl&&dfs(v,1-cl);
	}
	return bl;
}
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
	head[u]=tot;
}
int main()
{
	n=read(),m=read();
	for(int i=1;i<=m;i++) 
	{
		int u=read(),v=read();
		add(u,v);add(v,u);
	}
	for(int i=1;i<=n;i++)
	{
		if(vst[i]) continue;
		Sum[0]=Sum[1]=0;
		if(!dfs(i,0))
		{
			printf("Impossible");
			return 0;
		}
		ans+=min(Sum[0],Sum[1]);
	}
	printf("%d",ans);
}
