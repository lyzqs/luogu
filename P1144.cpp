#include <bits/stdc++.h>
#define il inline
#define Max 2000005
#define inf 0x3f3f3f3f
#define Mod 100003
using namespace std;
int head[Max],tot,n,m,d[Max],cnt[Max],vst[Max];
struct node
{
	int t,nt,w;
}e[Max<<1];
struct node2
{
	int ww,nn;
};
bool operator < (node2 a,node2 b)
{
	return a.ww>b.ww;
}
il void add(int u,int v,int w)
{
	e[++tot].t=v;
	e[tot].nt=head[u];
	e[tot].w=w;
	head[u]=tot;
}
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
int main()
{
	n=read(),m=read();
	for(int i=1;i<=m;i++)
	{
		int u=read(),v=read();
		add(u,v,1);
		add(v,u,1);
	}
	memset(d,inf,sizeof(d));
	d[1]=0;
	cnt[1]=1;
	priority_queue<node2> q;
	q.push((node2){0,1});
	while(!q.empty())
	{
		node2 k=q.top();
		q.pop();
		int u=k.nn;
		//printf("qwq\n");
		if(k.ww!=d[u]||vst[u]) continue;
		vst[u]=1;
		//printf("qwq\n");
		for(int i=head[u];i;i=e[i].nt)
		{
			int v=e[i].t,w=e[i].w;
			if(d[v]==d[u]+w)
			{
				cnt[v]+=cnt[u];
				cnt[v]%=Mod;
			}
			else if(d[v]>d[u]+w)
			{
				cnt[v]=cnt[u];
				d[v]=d[u]+w;
				q.push((node2){d[v],v});
				//printf("add:%d %d\n",v,d[v]);
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		printf("%d\n",cnt[i]);
	}
}
