#include <bits/stdc++.h>
#define il inline
#define Max 20005
#define Mod 998244353
#define ll long long 
using namespace std;
int f[1005][Max<<1],n,a[Max],m=0,cnt[Max];
ll ans=0;
il int read()
{
	char c=getchar();
	int x=0;
	while(c>'9'||c<'0') c=getchar();
	while(c>='0'&&c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return x;
}
int main()
{
	n=read();
	for(int i=0;i<=40000;i++) f[1][i]=1;
	for(int i=1;i<=n;i++) f[i][0]=1;
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		cnt[a[i]]++;
		m=max(m,a[i]);
	}
	//sort(a+1,a+1+n);
	//for(int i=1;i<=n;i++) cout<<a[i]<<' ';
	//cout<<"\n";
	//for(int i=1;i<=Max;i++) if(cnt[i]>0)ans+=pow(2,cnt[i]-1);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
		{
			//pp(i,j);
			f[i][a[i]-a[j]+Max]=((ll)f[i][a[i]-a[j]+Max]+f[j][a[i]-a[j]+Max]+1)%Mod;
			if(i!=j) f[j][a[i]-a[j]+Max]=0;
		//	cout<<a[i]<<' '<<a[j]<<' '<<a[i]-a[j]<<' '<<f[i][a[i]-a[j]]<<' '<<f[j][a[i]-a[j]]<<endl;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
		{
			ans=(ans+f[i][a[i]-a[j]+Max])%Mod;
			//cout<<a[i]<<' '<<a[j]<<' '<<f[i][a[i]-a[j]+Max]<<endl;
			//ans+=f[i][0];
		}
		//if(a[i]==a[i-1]) f[i][0]=f[i-1][0]<<1;
	}
	cout<<ans-n;
}
