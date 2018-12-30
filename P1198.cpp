#include <bits/stdc++.h>
#define il inline
#define Max 500005
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;
il ll read()
{
	char c=getchar();
	ll x=0,f=1;
	while(c>'9'||c<'0')
	{
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
ll n=0,m,p,a[Max],f[Max][31],x,t=0;
il void change(int u)
{
	f[u][0]=a[u];
	for(int i=1;u-(1<<i)>=0;i++)
	{
		f[u][i]=max(f[u][i-1],f[u-(1<<(i-1))][i-1]);
	}
}
il ll find(int l,int r)
{
	int k=(double)log(r-l+1)/log(2);
	return max(f[r][k],f[l+((1<<k)-1)][k]); 
}
int main()
{
	m=read(),p=read();
	for(int i=1;i<=m;i++)
	{
		char c=getchar();
		while(c!='A'&&c!='Q') c=getchar();
		x=read();
		//printf("qwq:%c %lld\n",c,t);
		if(c=='A')
		{
			a[++n]=(x+t)%p;
			change(n);
		}
		if(c=='Q')
		{
			t=find(n-x+1,n);
			printf("%lld\n",t);
		}
	}
}
