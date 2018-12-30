#include <bits/stdc++.h>
#define Max 2505
#define inf 0x3f3f3f3f
using namespace std;
int a[Max][Max],u[Max][Max],lr[Max][Max],f[Max][Max],n,m,ans=0;
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			scanf("%d",&a[i][j]);
			if(!a[i][j])
			{
				u[i][j]=u[i-1][j]+1;
				lr[i][j]=lr[i][j-1]+1;
			}
			else
			{
				f[i][j]=min(f[i-1][j-1],min(lr[i][j-1],u[i-1][j]))+1;
				ans=max(ans,f[i][j]);
			}
		}
	}
	memset(f,0,sizeof(f));
	memset(lr,0,sizeof(lr));
	memset(u,0,sizeof(u));
	for(int i=1;i<=n;i++)
	{
		for(int j=m;j>=1;j--)
		{
			if(!a[i][j])
			{
				u[i][j]=u[i-1][j]+1;
				lr[i][j]=lr[i][j+1]+1;
			}
			else
			{
				f[i][j]=min(f[i-1][j+1],min(lr[i][j+1],u[i-1][j]))+1;
				ans=max(ans,f[i][j]);
			}
		}
	}
	cout<<ans;
}
