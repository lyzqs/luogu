#include <bits/stdc++.h>
#define il inline
#define Max 500005
#define ll long long
#define getchar() (tt==ss&&(tt=(ss=In)+fread(In,1,Max,stdin),tt==ss)?EOF:*ss++)
using namespace std;
char In[Max],*ss=In,*tt=In;
il int read()
{
	char c=getchar();
	int x=0,f=1;
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
struct node
{
	int t,nt;
}e[Max<<1];
int head[Max],tot,tg[Max<<2],cnt,n,m,q;
ll w[Max],t[Max<<2];
il void add(int u,int v)
{
	e[++tot].t=v;
	e[tot].nt=head[u];
	head[u]=tot;
}
il void dfs(int u,int fa)
{
	
}
int main()
{
	
}
