#include <bits/stdc++.h>
#define ll long long
#define il inline
#define N 100005
using namespace std;
struct node
{
	int t,nt;
}e[N<<1];
int head[N],tot,cnt,d[N],f[N],size[N],wson[N],dfn[N],top[N],rk[N],n,a[N];
int Sum[N<<2],Max[N<<2];
il int read()
{
	char c=getchar();
	int x=0,num=1;
	while(c>'9'||c<'0')
	{
		if(c==-1) return 0;
		if(c=='-') num=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return (x*num);
}
il void add(int u,int v)
{
	e[++tot].t=v;
	e[tot].nt=head[u];
	head[u]=tot;
}
il int ls(int nw)
{
	return nw<<1;
}
il int rs(int nw)
{
	return nw<<1|1;
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
		if(v==f[u]||v==wson[u]) continue;
		dfs2(v,v);
	}
}
il void pushup(int x)
{
	Sum[x]=Sum[ls(x)]+Sum[rs(x)];
	Max[x]=max(Max[ls(x)],Max[rs(x)]);
}
il void build(int x,int l,int r)
{
	if(l==r) 
	{
		Max[x]=a[rk[l]];
		Sum[x]=a[rk[l]];
		return;
	}
	int mid=(l+r)>>1;
	build(ls(x),l,mid);
	build(rs(x),mid+1,r);
	pushup(x);
}
il void update(int x,int l,int r,int q,int v)
{
	if(l==r)
	{
		Sum[x]=Max[x]=v;
		return;
	}
	int mid=(l+r)>>1;
	if(q<=mid) update(ls(x),l,mid,q,v);
	else update(rs(x),mid+1,r,q,v);
	pushup(x);
}
il int qsum(int x,int l,int r,int ql,int qr)
{
	if(ql<=l&&r<=qr) return Sum[x];
	int ans=0,mid=(l+r)>>1;
	if(ql<=mid) ans+=qsum(ls(x),l,mid,ql,qr);
	if(mid<qr) ans+=qsum(rs(x),mid+1,r,ql,qr);
	pushup(x);
	return ans;
}
il int qmax(int x,int l,int r,int ql,int qr)
{
	if(ql<=l&&r<=qr) return Max[x];
	int ans=-2147483647,mid=(l+r)>>1;
	if(ql<=mid) ans=max(qmax(ls(x),l,mid,ql,qr),ans);
	if(mid<qr) ans=max(ans,qmax(rs(x),mid+1,r,ql,qr));
	pushup(x);
	return ans;
}
il int qs(int l,int r)
{
	int tl=top[l],tr=top[r],ans=0;
	while(tl!=tr)
	{
		if(d[tl]<d[tr]) swap(tr,tl),swap(l,r);
		ans+=qsum(1,1,n,dfn[tl],dfn[l]);
		l=f[tl];tl=top[l];
 	}
 	if(dfn[l]>dfn[r]) swap(l,r);
 	ans+=qsum(1,1,n,dfn[l],dfn[r]);
 	return ans;
}
il int qm(int l,int r)
{
	int tl=top[l],tr=top[r],ans=-2147483647;
	while(tl!=tr)
	{
		if(d[tl]<d[tr]) swap(tr,tl),swap(l,r);
		ans=max(ans,qmax(1,1,n,dfn[tl],dfn[l]));
		l=f[tl];tl=top[l];
 	}
 	if(dfn[l]>dfn[r]) swap(l,r);
 	ans=max(ans,qmax(1,1,n,dfn[l],dfn[r]));
 	return ans;
}
int main()
{
	n=read();
	for(int i=1;i<=n-1;i++)
	{
		int u=read(),v=read();
		add(u,v),add(v,u);
	}
	for(int i=1;i<=n;i++) a[i]=read();
	dfs1(1,0);
	dfs2(1,1);
	build(1,1,n);
	int q=read();
	while(q--)
	{
		char s[10];
		scanf("%s",s);
		int x=read(),y=read();
		if(s[1]=='H') update(1,1,n,dfn[x],y);
		if(s[1]=='M') printf("%d\n",qm(x,y));
		if(s[1]=='S') printf("%d\n",qs(x,y));
	}
}
