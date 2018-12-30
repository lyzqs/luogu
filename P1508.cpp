#include <bits/stdc++.h>
#define Max 205
#define il inline
using namespace std;
int a[Max][Max],n,m,f[Max][Max],ans;
il int read()
{
	char c=getchar();
	int x=0,num=1;
	while(c>'9'||c<'0')
	{
		if(c=='-') num=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return x*num;
}
int main()
{
	n=read(),m=read();
	memset(a,-0x3f3f3f3f,sizeof(a));
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			a[i][j]=read();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			f[i][j]=max(max(f[i-1][j],f[i-1][j-1]),f[i-1][j+1])+a[i][j];
	m=m/2+1;
	ans=max(max(f[n][m],f[n][m+1]),f[n][m-1]);
	cout<<ans;
}
