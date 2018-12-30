#include <bits/stdc++.h>
#define il inline
#define Max 25
#define Max2 100005
#define ll long long
#define Mod 998244353
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
il ll read()
{
	ll x=0;
	char c=getchar();
	while(c>'9'||c<'0') c=getchar();
	while(c>='0'&&c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return x;
}
ll n,m,cnt[Max2][2],c[105][105],w[Max2],f[Max];
ll ans=0;
int main()
{
	for(int i=1;i<=100;i++) c[i][i]=c[i][0]=1;
	for(int i=1;i<=100;i++)
		for(int j=1;j<i;j++)
			c[i][j]=(c[i-1][j-1]+c[i-1][j])%Mod;
	n=read();m=read();//cout<<"n:"<<n<<endl;
	f[n]=1;
	for(int i=n-1;i>=0;i--)
	{
		for(int j=n;j>i;j--)
		{
			f[i]+=f[j]*c[n-i][j-i];
			f[i]%=Mod;
		}
		//cout<<i<<' '<<f[i]<<" qwq\n";
	}
	for(int i=1;i<=m;i++)
	{
		char cc;
		for(int j=1;j<=n;j++)
		{
			cc='!';
			while(cc!='0'&&cc!='1') cc=getchar();
			//cout<<cc<<' '<<j<<" qwq\n";
			if(cc=='1') cnt[i][1]++;
			if(cc=='0') cnt[i][0]++;
		}
		w[i]=read();
		ans+=(w[i]*((f[cnt[i][1]]*f[cnt[i][0]])%Mod))%Mod;
		ans%=Mod;
	}
	cout<<ans;
}
