#include <bits/stdc++.h>
#define Max 20005
#define il inline
#define inf 0x3f3f3f3f
using namespace std;
int n,m,s,t,head[Max],tot,d[Max],vst[Max];
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
int main()
{
	n=read(),m=read(),s=read(),t=read();
	for(int i=1;i<=m;i++)
	{
		int u=read(),v=read(),w=read();
		add(u,v,w),add(v,u,w);
	}
	memset(d,inf,sizeof(d));
	d[s]=0;
	priority_queue<node2> q;
	q.push((node2){0,s});
	while(!q.empty())
	{
		node2 qwq=q.top();
		q.pop();
		int u=qwq.nn;
		if(d[u]!=qwq.ww) continue;
		vst[u]=1;
		//printf("nowu:%d\n",u);
		for(int i=head[u];i;i=e[i].nt)
		{
			int v=e[i].t,w=e[i].w;
			if(d[v]>d[u]+w)
			{
				d[v]=d[u]+w;
				q.push((node2){d[v],v});
				//printf("u:%d v:%d d:%d\n",u,v,d[v]);
			}
		}
	}
	printf("%d",d[t]);
}
