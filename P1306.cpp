#include <bits/stdc++.h>
#define ll long long
#define il inline
#define Mod 100000000
using namespace std;
il ll gcd(ll a,ll b)
{
	if(a%b==0) return b;
	return gcd(b,a%b);
}
struct node
{
	ll m[4][4];
}res,a,b,c;
ll x,y,ans;
il node mul(node u,node v)
{
	node w;
	memset(w.m,0,sizeof(w.m));
	for(int i=1;i<=2;i++)
		for(int j=1;j<=2;j++)
			for(int k=1;k<=2;k++)
				w.m[i][j]+=u.m[i][k]*v.m[k][j],w.m[i][j]%=Mod;
	return w;
}
il ll qpw(ll t)
{
	res=c;
	while(t)
	{
		if(t&1) res=mul(res,b);
		b=mul(b,b);
		t>>=1;
	}
	//mul(c,res);
	return res.m[1][1];
}
int main()
{
	for(int i=0;i<=3;i++) a.m[i][i]=1;
	cin>>x>>y;
	b.m[1][1]=b.m[1][2]=b.m[2][1]=1;
	c.m[1][1]=c.m[1][2]=1;
	ans=gcd(x,y);
	if(ans<=2) cout<<1,exit(0);
	ans=qpw(ans-2);
	cout<<ans;
}
