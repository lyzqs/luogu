#include <bits/stdc++.h>
#define il inline
#define ll long long
#define Max 10000005
#define Mod 998244353l
using namespace std;
ll n,qwq,res=0;
il ll qpw(ll a,ll b)
{
	ll ans=1;
	while(b)
	{
		if(b&1) ans=(ans*a)%Mod;
		a=(a*a)%Mod;
		b>>=1;
	}
	return ans%Mod;
}
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
int main()
{
	n=read();
	qwq=qpw(2,n-1);
	for(ll i=1;i<=n;i++)
	{
		res=(res+((read()*qwq)%Mod))%Mod;
	}
	printf("%lld",res);
}
