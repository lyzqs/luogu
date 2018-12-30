#include <bits/stdc++.h>
#define ll long long
#define il inline
#define Max 100005
using namespace std;
ll t[Max<<2],t2[Max<<2],tg[Max<<2],a[Max],n,m,ans=0;
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
	t[x]=min(t[ls(x)],t[rs(x)]);
	if(t[x]==t[ls(x)])
		t2[x]=t2[ls(x)];
	else t2[x]=t2[rs(x)];
}
il void wk(ll x,ll k)
{
	tg[x]+=k;
	t[x]-=k;
}
il void pushdown(ll x)
{
	wk(ls(x),tg[x]);
	wk(rs(x),tg[x]);
	tg[x]=0;
}
il void build(ll x,ll l,ll r)
{
	if(l==r)
	{
		t[x]=a[l];
		t2[x]=l;
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
		t[x]-=k;
		tg[x]+=k;
		return;
	}
	pushdown(x);
	ll mid=(l+r)>>1;
	if(tl<=mid) update(ls(x),l,mid,k,tl,tr);
	if(tr>mid) update(rs(x),mid+1,r,k,tl,tr);
	pushup(x);
}
struct node
{
	ll w,id;
};
il node min(node a,node b)
{
	return a.w<b.w?a:b;
}
il node qmin(ll x,ll l,ll r,ll ql,ll qr)
{
	node res=(node){(ll)1e16,0};
	if(ql<=l&&r<=qr) return (node){t[x],t2[x]};
	ll mid=(l+r)>>1;
	pushdown(x);
	if(ql<=mid) res=min(res,qmin(ls(x),l,mid,ql,qr));
	if(qr>mid) res=min(res,qmin(rs(x),mid+1,r,ql,qr));
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
il void work(ll l,ll r)
{
	if(l>=r)
	{
		if(l==r) ans+=qmin(1,1,n,l,r).w;//cout<<l<<' '<<qmin(1,1,n,l,r).w<<endl;
		return;
	}
	node qwq=qmin(1,1,n,l,r);
	ans+=qwq.w;
	//cout<<l<<' '<<r<<' '<<qwq.w<<endl;
	update(1,1,n,qwq.w,l,r);
	work(l,qwq.id-1),work(qwq.id+1,r);
}
int main()
{
	n=read();
	for(int i=1;i<=n;i++) a[i]=read();
	build(1,1,n);
	work(1,n);
	cout<<ans;
	//for(int i=1;i<=n*2;i++) printf("%d ",t[i]);printf("\n");
	//for(int i=1;i<=n*2;i++) printf("%d ",tg[i]);printf("\n");
}
