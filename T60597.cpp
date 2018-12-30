#include <bits/stdc++.h>
#define il inline
#define Max 1000005
#define ll long long 
#define Mod 1000000007
using namespace std;
ll n,m,a,k,w,res=1;
il ll qpw(register ll a,register ll b)
{
	register ll res=1;
	while(b)
	{
		if(b&1) res=res*a%Mod;
		a=a*a%Mod;
		b>>=1;
	}
	return res;
}
int main()
{
	scanf("%lld %lld %lld",&w,&n,&k);
	register ll ans=qpw(qpw(2,Mod-2),k);
	printf("%lld\n",w*ans%Mod);
}
