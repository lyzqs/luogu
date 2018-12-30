#include <bits/stdc++.h>
#define il inline
#define ll long long
#define Max 100005
#define eps 1e-6
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
int n,m,x[Max],y[Max];
il bool check(int nw,int  u,int v)
{
	ll xx=x[nw],yy=y[nw];
	double b1=yy;
	double k1=(-b1)/(double)xx;
	double k2=(double)u/(double)v;
	double jx=b1/(k2-k1);
	//cout<<k1<<' '<<b1<<' '<<k2<<' '<<jx<<endl;
	if(jx+eps<u||((jx+eps>u&&(jx-eps)<u))) return true;
	return false;
}
int main()
{
	n=read();
	for(int i=1;i<=n;i++)
	{
		x[i]=read();
	}
	for(int i=1;i<=n;i++)
	{
		y[i]=read();
	}
	sort(x+1,x+1+n);sort(y+1,y+1+n);
	m=read();
	for(int i=1;i<=m;i++)
	{
		int u=read(),v=read();
		int l=1,r=n,mid,ans=0;
		while(l<=r)
		{
			mid=(l+r)>>1;
			if(check(mid,u,v)) ans=mid,l=mid+1;
			else r=mid-1;
		}
		printf("%d\n",ans);
	}
}
