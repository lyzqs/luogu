#include <bits/stdc++.h>
#define ll long long 
#define il inline
#define Max 1000005
using namespace std;
ll n,m,p,t[Max<<2],tgc[Max<<2],tgj[Max<<2],a[Max];
il ll ls(ll now)
{
	return now<<1;
}
il ll rs(ll now)
{
	return now<<1|1;
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
	t[x]+=k*(r-l+1);
	t[x]%=p;
}
il void pushup(ll x)
{
	t[x]=(t[ls(x)]+t[rs(x)])%p;
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
il void add(ll x,ll l,ll r,ll tl,ll tr,ll k)
{
	if(tl<=l&&r<=tr) 
	{
		t[x]+=(r-l+1)*k;
		t[x]%=p;
		tgj[x]+=k;
		tgj[x]%=p;
		return;
	}
	pushdown(x,l,r);
	ll mid=(l+r)>>1;
	if(tl<=mid) add(ls(x),l,mid,tl,tr,k);
	if(tr>mid) add(rs(x),mid+1,r,tl,tr,k);
	pushup(x);
}
il void mul(ll x,ll l,ll r,ll tl,ll tr,ll k)
{
	if(tl<=l&&r<=tr)
	{
		t[x]=(t[x]*k)%p;
		tgc[x]=(tgc[x]*k)%p;
		tgj[x]=(tgj[x]*k)%p;
		return;
	}
	pushdown(x,l,r);
	ll mid=(l+r)>>1;
	if(tl<=mid) mul(ls(x),l,mid,tl,tr,k);
	if(tr>mid) mul(rs(x),mid+1,r,tl,tr,k);
	pushup(x);
}
il ll qsum(ll x,ll l,ll r,ll ql,ll qr)
{
	if(ql<=l&&r<=qr) return t[x]%=p;
	pushdown(x,l,r);
	ll mid=(l+r)>>1,res=0;
	if(ql<=mid) res+=qsum(ls(x),l,mid,ql,qr),res%=p;
	if(qr>mid) res+=qsum(rs(x),mid+1,r,ql,qr),res%=p;
	return res%=p;
}
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
int main()
{
	n=read(),m=read(),p=read();
	for(int i=1;i<=n;i++) a[i]=read();
	build(1,1,n);
	while(m--)
	{
		ll f=read();
		if(f==1)
		{
			ll q1=read(),q2=read(),q3=read();
			mul(1,1,n,q1,q2,q3);
		}
		if(f==2)
		{
			ll q1=read(),q2=read(),q3=read();
			add(1,1,n,q1,q2,q3);
		}
		if(f==3)
		{
			ll q1=read(),q2=read();
			printf("%lld\n",qsum(1,1,n,q1,q2));
		}
	}
}
