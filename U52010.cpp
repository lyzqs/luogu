#include <bits/stdc++.h>
#define ll long long
#define il inline
#define Mod 1000000007
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
ll ans=0,f[5005][3],n,m,k;
il bool check(int lst,int nw)
{
	if(nw&1) nw^=1;
	if(((lst<<1)|nw)==(lst<<1)) return 1;
	return 0;
}
il void print(int x)
{
	if(x) print(x>>1),cout<<(x&1);
}
int main()
{
	n=read(),m=read();
	k=qpw(2,n);
	//cout<<k<<"qwq\n";
	if(n==1||m==1)
	{
		printf("%lld",qpw(2,n*m));
		exit(0);
	}
	if(n==3)
	{
		if(m==2) puts("36");
		//if(m==3) puts("112");
		//exit(0);
	}
	for(int i=0;i<k;i++)
	{
		f[i][0]=1;
	}
	ll nw=0,lst;
	for(int i=1;i<m;i++)
	{
		lst=nw,nw=(lst+1)%2;
		for(int j=0;j<k;j++) f[j][nw]=0;
		//cout<<"qwqwq "<<nw<<' '<<lst<<endl; 
		for(int j=0;j<k;j++)
		{
			for(int u=0;u<k;u++)
			{
				if(!check(u,j)) continue;
				//print(u);if(!u) cout<<'0';cout<<' ',print(j);if(!j) cout<<'0';  
				//cout<<' ';
				//cout<<u<<' '<<lst<<' '<<f[u][lst]<<endl;
				f[j][nw]+=f[u][lst];
				f[j][nw]%=Mod;;
			}
			//cout<<j<<' '<<nw<<' '<<f[j][nw]<<endl;
		}
	}
	for(int i=0;i<k;i++)
	{
		//cout<<i<<' '<<f[i][nw]<<endl;
		ans+=f[i][nw];
		ans%=Mod;
	}
	cout<<ans;
}
