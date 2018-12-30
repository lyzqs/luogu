#include <bits/stdc++.h>
#define il inline
#define ll long long 
#define Max 200005
#define ls(x) x<<1
#define rs(x) x<<1|1
#define int ll
#define dg puts("qwq")
using namespace std;
struct node
{
	int t,nt;
}e[Max<<1];
ll n,m,tot,head[Max],d[Max],cnt,f[Max],wsn[Max],sz[Max],tp[Max],dfn[Max],rk[Max];
ll t[Max<<2],tg[Max<<2],w[Max];
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
		x=x*10+c-'0';;
		c=getchar();
	}
	return x*f;
}
il void add(int u,int v)
{
	e[++tot].t=v;
	e[tot].nt=head[u];
	head[u]=tot;
}
il void dfs1(int u,int fa)
{
	//dg;
	d[u]=d[fa]+1;
	f[u]=fa;
	sz[u]=1;
	for(int i=head[u];i;i=e[i].nt)
	{
		int v=e[i].t;
		if(v==fa) continue;
		dfs1(v,u);
		sz[u]+=sz[v];
		if(sz[v]>sz[wsn[u]]) wsn[u]=v;
	}
}
il void dfs2(int u,int t)
{
	tp[u]=t;
	dfn[u]=++cnt;
	rk[cnt]=u;
	if(!wsn[u]) return;
	dfs2(wsn[u],t);
	for(int i=head[u];i;i=e[i].nt)
	{
		int v=e[i].t;
		if(v!=f[u]&&v!=wsn[u]) dfs2(v,v);
	}
}
il void pushup(int x)
{
	t[x]=t[ls(x)]+t[rs(x)];
}
il void wk(int x,int l,int r,int k)
{
	tg[x]+=k;
	t[x]+=(r-l+1)*k;
}
il void pushdown(int x,int l,int r)
{
	int mid=(l+r)>>1;
	wk(ls(x),l,mid,tg[x]);
	wk(rs(x),mid+1,r,tg[x]);
	tg[x]=0;
}
il void build(int x,int l,int r)
{
	if(l==r)
	{
		t[x]=w[rk[l]];
		return;
	}
	int mid=(l+r)>>1;
	build(ls(x),l,mid);
	build(rs(x),mid+1,r);
	pushup(x);
}
il void add(int x,int l,int r,int ql,int qr,int k)
{
	if(ql<=l&&r<=qr)
	{
		t[x]+=k*(r-l+1);
		tg[x]+=k;
		return;
	}
	pushdown(x,l,r);
	int mid=(l+r)>>1;
	if(ql<=mid) add(ls(x),l,mid,ql,qr,k);
	if(qr>mid) add(rs(x),mid+1,r,ql,qr,k);
	pushup(x);
}
il int query(int x,int l,int r,int ql,int qr)
{
	//dg;
	if(ql<=l&&r<=qr)
	{
		return t[x];
	}
	pushdown(x,l,r);
	int mid=(l+r)>>1,res=0;
	//cout<<ql<<' '<<mid<<' '<<qr<<endl;
	if(ql<=mid) res+=query(ls(x),l,mid,ql,qr);
	if(qr>mid) res+=query(rs(x),mid+1,r,ql,qr);
	pushup(x);
	return res;
}
il int qsum(int x,int y)
{
	ll res=0;
	int tx=tp[x],ty=tp[y];
	while(tx!=ty)
	{
		//dg;
		if(d[tx]<d[ty]) swap(tx,ty),swap(x,y);
		//cout<<dfn[tx]<<' '<<dfn[x]<<endl;
		res+=query(1,1,n,dfn[tx],dfn[x]);
		x=f[tx];tx=tp[x];
		//dg;
	}
	//dg;
	if(dfn[x]>dfn[y]) swap(x,y);
	res+=query(1,1,n,dfn[x],dfn[y]);
	return res;
}
signed main()
{
	//freopen("P3178.in","r",stdin);
	n=read(),m=read();
	for(int i=1;i<=n;i++) w[i]=read();
	for(int i=1;i<=n-1;i++)
	{
		int u=read(),v=read();
		add(u,v),add(v,u);
	}
	dfs1(1,0);
	dfs2(1,1);
	build(1,1,n);
	while(m--)
	{
		int opt=read(),x=read();
		if(opt==1)
		{
			int a=read();
			add(1,1,n,dfn[x],dfn[x],a);
		}
		if(opt==2)
		{
			int a=read();
			add(1,1,n,dfn[x],dfn[x]+sz[x]-1,a);
		}
		if(opt==3)
		{
			//dg;
			printf("%lld\n",qsum(1,x));
		}
		//dg;
	}
}
