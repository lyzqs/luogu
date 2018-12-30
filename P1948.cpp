#include <bits/stdc++.h>
#define il inline
#define Max 100005
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
int n,m,d[Max],k,vst[Max],q[10000005],tot,head[Max];
il void add(int u,int v,int w)
{
	e[++tot].t=v;
	e[tot].nt=head[u];
	e[tot].w=w;
	head[u]=tot;
}
il bool spfa(int x)
{
	memset(d,0x3f,sizeof(d));
	memset(vst,0,sizeof(vst));
	d[1]=0;
	int l=1,r=1;
	vst[1]=1;
	q[l]=1;
	while(l<=r)
	{
		int u=q[l++];
		vst[u]=0;
		for(int i=head[u];i;i=e[i].nt)
		{
			int v=e[i].t,w=e[i].w;
			if(w>x) w=d[u]+1;
			else w=d[u];
			if(w<d[v])
			{
				d[v]=w;
				if(!vst[v]) q[++r]=v,vst[v]=1;
			}
		}
	}
	if(d[n]<=k) return 1;
	return 0;
}
int main()
{
	n=read();m=read(),k=read();
	for(int i=1;i<=m;i++)
	{
		int u=read(),v=read(),w=read();
		add(u,v,w);
		add(v,u,w);
	}
	int l=0,r=1000000,ans;
	if(!spfa(r)) puts("-1"),exit(0);
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(spfa(mid)) ans=mid,r=mid-1;
		else l=mid+1;
	}
	cout<<ans;
}
