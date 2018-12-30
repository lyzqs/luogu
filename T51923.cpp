#include <bits/stdc++.h>
#define il inline
#define Mod 1000000007
#define ll long long
#define Max 500005
using namespace std;
il ll read()
{
	char c=getchar();
	ll x=0;
	while(c>'9'||c<'0') c=getchar();
	while(c>='0'&&c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return x;
}
ll n,m,k,ans=0;
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
ll f[Max][10],t[Max][10],g[Max][10],c[1005][1005];
il void pre()
{
	for(int i=1;i<=1000;i++) c[i][i]=c[i][0]=1;
	for(int i=1;i<=1000;i++)
		for(int j=1;j<i;j++)
			c[i][j]=(c[i-1][j]+c[i-1][j-1])%Mod;
}
int main()
{
	n=read(),m=read(),k=read();
	if(m==1||m==0) cout<<0,exit(0);
	if(m==2) cout<<2,exit(0);
	for(int i=1;i<=k;i++)
	{
		t[i][0]=read();
		for(int j=1;j<=t[i][0];j++) t[i][j]=read();
	}
	for(int i=1;i<=t[1][0];i++) f[1][t[1][i]]=1;
	pre();
	//n++;t[k+1][0]=1;t[k+1][1]=8;
	for(int i=2;i<=n;i++)
	{
		int d=i%k;
		if(!d) d=k;
		int lst=d-1;
		if(!lst) lst=k;
		//if(i==n) d=k+1;
		for(int j=1;j<=t[d][0];j++)
		{
			for(int u=1;u<=t[lst][0];u++)
			{
				if(t[d][j]==t[lst][u]) continue;
				f[i][t[d][j]]+=f[i-1][t[lst][u]];
				g[i][t[d][j]]++;
				f[i][t[d][j]]%=Mod;
			}
			ll add=0;
			for(int u=2;g[i][t[d][j]]>=u;u++) add+=c[g[i][t[d][j]]][u],add%=Mod;
			cout<<i<<' '<<j<<' '<<t[d][j]<<' '<<g[i][t[d][j]]<<' '<<add<<"qwq\n";
			f[i][t[d][j]]+=add;
			f[i][t[d][j]]%=Mod;
		}
	}
	//cout<<f[3][3]<<"qwqqwqwq\n";
	int qwq=n%k;
	if(!qwq) qwq=k;
	for(int i=1;i<=t[qwq][0];i++) ans=(ans+f[n][t[qwq][i]])%Mod;
	for(int u=2;t[qwq][0]>=u;u++) ans+=c[t[qwq][0]][u],ans%=Mod;
	cout<<ans;
}
