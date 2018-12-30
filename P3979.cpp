#include <bits/stdc++.h>
#define il inline
#define Max 1000005
#define rg register
#define int long long
#define ls(x) x<<1
#define rs(x) x<<1|1
#define dg puts("qwq")
//#define getchar() (tt==ss&&(tt=(ss=In)+fread(In,1,Max,stdin),tt==ss)?EOF:*ss++)
using namespace std;
char In[Max],*ss=In,*tt=In;
il int read()
{
	char c=getchar();
	int x=0;
	while(c>'9'||c<'0')
	{
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return x;
}
struct node
{
	int t,nt;
}e[Max<<1];
int head[Max],tot,cnt,t[Max<<2],tg[Max<<2],dfn[Max],tp[Max],wsn[Max],n,m,rt,w[Max],f[Max],rk[Max],sz[Max],d[Max];
il void add(int u,int v)
{
	e[++tot].t=v;
	e[tot].nt=head[u];
	head[u]=tot;
}
il void dfs1(int u,int fa)
{
	d[u]=d[fa]+1;sz[u]=1;f[u]=fa;
	for(int i=head[u];i;i=e[i].nt)
	{
		int v=e[i].t;
		if(v==fa) continue;
		dfs1(v,u);
		sz[u]+=sz[v];
		if(sz[v]>sz[wsn[u]]) wsn[u]=v;
	}
}
il void dfs2(int u,int top)
{
	tp[u]=top;
	dfn[u]=++cnt;
	rk[cnt]=u;
	if(wsn[u]) dfs2(wsn[u],top);
	for(int i=head[u];i;i=e[i].nt)
	{
		int v=e[i].t;
		if(v==f[u]||v==wsn[u]) continue;
		dfs2(v,v);
	}
}
il int Lca(int x,int y)
{
	while(tp[x]!=tp[y])
	{
		if(d[tp[x]]<d[tp[y]]) swap(x,y);
		x=f[tp[x]];
	}
	return d[x]<d[y]?x:y;
}
il void pushup(int x)
{
	t[x]=min(t[ls(x)],t[rs(x)]);
}
il void pushdown(int x)
{
	if(tg[x]==-1) return;
	tg[ls(x)]=t[ls(x)]=tg[x];
	tg[rs(x)]=t[rs(x)]=tg[x];
	tg[x]=-1;
}
il void build(int x,int l,int r)
{
	tg[x]=-1;
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
il void mdf(int x,int l,int r,int ql,int qr,int k)
{
	//dg;
	if(ql<=l&&r<=qr)
	{
		tg[x]=t[x]=k;
		return;
	}
	int mid=(l+r)>>1;
	pushdown(x);
	if(ql<=mid) mdf(ls(x),l,mid,ql,qr,k);
	if(qr>mid) mdf(rs(x),mid+1,r,ql,qr,k);
	pushup(x);
}
il int qry(int x,int l,int r,int ql,int qr)
{
	//dg;
	if(ql<=l&&r<=qr)
	{
		return t[x];
	}
	pushdown(x);
	int mid=(l+r)>>1;
	int res=1e17;
	if(ql<=mid) res=min(res,qry(ls(x),l,mid,ql,qr));
	if(qr>mid) res=min(res,qry(rs(x),mid+1,r,ql,qr));
	pushup(x);
	return res;
}
il void modify(int x,int y,int w)
{
	while(tp[x]!=tp[y])
	{
		//dg;
		if(d[tp[x]]<d[tp[y]]) swap(x,y);
		mdf(1,1,n,dfn[tp[x]],dfn[x],w);
		x=f[tp[x]];
	}
	if(dfn[x]>dfn[y]) swap(x,y);
	mdf(1,1,n,dfn[x],dfn[y],w);
}
il int find(int u)
{
	if(u==rt) return -1;
	if(dfn[u]>=dfn[rt]||dfn[u]+sz[u]-1<dfn[rt]) return 0;
	int v=rt;
	while(tp[u]!=tp[v])
	{
		if(f[tp[v]]==u) return tp[v];
		v=f[tp[v]];
	}
	return wsn[u];
}
il int work(int u)
{
	int v=find(u);
	if(v==-1) return t[1];
	if(v==0) return qry(1,1,n,dfn[u],dfn[u]+sz[u]-1);
	else
	{
		int ans=qry(1,1,n,1,dfn[v]-1);
		if(dfn[v]+sz[v]-1!=n) ans=min(ans,qry(1,1,n,dfn[v]+sz[v],n));
		return ans;
	}
}
signed main()
{
	sz[0]=-1;
	n=read(),m=read();
	for(int i=1;i<n;i++)
	{
		int u=read(),v=read();
		add(u,v),add(v,u);
	}
	for(int i=1;i<=n;i++) w[i]=read();
	rt=read();
	dfs1(rt,1);
	dfs2(rt,rt);
	build(1,1,n);
	while(m--)
	{
		int opt=read();
		if(opt==1)
		{
			rt=read();
		}
		else if(opt==2)
		{
			int u=read(),v=read(),w=read();
			modify(u,v,w);
		}
		else if(opt==3)
		{
			int u=read();
			printf("%lld\n",work(u));
		}
	}
}
