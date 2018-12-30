#include <bits/stdc++.h>
#define Max 200005
#define il inline
#define inf 0x3f3f3f3f
using namespace std;
int head[Max],tot,n,s,t,d[105],vst[105];
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
il void add(int u,int v,int w)
{
	e[++tot].t=v;
	e[tot].nt=head[u];
	e[tot].w=w;
	head[u]=tot;
}
int main()
{
	//freopen("p1346.in","r",stdin);
	n=read(),s=read(),t=read();
	for(int i=1;i<=n;i++)
	{
		int k=read();
		//int u=read();
		//printf("%d %d %d\n",i,k,u);
		int u;
		for(int j=1;j<=k;j++)
			u=read(),add(i,u,(j==1)?0:1);
	}
	memset(d,inf,sizeof(d));
	d[s]=0;
	priority_queue<node2> q;
	q.push((node2){0,s});
	while(!q.empty())
	{
		node2 k=q.top();
		q.pop();
		int u=k.nn;
		//printf("qwq");
		if(d[u]!=k.ww||vst[u]) continue;
		vst[u]=1;
		for(int i=head[u];i;i=e[i].nt)
		{
			int v=e[i].t,w=e[i].w;
			if(d[v]>d[u]+w)
			{
				d[v]=d[u]+w;
				q.push((node2){d[v],v});
			}
		}
	}
	if(d[t]==inf) printf("-1");
	else printf("%d",d[t]);
}
