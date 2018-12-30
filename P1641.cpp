#include <bits/stdc++.h>
#define mian main
#define Max 2000005
#define il inline
#define Mod 20100403
#define ll long long
using namespace std;
ll n,m,w[Max];
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
il ll C(ll a,ll b)
{
	ll res=w[a];
	res=res*qpw(w[b],Mod-2)%Mod;
	res=res*qpw(w[a-b],Mod-2)%Mod;
	return res;
}
il void pre()
{
	w[1]=1;
	for(int i=2;i<=n*2;i++)
	{
		w[i]=w[i-1]*i%Mod;
	}
}
int mian()
{
	cin>>n>>m;
	pre();
	cout<<((C(n+m,n)-C(n+m,n+1)+Mod)%Mod);
}
