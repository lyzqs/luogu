#include <bits/stdc++.h>
#define Max 1005
#define il inline
using namespace std;
int f[Max][Max],p1[Max][Max],p2[Max][Max],s[Max],T,n,a[Max];
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
	T=read();
	while(T--)
	{
		memset(s,0,sizeof(s));
		memset(f,-0x3f3f3f3f,sizeof(f));
		memset(p1,0,sizeof(p1));
		memset(p2,0,sizeof(p2));
		n=read();
		for(int i=1;i<=n;i++)
		{
			a[i]=read();s[i]=a[i]+s[i-1];
		}
		for(int i=1;i<=n;i++) f[i][i]=a[i],p1[i][i]=s[i-1]-a[i],p2[i][i]=s[i]+a[i];
		for(int len=1;len<=n;len++)
		{
			for(int l=1;l<=n-len;l++)
			{
				int r=l+len;
				f[l][r]=max(f[l][r],p1[l+1][r]-s[l-1]);
				f[l][r]=max(f[l][r],s[r]-p2[l][r-1]);
				f[l][r]=max(f[l][r],s[r]-s[l-1]);
				p1[l][r]=max(p1[l+1][r],s[l-1]-f[l][r]);
				p2[l][r]=min(p2[l][r-1],f[l][r]+s[r]);
				//printf("%d %d:%d %d %d\n",l,r,f[l][r],p1[l][r],p2[l][r]);
			}
		}
		printf("%d\n",(f[1][n]+s[n])/2);
	}
}
//f[l][r]=Max(f[l][r],(s[l1-1]-f[l1][r]) -s[l-1])
//f[l][r]=Max(f[l][r],s[r] - (s[r1]+f[l][r1]) )
//p1[l][r]=max(s[i-1]-f[i][r]  l<=i<=r)
//p2[l][r]=min(s[i]+f[l][i] l<=i<=r)
//a-b
//b=sum-a
//2a-sum=a-b
//a=a-b+sum/2
