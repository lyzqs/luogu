#include <bits/stdc++.h>
#define il inline
#define Max 300005
#define rg register
using namespace std;
il int read()
{
	char c=getchar();
	int x=0,f=1;
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
int n,m,k,p,ans=0;
int f[Max],v[Max],w[Max],t[Max],c[Max];
int main()
{
	n=read(),m=read(),k=read(),p=read();
	for(rg int i=1;i<=n;i++)
	{
		v[i]=read(),w[i]=read();
	}
	for(rg int i=1;i<=k;i++)
	{
		t[i]=read();
		c[i]=read();
	}
	for(rg int i=1;i<=n;i++)
	{
		for(rg int j=m;j>=v[i];j--)
		{
			f[j]=max(f[j],f[j-v[i]]+w[i]);
		}
	}
	p+=f[m];
	for(rg int i=1;i<=k;i++)
	{
		if(t[i]*p>=c[i]) ans++;
	}
	if(ans==k) puts("AC");
	else cout<<ans<<endl;
}
