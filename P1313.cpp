#include <bits/stdc++.h>
#define Mod 10007
#define ll long long
#define il inline
#define Max 1005
using namespace std;
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
ll a,b,k,n,m;
ll c[Max][Max],ans;
int main()
{
	cin>>a>>b>>k>>n>>m;
	a=qpw(a,n);
	b=qpw(b,m);
	c[0][0]=1;
	for(int i=1;i<=k;i++) c[i][0]=c[i][i]=1;
	for(int i=1;i<=k;i++)
		for(int j=1;j<i;j++)
		{
			c[i][j]=(c[i-1][j]+c[i-1][j-1])%Mod;
		}
	ans=(a*b)%Mod;
	cout<<(ans*c[k][min(n,m)])%Mod;
}
