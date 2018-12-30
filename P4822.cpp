#include <bits/stdc++.h>
#define il inline
#define inf 0x3f3f3f3f
#define Max 5000005
using namespace std;
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
	int t,nt,w;
}e[Max<<1];
struct nd
{
	int ww,nn;
	nd(int qwq1=0,int qwq2=0)
	{
		ww=qwq1;nn=qwq2;
	}
};
int n,m,k,tot,head[Max],vst[Max],d[Max],s,t;
il void add2(int u,int v,int w)
{
	//cout<<"add: "<<u<<' '<<v<<' '<<w<<endl;
	e[++tot].t=v;
	e[tot].w=w;
	e[tot].nt=head[u];
	head[u]=tot;
}
il void add(int u,int v,int w)
{
	add2(u,v,w),add2(v,u,w);
}
il bool operator < (nd a,nd b)
{
	return a.ww>b.ww;
}
priority_queue<nd> q;
il void dij()
{
	memset(d,0x3f,sizeof(d));
	d[1]=0;
	q.push(nd(0,1));
	while(!q.empty())
	{
		nd qwq=q.top();
		q.pop();
		int u=qwq.nn;
		if(d[u]!=qwq.ww||vst[u]) continue;
		vst[u]=1;
		for(int i=head[u];i;i=e[i].nt)
		{
			int v=e[i].t,w=e[i].w;
			if(d[v]>d[u]+w)
			{
				//cout<<v<<' '<<d[v]<<endl;
				d[v]=d[u]+w;
				q.push(nd(d[v],v));
			}
		}
	}
}
int main()
{
	n=read(),m=read();k=read();
	for(int i=1;i<=m;i++)
	{
		int u=read(),v=read(),w=read();
		add(u,v,w);
		for(int j=1;j<=k;j++)
		{
			add(u+n*j,v+n*j,w);
			add2(u+n*(j-1),v+n*j,w/2);
			add2(v+n*(j-1),u+n*j,w/2);
		}
	}
	t=n*(k+1)+1;
	for(int i=0;i<=k;i++) add2(n+n*i,t,0);
	dij();
	cout<<d[t]<<endl;
}
