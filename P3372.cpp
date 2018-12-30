#include <bits/stdc++.h>
#define ll long long
#define il inline
#define Max 100005
using namespace std;
ll t[Max<<2],tg[Max<<2],a[Max],n,m;
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
	t[x]=t[ls(x)]+t[rs(x)];
}
il void wk(ll x,ll l,ll r,ll k)
{
	tg[x]+=k;
	t[x]+=k*(r-l+1);
}
il void pushdown(ll x,ll l,ll r)
{
	ll mid=(l+r)/2;
	wk(ls(x),l,mid,tg[x]);
	wk(rs(x),mid+1,r,tg[x]);
	tg[x]=0;
}
il void build(ll x,ll l,ll r)
{
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
il void update(ll x,ll l,ll r,ll k,ll tl,ll tr)
{
	if(tl<=l&&r<=tr) 
	{
		t[x]+=k*(r-l+1);
		tg[x]+=k;
		return;
	}
	pushdown(x,l,r);
	ll mid=(l+r)>>1;
	if(tl<=mid) update(ls(x),l,mid,k,tl,tr);
	if(tr>mid) update(rs(x),mid+1,r,k,tl,tr);
	pushup(x);
}
il ll qsum(ll x,ll l,ll r,ll ql,ll qr)
{
	ll res=0;
	if(ql<=l&&r<=qr) return t[x];
	ll mid=(l+r)>>1;
	pushdown(x,l,r);
	if(ql<=mid) res+=qsum(ls(x),l,mid,ql,qr);
	if(qr>mid) res+=qsum(rs(x),mid+1,r,ql,qr);
	return res;
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
	for(int i=1;i<=n;i++) a[i]=read();
	build(1,1,n);
	
	while(m--)
	{
		int pd=read();
		if(pd==1)
		{
			ll q1=read(),q2=read(),q3=read();
			update(1,1,n,q3,q1,q2);
		}
		if(pd==2)
		{
			ll q1=read(),q2=read();
			printf("%lld\n",qsum(1,1,n,q1,q2));
		}
	}
	//for(int i=1;i<=n*2;i++) printf("%d ",t[i]);printf("\n");
	//for(int i=1;i<=n*2;i++) printf("%d ",tg[i]);printf("\n");
}
