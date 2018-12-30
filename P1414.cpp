#include <bits/stdc++.h>
#define il inline
#define Max 1000005
using namespace std;
int c[Max],n,m,maxm=-1;
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
	n=read();
	for(int i=1;i<=n;i++)
	{
		m=read();
		maxm=max(maxm,m);
		int q=sqrt(m);
		for(int j=1;j<=q;j++)
		{
			if(m%j==0)
			{
				c[j]++;
				if(j*j!=m) c[m/j]++;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		while(c[maxm]<i) maxm--;
		cout<<maxm<<endl;
	}
}
