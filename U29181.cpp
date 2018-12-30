#include <bits/stdc++.h>
using namespace std;
#define ll long long
int mod=998244353;
int n,k,s[35],tot=0,m;
char c;
ll qpw(int a,int b)
{
	ll ans=1;
	while(b)
	{
		if(b&1) ans=(1ll*ans*a)%mod;
		a=(1ll*a*a)%mod;
		b>>=1;
	}
	return ans;
}
int main()
{
	scanf("%d",&n);
	k=1;
	for(int i=1;i<=n;i++)
	{
		c=getchar();c=getchar();
		int l=c-'a'+1;
		//printf("%d\n",l);
		s[l]=1;
		//printf("%c",c);
	}
	for(int i=1;i<=26;i++)
	{
		if(!s[i]) tot++;
	}
	cin>>m;
	//cout<<tot;
	//cout<<m; 
	cout<<qpw(tot,m);
}
