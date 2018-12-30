#include <bits/stdc++.h>
#define il inline
#define Max 500005
#define inf 0x3f3f3f3f
using namespace std;
struct node
{
	int t,nt,w;
}e[Max<<1];
int n,m,tot,head[Max],d[Max],vst[Max],cnt;
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
struct node2
{
	int nd;
};
bool operator < (node2 a,node2 b)
{
	return d[a.nd]>d[b.nd];
}
priority_queue<node2> q;
il void spfa()
{
	memset(d,0x3f,sizeof(d));
	d[0]=0;
	q.push((node2){0});
	while(!q.empty())
	{
		node2 qwq=q.top();
		int u=qwq.nd;
		q.pop();
		vst[u]=0;
		for(int i=head[u];i;i=e[i].nt)
		{
			int v=e[i].t,w=e[i].w;
			if(d[v]>d[u]+w)
			{
				d[v]=d[u]+w;
				if(!vst[v])
				{
					cnt++;
					if(cnt>800000) cout<<"-1",exit(0);
					vst[v]=1;
					q.push((node2){v});
				}
			}
		}
	}
	cout<<d[n];
}
int main()
{
	//freopen("P3084.in","r",stdin);
	n=read(),m=read();
	for(int i=1;i<=m;i++)
	{
		int u=read(),v=read();
		add(u-1,v,1);
		add(v,u-1,-1);
	}
	for(int i=1;i<=n;i++)
	{
		add(i,i-1,0);
		add(i-1,i,1);
	}
	spfa();
}
