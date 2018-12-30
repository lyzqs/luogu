#include <bits/stdc++.h>
#define il inline
#define Max 2005
using namespace std;
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
int n,a[Max][Max],nw,last,ans;
int main()
{
	n=read();
	for(int i=1;i<n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			a[i][j]=a[j][i]=read();
		}
	}
	for(int i=1;i<=n;i++)
	{
		nw=0;
		for(int j=1;j<=n;j++)
		{
			if(a[i][j]>=nw)
			{
				last=nw;
				nw=a[i][j];
			}
			else last=max(last,a[i][j]);
		}
		ans=max(ans,last);
	}
	cout<<"1\n"<<ans;
}
