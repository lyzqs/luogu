#include <bits/stdc++.h>
#define il inline
#define Max 15
#define Mod 1000000000
using namespace std;
int f[Max][1<<Max],e[Max][Max],n,m,g[1<<Max],w[Max];
int main()
{
	//freopen("P1879.in","r",stdin);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>e[i][j];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			w[i]=(w[i]<<1)+e[i][j];
		}
	for(int i=0;i<=(1<<m);i++)
		g[i]=!((i<<1)&i)&&!((i>>1)&i==0);
	f[0][0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<(1<<m);j++)
		{
			if(g[j]&&(j&w[i])==j)
			for(int k=0;k<(1<<m);k++)
			{
				if((k&j)==0)
				{
					f[i][j]=(f[i][j]+f[i-1][k])%Mod;
				}
			}
		}
	}
	int ans=0;
	for(int i=0;i<(1<<m);i++) ans+=f[n][i],ans%=Mod;
	cout<<ans;
}
