#include <bits/stdc++.h>
#define ll long long
#define Max 2000005
using namespace std;
ll n,mod;
ll s[Max],p[Max],fp[Max],pnum=0,k,t,q,ans=1;
ll qpw(ll x,ll y)
{
	ll Ans=1;
	while(y)
	{
		if(y&1) Ans=(Ans*x)%mod;
		x=(x*x)%mod;
		y>>=1;
	}
	return Ans;
}
int main()
{
	scanf("%lld%lld",&n,&mod);
	//n-=2;
	fp[1]=1;
	for(ll i=2;i<=2*n;i++)
	{
	 	if(!fp[i]) p[++pnum]=i,fp[i]=i;
		for(ll j=1;j<=pnum&&p[j]*i<=2*n;j++)
		{
		 	fp[i*p[j]]=p[j];
			if(i%p[j]==0) break;	
		}
	}
	//for(int i=1;i<=pnum;i++) printf("%d ",p[i]); 
	//k=2*n;
	
	for(int i=n*2;i>=1;i--)
	{
		k=i;
		while(k>1)
		{
			s[fp[k]]++;
			k/=fp[k];
		}
	}
	
	for(int i=2;i<=n;i++)
	{
		k=i;
		while(k>1)
		{
			s[fp[k]]--;
			k/=fp[k];
		}
	}
	
	for(int i=2;i<=n+1;i++)
	{
		k=i;
		while(k>1)
		{
			s[fp[k]]--;
			k/=fp[k];
		}
	}
	//for(int i=1;i<=n*2;i++)
	//printf("%d %d\n",i,s[i]);
	for(ll i=1;i<=pnum;i++)
	{
		if(s[p[i]]!=0)
		{
			ans*=qpw(p[i],s[p[i]]);
			ans%=mod;
		}
	}
	printf("%lld",ans);
}
