#include <bits/stdc++.h>
using namespace std;
int n,m,f[1005],ans,cnt,sum,tot;
struct fck
{
	int u,v,w;
}e[1005];
struct shit
{
	int l,r,ct;
}a[1005];
bool cmp(fck x,fck y)
{
	return x.w<y.w;
}
int read()
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
int find(int x)
{
	if(f[x]==x) return x;
	else return find(f[x]);
}
void dfs(int k,int nw,int st)
{
	if(nw==a[k].r+1)
	{
		if(st==a[k].ct) sum++;
		return;
	}
	int x=find(e[nw].u),y=find(e[nw].v);
	if(x!=y)
	{
		f[x]=y;
		dfs(k,nw+1,st+1);
		f[x]=x;f[y]=y;
	}
	dfs(k,nw+1,st);
}
int main()
{
	n=read(),m=read();
	for(int i=1;i<=n;i++) f[i]=i;
	for(int i=1;i<=m;i++)
	{
		e[i].u=read(),e[i].v=read(),e[i].w=read();
	}
	sort(e+1,e+1+m,cmp);
	for(int i=1;i<=m;i++)
	{
		if(e[i].w!=e[i-1].w) cnt++,a[cnt].l=i,a[cnt-1].r=i-1;
		int x=find(e[i].u),y=find(e[i].v);
		if(x!=y)
		{
			f[x]=y;
			a[cnt].ct++;
			tot++;
		}
	}
	if(tot!=n-1) 
	{
		printf("0");
		return 0;
	}
	a[cnt].r=m;
	ans=1;
	for(int i=1;i<=n;i++) f[i]=i;
	for(int i=1;i<=cnt;i++)
	{
		sum=0;
		dfs(i,a[i].l,0);
		ans=(ans*sum)%31011;
		for(int j=a[i].l;j<=a[i].r;j++)
		{
			int x=find(e[j].u),y=find(e[j].v);
			if(x!=y) f[x]=y;
		}
	}
	printf("%d",ans);
}
