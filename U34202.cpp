#include <bits/stdc++.h>
#define ll long long 
using namespace std;
ll a,b,ans=0,sumn=0;
int getnum(ll i,ll j)
{
	if((i-j+1)%2==0) return 0;
	else return (j%2==0?1:-1);
}
int main()
{
	cin>>a>>b;
	for(ll k=a;k<=b;k++)
	for(ll l=1,r;l<=k;l=r+1)
	{
        if(l<=k)r=min((k/(k/l)),k);
        else r=k;
        ans+=(k/l)*getnum(l,r);
    }
    printf("%lld",ans);
}
