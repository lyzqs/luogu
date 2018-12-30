#include <bits/stdc++.h>
#define il inline
#define ll long long 
using namespace std;
ll m,k,ik,iik,ans=0,q=0;
il ll qpw(ll a,ll b,ll Mod)
{
	ll ans=1,r=a;
	while(b)
	{
		if(b&1) ans=(ans*r)%Mod;
		r=(r*r)%Mod;
		b>>=1;
	}
	return ans;
}
int main()
{
	scanf("%lld%lld",&k,&m);
	ik=qpw(k,m-2,m);
	iik=qpw(ik,m-2,m);
	while(19260817)
	{
		ans++;
		q=(q*10+1)%m;
		if(q==iik) break;
	}
	printf("%lld",ans);
}
