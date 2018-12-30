#include <bits/stdc++.h>
#define ll long long 
#define Max 805
#define il inline
using namespace std;
int n,m,Mod=(int)1e9+7,k,a[Max][Max],f[Max][Max][18][2],ans;
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
	n=read(),m=read(),k=read()+1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			a[i][j]=read();
			f[i][j][a[i][j]%k][0]=1;
		}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			for(int s=0;s<=k;s++)
			{
				f[i][j][s][0]+=f[i-1][j][(s+k-a[i][j])%k][1]+f[i][j-1][(s+k-a[i][j])%k][1];
				f[i][j][s][1]+=f[i-1][j][(s+k+a[i][j])%k][0]+f[i][j-1][(s+k+a[i][j])%k][0];
				f[i][j][s][1]%=Mod;
				f[i][j][s][0]%=Mod;
			}
			ans+=f[i][j][0][1];
			ans%=Mod;
		}
	printf("%d",ans);
}
