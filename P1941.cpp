#include <bits/stdc++.h>
#define il inline
#define Maxn 10005
#define Maxm 2005
#define inf 0x3f3f3f3f
using namespace std;
int n,m,k;
int up[Maxn],dn[Maxn],z[Maxn],x[Maxn],y[Maxn];
int f[Maxn][Maxm],last=-inf;
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
il void find()
{
	int ans=inf;
	for(int i=1;i<=m;i++)
		ans=min(ans,f[n][i]);
	if(ans<inf)
	{
		printf("1\n%d",ans);
		return;
	}
	int i,j,res=0;
	for(i=n;i>=1;i--)
	{
		for(j=1;j<=m;j++)
			if(f[i][j]<inf)
				break;
		if(j<=m) break;
	}
	//printf("!!!%d %d %d\n",i,j,f[i][j]);
		for(j=1;j<=i;j++)
		{
			if(z[j]) res+=z[j];
		}
		printf("0\n%d",res);
}
int main()
{
	freopen("P1941.in","r",stdin);
	n=read(),m=read(),k=read();
	for(int i=1;i<=n;i++) x[i]=read(),y[i]=read();
	for(int i=1;i<=n;i++) dn[i]=1,up[i]=m;
	for(int i=1;i<=k;i++)
	{
		int a=read(),b=read(),c=read();
		z[a]=1;
		dn[a]=b+1;
		up[a]=c-1;
		//last=max(last,a);
	}
	memset(f,inf,sizeof(f));
	for(int i=0;i<=m;i++)
	{
		f[0][i]=0;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=x[i]+1;j<=m+x[i];j++)
		{
			f[i][j]=min(f[i-1][j-x[i]]+1,f[i][j-x[i]]+1);
		}
		for(int j=m+1;j<=m+x[i];j++)
		{
			f[i][m]=min(f[i][m],f[i][j]);
		}
		for(int j=1;j<=m-y[i];j++)
		{
			f[i][j]=min(f[i][j],f[i-1][j+y[i]]);
		}
		for(int j=1;j<dn[i];j++) f[i][j]=inf;
		for(int j=up[i]+1;j<=m;j++) f[i][j]=inf;
	}
	find();
}
//f[x][y]=mindianji
