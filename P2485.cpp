#include <bits/stdc++.h>
#define il inline
#define Max 100005
#define ll long long
using namespace std;
ll T,opt;
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
il ll qpw(ll a,ll b,ll p)
{
	ll res=1;
	while(b)
	{
		if(b&1) res=res*a%p;
		a=a*a%p;
		b>>=1;
	}
	return res%p;
}
map<ll,ll> h;
il void bsgs(ll y,ll z,ll p)
{
	h.clear();
	if(y==0&&z==0) 
	{
		puts("1");
		return;
	}
	if(y==0&&z!=0) 
	{
		puts("Orz, I cannot find x!");
		return;
	}
	ll m=sqrt(p)+0.5,qwq=0;
	for(ll i=0;i<=m;i++)
	{
		if(i==0) 
		{
			qwq=z%p;
			h[qwq]=i;
			continue;
		}
		qwq*=y;
		qwq%=p;
		h[qwq]=i;
	}
	ll t=qpw(y,m,p);
	qwq=1;
	for(ll i=1;i*i<=p;i++)
	{
		qwq*=t;
		qwq%=p;
		if(h[qwq])
		{
			ll res=(i*m)-h[qwq];
			res=res%p+p;
			res%=p;
			cout<<res<<endl;
			return;
		}
	}
	puts("Orz, I cannot find x!");
}
int main()
{
	T=read(),opt=read();
	while(T--)
	{
		ll y=read(),z=read(),p=read();
		y%=p;
		if(opt==1)
		{
			cout<<qpw(y,z,p)<<endl;
		}
		else if(opt==2)
		{
			z%=p;
			ll x=(z*qpw(y,p-2,p))%p;
			if((y%p==0)&&(z%p!=0)) cout<<"Orz, I cannot find x!\n";
			else
				cout<<x%p<<endl;
		}
		else if(opt==3)
		{
			bsgs(y,z,p);
		}
	}
}
