#include <bits/stdc++.h>
using namespace std;
#define Max 255
#define Inf 0x3f3f3f3f
int n,m,q,w,s,t,u,v;
int dst[Max][Max],d[Max][Max],rk[Max];
struct node 
{
	int vl,id;
}e[Max];
int read()
{
	char c=getchar();
	int x=0;
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return x;
}
bool cmp(node a,node b)
{
	if(a.vl==b.vl) return a.id<b.id;
	return a.vl<b.vl;
}
int main()
{
	//freopen("P2966.in","r",stdin);
	n=read(),m=read(),q=read();
	for(int i=1;i<=n;i++)
	{
		e[i].vl=read();
		e[i].id=i;
	}
	sort(e+1,e+1+n,cmp);
	for(int i=1;i<=n;i++) rk[e[i].id]=i;
	memset(d,0x3f3f3f3f,sizeof(d));
	for(int i=1;i<=n;i++) d[i][i]=0;
	for(int i=1;i<=m;i++)
	{
		u=read(),v=read(),w=read();
		u=rk[u],v=rk[v];
		d[u][v]=d[v][u]=min(d[u][v],w);
	}
	memset(dst,0x3f3f3f3f,sizeof(dst));
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
			{
				if(i==j) continue;
				d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
				dst[i][j]=min(dst[i][j],d[i][j]+max(e[k].vl,max(e[i].vl,e[j].vl)));
			}
	//while(q--)
	{
		s=read(),t=read();
		printf("%d\n",dst[rk[s]][rk[t]]);
	}
}
