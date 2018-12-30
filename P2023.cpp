#include <bits/stdc++.h>
#define il inline
#define ll long long
#define Max 500005
using namespace std;
ll n,m,p,t[Max<<2],tgc[Max<<2],tgj[Max<<2],a[Max];
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
il ll ls(ll u)
{
	return u<<1;
}
il ll rs(ll u)
{
	return u<<1|1;
}
il void pushup(ll x)
{
	t[x]=(t[ls(x)]+t[rs(x)])%p;
}
il void wkc(ll x,ll k)
{
	t[x]=(t[x]*k)%p;
	tgc[x]=(tgc[x]*k)%p;
	tgj[x]=(tgj[x]*k)%p;
}
il void wkj(ll x,ll l,ll r,ll k)
{
	tgj[x]=(tgj[x]+k)%p;
	t[x]=t[x]+k*(r-l+1);
	t[x]%=p;
}
il void pushdown(ll x,ll l,ll r)
{
	wkc(ls(x),tgc[x]);
	wkc(rs(x),tgc[x]);
	tgc[x]=1;
	ll mid=(l+r)>>1;
	wkj(ls(x),l,mid,tgj[x]);
	wkj(rs(x),mid+1,r,tgj[x]);
	tgj[x]=0;
}
il void build(ll x,ll l,ll r)
{
	tgc[x]=1;
	if(l==r)
	{
		t[x]=a[l];
		return;
	}
	ll mid=(l+r)>>1;
	build(ls(x),l,mid);
	build(rs(x),mid+1,r);
	pushup(x);
}
il void add(ll x,ll l,ll r,ll ql,ll qr,ll k)
{
	if(ql<=l&&r<=qr)
	{
		t[x]+=(r-l+1)*k;
		t[x]%=p;
		tgj[x]+=k;
		tgj[x]%=p;
		return;
	}
	pushdown(x,l,r);
	ll mid=(l+r)>>1;
	if(ql<=mid) add(ls(x),l,mid,ql,qr,k);
	if(qr>mid) add(rs(x),mid+1,r,ql,qr,k);
	pushup(x);
}
il void mul(ll x,ll l,ll r,ll ql,ll qr,ll k)
{
	if(ql<=l&&r<=qr)
	{
		t[x]=(t[x]*k)%p;
		tgj[x]=(tgj[x]*k)%p;
		tgc[x]=(tgc[x]*k)%p;
		return;
	}
	pushdown(x,l,r);
	ll mid=(l+r)>>1;
	if(ql<=mid) mul(ls(x),l,mid,ql,qr,k);
	if(qr>mid) mul(rs(x),mid+1,r,ql,qr,k);
	pushup(x);
}
il ll qsum(ll x,ll l,ll r,ll ql,ll qr)
{
	if(ql<=l&&r<=qr) return t[x];
	pushdown(x,l,r);
	ll mid=(l+r)>>1,res=0;
	//printf("qwq\n");
	//cout<<x<<' '<<l<<' '<<r<<endl;
	if(ql<=mid) res+=qsum(ls(x),l,mid,ql,qr),res%=p;
	if(qr>mid) res+=qsum(rs(x),mid+1,r,ql,qr),res%=p;
	pushup(x);
	return res%p;
}
int main()
{
	n=read(),p=read();
	for(int i=1;i<=n;i++) a[i]=read();
	build(1,1,n);
	m=read();
	while(m--)
	{
		ll opt=read(),l=read(),r=read();
		if(opt==1)
		{
			ll c=read();
			mul(1,1,n,l,r,c);
		}
		if(opt==2)
		{
			ll c=read();
			add(1,1,n,l,r,c);
		}
		if(opt==3)
		{
			printf("%lld\n",qsum(1,1,n,l,r));
		}
	}
}
