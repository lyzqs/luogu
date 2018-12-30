#include <bits/stdc++.h>
#define il inline
#define ll long long
#define Mod 1000000007
using namespace std;
ll n;
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
	ll ans=1;
	while(b)
	{
		if(b&1) ans=(ans*a)%Mod;
		a=(a*a)%Mod;
		b>>=1;
	}
	return ans%Mod;
}
int main()
{
	n=read();
	printf("%lld",((n-2)*qpw(2,n-1))%Mod+1);
}
