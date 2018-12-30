#include <bits/stdc++.h>
using namespace std;
int f[105][10005],s[10005][105],a[10005][105],mx[105],mx1[105];
int n,m;
int read()
{
	char c=getchar();
	int x=0;
	while(c>'9'||c<'0')
	{
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return x;
}
int main()
{
	n=read(),m=read();
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
			a[i][j]=read(),s[i][j]=s[i][j-1]+a[i][j];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			for(int k=1;k<=i;k++)
			{
				if(mx1[i-k]==j) continue;
				f[i][j]=max(f[i][j],mx[i-k]+s[j][k]);
				if(f[i][j]>mx[i]) mx[i]=f[i][j],mx1[i]=j;
			}
	printf("%d",mx[n]);
}
//i:day
//j:方式
//f[i][j] 第i天用j的最大值 
//f[i][j]= max(f[i-k])+s[j][k];
