#include <bits/stdc++.h>
#define il inline
#define Mod 998244353
#define Max 1000008
using namespace std;
int a[Max],b[Max],c[Max],d[Max],v[Max],n,m,head[Max],dst[Max],cnt[Max],tot,vst[Max],inq[Max];
struct node
{
	int t,nt,w;
}e[Max<<1];
queue <int> q;
il int read()
{
	char c=getchar();
	int x=0,num=1;
	while(c>'9'||c<'0')
	{
		if(c=='-') num=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return x*num;
}
il int check(int x,int y)
{
	if(a[x]<=a[y]&&b[x]<=b[y]&&c[x]<=c[y]&&d[x]<=d[y]) return 1;
	if(a[x]>=a[y]&&b[x]>=b[y]&&c[x]>=c[y]&&d[x]>=d[y]) return -1;
	return 0;
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
	n=read(),m=read();
	a[1]=b[1]=c[1]=d[1]=1;
	a[n+2]=b[n+2]=c[n+2]=d[n+2]=m;
	int ft;
	for(int i=2;i<=n+1;i++)
	{
		a[i]=read(),b[i]=read(),c[i]=read(),d[i]=read(),v[i]=read();
		add(1,i,v[i]);add(i,n+2,0);
		for(int j=2;j<i;j++)
		{
			ft=check(i,j);
			if(ft==1) 
			{
				add(i,j,v[j]);
				//printf("add:%d %d\n",i,j);
			}
			if(ft==-1)
			{
				add(j,i,v[i]);
				//printf("add:%d %d\n",j,i);
			}
		}
	}
	n+=2;
	memset(d,-0x3f3f3f3f,sizeof(dst));
	dst[1]=0;
	memset(cnt,0,sizeof(cnt));
	cnt[1]=1;
	q.push(1);
	while(!q.empty())
	{
		int u=q.front();
		q.pop();inq[u]=0;
		for(int i=head[u];i;i=e[i].nt)
		{
			int v=e[i].t,w=e[i].w;
			if(dst[u]+w>dst[v])
			{
				dst[v]=dst[u]+w;
				cnt[v]=cnt[u];
				if(!inq[v])q.push(v),inq[v]=1;
				//printf("uv:%d %d scntv:%d\n",u,v,cnt[v]);
			}
			else if(dst[u]+w==dst[v])
			{
				cnt[v]+=cnt[u];
				cnt[v]%=Mod;
				//printf("uv:%d %d cntv:%d\n",u,v,cnt[v]);
			}
		}
	}
	printf("%d\n%d",dst[n],cnt[n]);
}
