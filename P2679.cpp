#include <bits/stdc++.h>
#define Max 1005
#define Mod 1000000007
using namespace std;
char a[Max],b[Max];
int n,m,k,u=1,v=0;
int d[2][Max][Max],f[2][Max][Max];
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	scanf("%s%s",a+1,b+1);
	f[0][0][0]=f[1][0][0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			for(int t=1;t<=k;t++)
			{
				if(a[i]==b[j]) d[u][j][t]=(d[v][j-1][t]+f[v][j-1][t-1])%Mod;
				else d[u][j][t]=0;
				f[u][j][t]=(f[v][j][t]+d[u][j][t])%Mod; 
			}
		}
		u^=1;
		v^=1;
	}
	printf("%d",f[v][m][k]);
}
