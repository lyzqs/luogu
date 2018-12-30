#include <bits/stdc++.h>
#define ll long long 
#define il inline
#define mod 19260817
using namespace std;
ll n,m;
struct node
{
	ll c[15][15];
}a,b,k;
il ll read()
{
	char c=getchar();
	ll x=0;
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return x;
}
node fun(node x,node y,int k)
{
	node z;
	memset(z.c,0,sizeof(z.c));
	for(int i=1;i<=3;i++)
		for(int j=1;j<=k;j++)
			for(int k=1;k<=3;k++)
				z.c[i][j]=(z.c[i][j]+x.c[i][k]*y.c[k][j])%mod;
	return z;
}
node qpw(node a,ll b)
{
	node ans=k;
	while(b)
	{
		if(b&1) ans=fun(ans,a,3);
		a=fun(a,a,3);
		b>>=1;
	}
	return ans;
}
int main()
{
	m=read();
	for(int i=1;i<=3;i++) 
		k.c[i][i]=1;	
	while(m--)
	{
		n=read();
		memset(a.c,0,sizeof(a.c));
		memset(b.c,0,sizeof(b.c));
		a.c[1][1]=a.c[1][2]=a.c[1][3]=a.c[2][1]=a.c[3][2]=1;
		b.c[1][1]=1;
		b=fun(qpw(a,n),b,1);
		printf("%lld\n",(b.c[1][1]+b.c[2][1]+b.c[3][1])%mod);
	}
}
