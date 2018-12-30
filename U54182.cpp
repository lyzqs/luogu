#include <bits/stdc++.h>
#define il inline
#define ll long long
#define Max 1000005
using namespace std;
ll Mod,n;
struct node
{
	ll a[5][5];
}a,b,c;
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
ll f[Max],g[Max];
int main()
{
	cin>>n>>Mod;
	n++;
	f[1]=0;f[2]=0;f[3]=1;
	g[1]=1;g[2]=2;g[3]=4;
	for(int i=4;i<=n;i++)
	{
		f[i]=f[i-1]+g[i-2];
		g[i]=g[i-2]+g[i-1]+1;
		f[i]%=Mod;
		g[i]%=Mod;
	//	cout<<i<<' '<<f[i]<<' '<<g[i]<<endl;
	}
	printf("%lld",qpw(f[n],n));
}
