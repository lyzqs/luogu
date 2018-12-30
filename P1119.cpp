#include <bits/stdc++.h>
#define il inline
#define Max 2005
using namespace std;
int f[Max][Max],n,m,q,t[Max],u[500005],v[500005],d[500005],s[Max];
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
int main()
{
	memset(f,0x3f,sizeof(f));
	n=read();m=read();
	for(int i=1;i<=n;i++) t[i]=read(),f[i][i]=0;
	for(int i=1;i<=m;i++)
	{
		int x=read()+1,y=read()+1,w=read();
		f[x][y]=f[y][x]=w;
	}
	q=read();
	for(int i=1;i<=q;i++)
	{
		u[i]=read()+1;
		v[i]=read()+1;
		d[i]=read();
	}
	for(int nw=1;nw<=q;nw++)
	{
		for(int k=1;k<=n;k++)
		{
			if(!s[k]&&t[k]<=d[nw])
			{
				s[k]=1;
				for(int i=1;i<=n;i++)
				{
					for(int j=1;j<=n;j++)
					{
						f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
					}
				}
			}
		}
		if(t[u[nw]]<=d[nw]&&t[v[nw]]<=d[nw]&&f[u[nw]][v[nw]]<0x3f3f3f3f) printf("%d\n",f[u[nw]][v[nw]]);
			else printf("-1\n");
	}
}
