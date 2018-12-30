#include <bits/stdc++.h>
#define il inline
#define Max 1000005
#define ll long long
#define int ll
using namespace std;
il ll read()
{
	char c=getchar();
	ll x=0,f=1;
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
struct node
{
	int x,y;
}e[Max];
ll ans=1e16,s[Max],s2[Max],n,x[Max],y[Max];
signed main()
{
	n=read();
	for(int i=1;i<=n;i++)
	{
		int q=read(),p=read();
		e[i].x=x[i]=q+p;
		e[i].y=y[i]=q-p;
	}
	sort(x+1,x+1+n);
	sort(y+1,y+1+n);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+x[i],s2[i]=s2[i-1]+y[i];
	for(int i=1;i<=n;i++)
	{
		ll res=0,k=lower_bound(x+1,x+1+n,e[i].x)-x;
		res+=s[n]-2*s[k]+e[i].x*(2*k-n);
		k=lower_bound(y+1,y+1+n,e[i].y)-y;
		res+=s2[n]-2*s2[k]+e[i].y*(2*k-n);
		ans=min(ans,res);
	}
	cout<<ans/2;
}
