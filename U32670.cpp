#include <bits/stdc++.h>
#define Mod 9
#define ll long long 
using namespace std;
ll a,b,q,l,r;
int main()
{
	scanf("%lld",&q);
	while(q--)
	{
		scanf("%lld%lld",&l,&r);
		a=l+r;
		b=r-l+1;
		if(a%2==0) a/=2;
		else b/=2;
		a%=Mod;
		b%=Mod;
		printf("%lld\n",(a*b)%Mod);
	}
}
