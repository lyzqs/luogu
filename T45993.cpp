#include <bits/stdc++.h>
#define ll long long
#define il inline
#define Max 200005
using namespace std;
ll n,m,pos,len,ans=0;
il ll read()
{
	char c=getchar();
	ll x=0;
	while(c>'9'||c<'0') c=getchar();
	while(c>='0'&&c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return x;
}
map<ll,int> q;
int main()
{
	n=read(),m=read();
	for(ll i=1;i<=n;i++)
	{
		pos=i+m;
		len=read();
		ans+=q[pos+len]++;
		ans+=q[pos-len]++;
	}
	printf("%lld",ans);
}
