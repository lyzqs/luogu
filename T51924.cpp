#include <bits/stdc++.h>
#define il inline
#define Max 100005
#define ll long long
using namespace std;
ll a[Max],s[Max],ans=1e16,n;
il ll read()
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
ll m,f[505][505];
il ll calc(int a,int b)
{
	return (s[b]-s[a]+1)*(s[b]-s[a]+1);
}
int main()
{
	n=read();m=read();
	for(int i=1;i<=n;i++) a[i]=read(),s[i]=s[i-1]+a[i];
	if(m==2)
	{
	for(int i=1;i<=n;i++)
	{
		ans=min(ans,(s[i]+1)*(s[i]+1)+(s[n]-s[i]+1)*(s[n]-s[i]+1));
	}
	}
	else
	{
		for(int i=1;i<=n;i++) f[i][1]=(s[i]+1)*(s[i]+1);
		for(int i=1;i<=n;i++)
		{
			for(int j=2;j<=m;j++)
			{
				f[i][j]=1e16;
				for(int k=1;k<i;k++)
				{
					f[i][j]=min(f[i][j],f[k][j-1]+calc(k,i));
				}
				//cout<<i<<' '<<j<<' '<<f[i][j]<<endl;
			}
		}
		ans=f[n][m];
	}
	cout<<ans;
}
