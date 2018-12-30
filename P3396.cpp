#include <bits/stdc++.h>
#define il inline
#define Max 150005
using namespace std;
il int read()
{
	char c=getchar();
	int x=0,f=1;
	while(c>'9'||c<'0')
	{
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
int n,m,a[Max],b,ans[Max][1033];
signed main()
{
	n=read(),m=read();b=pow(n,0.233);
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		for(int j=1;j<=b;j++)
		{
			ans[j][i%j]+=a[i];
		}
	}
	while(m--)
	{
		char opt[3];
		scanf("%s",opt);
		int x=read(),y=read();
		if(opt[0]=='A')
		{
			if(x<=b)
				printf("%d\n",ans[x][y%x]);
			else
			{
				int res=0;
				for(int i=y;i<=n;i+=x)
				{
					res+=a[i];
				}
				printf("%d\n",res);
			}
		}
		if(opt[0]=='C')
		{
			for(int i=1;i<=b;i++)
			{
				ans[i][x%i]+=y-a[x];
			}
			a[x]=y;
		}
	}
}
