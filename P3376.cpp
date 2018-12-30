#include <bits/stdc++.h>
#define il inline
using namespace std;
int n,m,s,t,tot=1,head[1000005];
int q[2000005];
bool vst[100005];
struct node
{
	int t,nt,w;
}e[2000005];
struct path
{
	int from;
	int ed;
}pre[2000005];
il void add(int u,int v,int w)
{
	e[++tot].t=v;
	e[tot].nt=head[u];
	head[u]=tot;
	e[tot].w=w;
}
il bool bfs()
{
	memset(pre,0,sizeof(pre));
	memset(vst,0,sizeof(vst));
	vst[s]=1;
	int l=1,r=1;
	q[l]=s;
	while(l<=r)
	{
		int u=q[l++];
		for(int i=head[u];i;i=e[i].nt)
		{
			int v=e[i].t;
			if(e[i].w&&!vst[v])
			{
				pre[v].from=u;
				pre[v].ed=i;
				if(v==t) return 1;
				vst[v]=1;
				q[++r]=v;
			}
		}
	}
	return 0;
}
il int ek()
{
	int ans=0;
	while(bfs())
	{
		int minn=0x3f3f3f3f;
		for(int i=t;i!=s;i=pre[i].from)
			minn=min(minn,e[pre[i].ed].w);
		for(int i=t;i!=s;i=pre[i].from)
		{
			e[pre[i].ed].w-=minn;
			e[pre[i].ed^1].w+=minn;
		}
		ans+=minn;
	}
	return ans;
}
il int read()
{
	int x=0;char c=getchar();
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
	n=read(),m=read(),s=read(),t=read();
	for(int i=1;i<=m;i++) 
	{
		int u=read(),v=read(),w=read();
		add(u,v,w),add(v,u,0);
	}
	printf("%d",ek());
}
