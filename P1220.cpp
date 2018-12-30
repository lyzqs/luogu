#include <bits/stdc++.h>
#define Max 55
#define inf 0x3f3f3f3f
#define il inline
using namespace std;
int a[Max],b[Max],f[Max][Max][2],s[Max],n,c;
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
il int calc(int i,int j,int l,int r)
{
	return (a[j]-a[i])*(s[l]+s[n]-s[r-1]);
}
int main()
{
	n=read(),c=read();//cout<<n<<' '<<c;
	for(int i=1;i<=n;i++)
		a[i]=read(),b[i]=read(),s[i]=s[i-1]+b[i];
	memset(f,inf,sizeof(f));
	f[c][c][0]=f[c][c][1]=0;
	for(int len=1;len<n;len++)
		for(int l=1;l<=n-len;l++)
		{
			int r=l+len;
			f[l][r][0]=min(f[l+1][r][0]+calc(l,l+1,l,r+1),f[l+1][r][1]+calc(l,r,l,r+1));
			f[l][r][1]=min(f[l][r-1][0]+calc(l,r,l-1,r),f[l][r-1][1]+calc(r-1,r,l-1,r));
		}
	cout<<min(f[1][n][0],f[1][n][1]);
}
