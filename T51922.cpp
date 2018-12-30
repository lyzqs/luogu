#include <bits/stdc++.h>
#define il inline
#define Mod 1000000009
#define ll long long
#define Max 1000000000
#define Max2 1000
using namespace std;
ll n,T,ans,jc[Max/Max2+Max2];
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
int main()
{
	//for(int i=1;i<=n;i++)
	cin>>T;
	while(T--)
	{
		scanf("%lld",&n);
		printf("%lld\n",qpw(n,n-1));
	}
}
