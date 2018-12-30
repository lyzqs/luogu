#include <bits/stdc++.h>
#define ll long long
#define il inline
#define Max 50005
#define inf 1000000000
using namespace std;
ll st[Max<<2],mt[Max<<2],tg[Max<<2],a[Max],n,m;
il ll ls(ll now) 
{
	return now<<1;
}
il ll rs(ll now)
{
	return now<<1|1;
}
il void pushup(ll x)
{
	st[x]=st[ls(x)]^st[rs(x)];
	mt[x]=max(max(mt[ls(x)],mt[rs(x)]),st[x]);
}
/*
il void build(ll x,ll l,ll r)
{
	if(l==r)
	{
		st[x]=a[l];
		mt[x]=a[l];
		return;
	}
	ll mid=(l+r)>>1;
	build(ls(x),l,mid);
	build(rs(x),mid+1,r);
	pushup(x);
}*/
il void update(ll x,ll l,ll r,ll pos,ll k)
{
	// if(l>pos||r<pos) return;
	if(l==r) 
	{
		st[x]=k;
		mt[x]=k;
		return;
	}
	ll mid=(l+r)>>1;
	if(pos<=mid) update(ls(x),l,mid,pos,k);
	else update(rs(x),mid+1,r,pos,k);
	pushup(x);
}
il ll qmax(ll x,ll l,ll r,ll ql,ll qr)
{
	if (ql<=l&&r<=qr) return st[x];
	ll mid=(l+r)>>1,ans=0;
	if(ql<=mid) ans=max(max(ans,qmax(ls(x),l,mid,ql,qr)),ans^qmax(ls(x),l,mid,ql,qr));
	if(qr>mid) ans=max(max(ans,qmax(rs(x),mid+1,r,ql,qr)),ans^qmax(rs(x),mid+1,r,ql,qr));
	pushup(x);
	return ans;
}
il ll read()
{
	char c=getchar();
	ll x=0;
	while(c>'9'||c<'0')c=getchar();
	while(c>='0'&&c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return x;
}
int main()
{
	n=read(),m=read();
	for(int i=1;i<=n;i++)
	{
		ll flag=read(),l=read(),r=read();
		if(flag==1)
		{
			update(1,1,n,l,r);
		}
		if(flag==2)
		{
			printf("%lld\n",qmax(1,1,n,l,r));
		}
	}
}
