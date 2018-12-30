#include <bits/stdc++.h>
#define il inline
#define Max 50005
#define inf 0x3f3f3f3f
using namespace std;
int tot,head[Max],d[Max],n,m,hp,f[Max],qwq[Max],vst[Max],ans;
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
	int x=0;
	while(c>'9'||c<'0') c=getchar();
	while(c>='0'&&c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return x;
}
il void add(int u,int v,int w)
{
	e[++tot].t=v;
	e[tot].nt=head[u];
	e[tot].w=w;
	head[u]=tot;
}
il bool spfa(int md)
{
	memset(vst,0,sizeof(vst));
	memset(d,inf,sizeof(d));
	d[1]=0;
	priority_queue<node2> q;
	q.push((node2){0,1});
	while(!q.empty())
	{
		node2 k=q.top();
		q.pop();
		int u=k.nn;
		if(d[u]!=k.ww&&vst[u]) continue;
		vst[u]=1;
		for(int i=head[u];i;i=e[i].nt)
		{
			int v=e[i].t,w=e[i].w;
			if(d[v]>d[u]+w&&f[v]<=md)
			{
				d[v]=d[u]+w;
				q.push((node2){d[v],v});
			}
		}
	}
	if(d[n]<=hp) return true;
	else return false;
}
int main()
{
	n=read(),m=read(),hp=read();
	for(int i=1;i<=n;i++)
	{
		f[i]=read();
		qwq[i]=f[i];
	}
	sort(qwq+1,qwq+1+n);
	for(int i=1;i<=m;i++)
	{
		int u=read(),v=read(),w=read();
		add(u,v,w);
		add(v,u,w);
	}
	if(spfa(qwq[n])==false)
	{
		printf("AFK");
		return 0;
	}
	int l=1,r=n,mid;
	while(l<=r)
	{
		mid=(l+r)>>1;
		if(spfa(qwq[mid]))
		{
			ans=qwq[mid];
			r=mid-1;
		}
		else l=mid+1;
	}
	printf("%d",ans);
}
