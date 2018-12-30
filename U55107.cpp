#include <bits/stdc++.h>
#define il inline
#define ll long long
#define Max 1005
#define Mod 998244353
using namespace std;
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
il ll qpw(ll a,ll b)
{
	ll res=1;
	while(b)
	{
		if(b&1) res=res*a%Mod;
		a=a*a%Mod;
		b>>=1;
	}
	return res;
}
ll n,m;
int main()
{
	//cout<<qpw(11ll,11ll)<<' '<<qpw(12,12);
	ll t=read();
	for(ll i=1;i<=t;i++)
	{
		n=read(),m=read();
		printf("%lld\n",qpw(qpw(2,n-1),m-1));
	}
}
