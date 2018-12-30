#include <bits/stdc++.h>
#define ll unsigned long long
#define il inline
#define Mod 123456789
using namespace std;
ll k;
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
	cin>>k;
	cout<<qpw(2,k-1);
}
