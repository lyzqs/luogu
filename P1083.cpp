#include <bits/stdc++.h>
#define il inline
#define Max 1000005
using namespace std;
int x[Max],y[Max],d[Max],dif[Max],w[Max],n,m,ans,a[Max];
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
il bool check(int pos)
{
	memset(dif,0,sizeof(dif));
	for(int i=1;i<=pos;i++)
	{
		dif[x[i]]+=d[i];
		dif[y[i]+1]-=d[i];
	}
	for(int i=1;i<=n;i++)
	{
		a[i]=a[i-1]+dif[i];
		//cout<<i<<' '<<a[i]<<endl;
		if(a[i]>w[i]) return 0;
	}
	return 1;
}
int main()
{
	n=read(),m=read();
	for(int i=1;i<=n;i++)
	{
		w[i]=read();
	}
	for(int i=1;i<=m;i++)
	{
		d[i]=read(),x[i]=read(),y[i]=read();
	}
	int l=1,r=m,mid;
	if(check(m)) cout<<'0',exit(0);
	while(l<=r)
	{
		mid=(l+r)>>1;
		if(check(mid)) ans=mid,l=mid+1;
		else r=mid-1;
	}
	cout<<"-1\n"<<ans+1;
}
