#include <bits/stdc++.h>
#define il inline
using namespace std;
int f[105][105],g[105][105],n,op[105],a[105],ans[105],tot=0;
il int read()
{
	char c=getchar();
	int x=0,num=1;
	while(c>'9'||c<'0')
	{
		if(c=='-') num=-1;
		if(c=='t') return 1;
		if(c=='x') return 2;
 		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return x*num;
}
il int fun(int a,int b,int o)
{
	if(o==1) return a+b;
	if(o==2) return a*b;
	return 0;
}
il int mymax(int l,int r,int k,int opt)
{
	return max(fun(f[l][k],f[k+1][r],opt),max(fun(f[l][k],g[k+1][r],opt),max(fun(g[l][k],f[k+1][r],opt),fun(g[l][k],g[k+1][r],opt))));
}
il int mymin(int l,int r,int k,int opt)
{
	return min(fun(f[l][k],f[k+1][r],opt),min(fun(f[l][k],g[k+1][r],opt),min(fun(g[l][k],f[k+1][r],opt),fun(g[l][k],g[k+1][r],opt))));
}
int main()
{
	n=read();
	memset(f,-0x3f3f3f3f,sizeof(f));
	memset(g,0x3f3f3f3f,sizeof(g));
	for(int i=1;i<=n;i++)
		op[i+n]=op[i]=read(),a[i+n]=a[i]=read(),f[i][i]=f[i+n][i+n]=a[i],g[i][i]=g[i+n][i+n]=a[i];
	for(int len=1;len<=n-1;len++)
	{
		for(int l=1;l<=2*n-len;++l)
		{
			int r=l+len;
			for(int k=l;k<r;k++)
			{
				f[l][r]=max(f[l][r],mymax(l,r,k,op[k+1]));
				g[l][r]=min(g[l][r],mymin(l,r,k,op[k+1]));
			}
		}
	}
	int maxn=-0x3f3f3f3f;
	for(int i=1;i<=n;i++)
	{
		if(f[i][i+n-1]>maxn)
		{
			maxn=f[i][i+n-1];
			tot=0;
		}
		if(f[i][i+n-1]==maxn)
		{
			ans[++tot]=i;
		}
	}
	printf("%d\n",maxn);
	for(int i=1;i<=tot;i++) printf("%d ",ans[i]);
}
//
