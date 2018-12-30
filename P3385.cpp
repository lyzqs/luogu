#include <bits/stdc++.h>
#define ll long long 
using namespace std;
int T,n,m,tot;
int q[50000005],head[1000005],d[1000005],c[1000005],vst[1000005];
struct node
{
	ll nt,t,w;
}e[100005];
int read()
{
	char c=getchar();
	int x=0,num=1;
	while((c>'9'||c<'0')&&c!='-') c=getchar();
	if(c=='-') num=-1,c=getchar();
	while(c>='0'&&c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return x*num;
}
int add(int u,int v,int w)
{
	e[++tot].t=v;
	e[tot].nt=head[u];
	e[tot].w=w;
	head[u]=tot;
}
int spfa()
{
	int l=0,r=1;
	memset(d,0x3f3f3f3f,sizeof(d));d[1]=0;
	memset(vst,0,sizeof(vst));
	memset(c,0,sizeof(c));
	c[1]=1;
	vst[1]=1;
	q[r]=1;
	while(l<r)
	{
		int t=q[++l];vst[t]=0;
		for(int i=head[t];i;i=e[i].nt)
		{
			int v=e[i].t,w=e[i].w;
			if(d[t]+w<d[v])
			{
				//printf("test:%d\n",t);
				d[v]=d[t]+w;
				c[v]++;
				if(c[v]>=n) return 1;
				if(!vst[v]) q[++r]=v,vst[v]=1;
			}
		}
	}
	return 0;
}
int main()
{
	T=read();
	//printf("%d",T);
	while(T--)
	{
		memset(head,0,sizeof(head));
		n=read(),m=read();
		for(int i=1;i<=m;i++)
		{
			int x=read(),y=read(),z=read();
			add(x,y,z);
			if(z>=0) add(y,x,z);
		}
		if(spfa()) printf("YE5\n");
		else printf("N0\n");
		//for(int i=1;i<=n;i++) printf("%d ",c[i]);
	}
}
