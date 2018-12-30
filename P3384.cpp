#include <bits/stdc++.h>
#define ll long long 
#define il inline
#define Max 100005
using namespace std;
ll n,m,p,r,head[Max],tot,cnt,d[Max],f[Max],size[Max],top[Max],dfn[Max],rk[Max],wson[Max];
ll t[Max<<2],tg[Max<<2],a[Max];
struct node 
{
	int t,nt;
}e[Max<<1];
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
il void add(int u,int v)
{
	e[++tot].t=v;
	e[tot].nt=head[u];
	head[u]=tot;
}
il void dfs1(int u,int fa)
{
	d[u]=d[fa]+1;
	f[u]=fa;
	size[u]=1;
	for(int i=head[u];i;i=e[i].nt)
	{
		int v=e[i].t;
		if(v==fa) continue;
		dfs1(v,u);
		size[u]+=size[v];
		if(size[v]>size[wson[u]]) wson[u]=v; 
	}
}
il void dfs2(int u,int t)
{
	top[u]=t;
	dfn[u]=++cnt;
	rk[cnt]=u;
	if(!wson[u]) return;
	dfs2(wson[u],t);
	for(int i=head[u];i;i=e[i].nt)
	{
		int v=e[i].t;
		if(v!=f[u]&&v!=wson[u]) dfs2(v,v);
	}
}
il ll ls(ll nw)
{
	return (nw<<1);
}
il ll rs(ll nw)
{
	return (nw<<1|1);
}
il void pushup(ll nw)
{
	t[nw]=(t[ls(nw)]+t[rs(nw)])%p;
}
il void wk(ll x,ll l,ll r,ll k)
{
	tg[x]=(tg[x]+k)%p;
	t[x]=(t[x]+k*(r-l+1))%p;
}
il void pushdown(ll x,ll l,ll r)
{
	ll mid=(l+r)>>1;
	wk(ls(x),l,mid,tg[x]);
	wk(rs(x),mid+1,r,tg[x]);
	tg[x]=0;
}
il void build(ll x,ll l,ll r)
{
	if(l==r) 
	{
		t[x]=a[rk[l]];
		return;
	}
	ll mid=(l+r)>>1;
	build(ls(x),l,mid);
	build(rs(x),mid+1,r);
	pushup(x);
}
il void update(ll x,ll l,ll r,ll tl,ll tr,ll k)
{
	if(tl<=l&&r<=tr)
	{
		t[x]+=k*(r-l+1);
		t[x]%=p;
		tg[x]+=k;
		tg[x]%=p;
		return;
	}
	pushdown(x,l,r);
	ll mid=(l+r)>>1;
	if(tl<=mid) update(ls(x),l,mid,tl,tr,k);
	if(tr>mid) update(rs(x),mid+1,r,tl,tr,k);
	pushup(x);
}
il ll qsum(ll x,ll l,ll r,ll ql,ll qr)
{
	if(ql<=l&&r<=qr)
	{
		return t[x];
	}
	ll mid=(l+r)>>1,ans=0;
	if(ql<=mid) ans=(ans+qsum(ls(x),l,mid,ql,qr))%p;
	if(qr>mid) ans=(ans+qsum(ls(x),mid+1,r,ql,qr))%p;
	pushup(x);
	return ans;
}
il void updates(ll x,ll y,ll k)
{
	ll tx=top[x],ty=top[y];
	while(tx!=ty)
	{
		if(d[tx]<d[ty]) swap(tx,ty),swap(x,y);
		update(1,1,n,dfn[tx],dfn[x],k);
		x=f[tx],tx=top[x];
	}
	if(d[x]>d[y]) swap(x,y);
	update(1,1,n,dfn[x],dfn[y],k);
}
il ll qs(ll x,ll y)
{
	ll ans=0;
	ll tx=top[x],ty=top[y];
	while(tx!=ty)
	{
		if(d[tx]<d[ty]) swap(tx,ty),swap(x,y);
		ans=(ans+qsum(1,1,n,dfn[tx],dfn[x]))%p;
		x=f[tx],tx=top[x];
	}
	if(dfn[x]>dfn[y]) swap(x,y);
	ans=(ans+qsum(1,1,n,dfn[x],dfn[y]))%p;
	return ans%p;
}
int main()
{
	n=read(),m=read();r=read(),p=read();
	for(int i=1;i<=n;i++) a[i]=read(),a[i]%=p;
	for(int i=1;i<=n-1;i++) 
	{
		int u=read(),v=read();
		add(u,v);add(v,u);
	}
	dfs1(r,0);
	dfs2(r,r);
	build(1,1,n);
	for(int i=1;i<=n<<1;i++) printf("%lld ",t[i]);printf("\n");
	for(int i=1;i<=m;i++)
	{
		ll fg=read();
		if(fg==1) 
		{
			ll x=read(),y=read(),z=read();
			updates(x,y,z);
		}
		if(fg==2)
		{
			ll x=read(),y=read();
			printf("%lld\n",qs(x,y));
		}
		if(fg==3)
		{
			ll x=read(),y=read();
			update(1,1,n,dfn[x],dfn[x]+size[x]-1,y);
		}
		if(fg==4)
		{
			ll x=read();
			printf("%lld\n",qsum(1,1,n,dfn[x],dfn[x]+size[x]-1));
		}
	}
}
