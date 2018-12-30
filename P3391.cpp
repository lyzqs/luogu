#include <bits/stdc++.h>
#define Max 100005
#define inf 2147483647
#define ll long long 
#define il inline
#define QWQ printf("%d?\n",root)
using namespace std;
struct splay
{
	int v,f,sz,s[2],tg,cnt;
}e[Max<<1];
int tot,n,m,root,a[Max];
il bool rlt(int x)
{
	return e[e[x].f].s[1]==x;
}
il int ls(int x)
{
	return e[x].s[0];
}
il int rs(int x)
{
	return e[x].s[1];
}
il void pushup(int x)
{
	if(x) e[x].sz=e[x].cnt;
	if(ls(x)) e[x].sz+=e[ls(x)].sz;
	if(rs(x)) e[x].sz+=e[rs(x)].sz;
}
il void pushdown(int x)
{
	if(x&&e[x].tg)
	{
		e[ls(x)].tg^=1;
		e[rs(x)].tg^=1;
		swap(e[x].s[0],e[x].s[1]);
		e[x].tg=0;
	}
}
il int build(int l,int r,int f)
{
	if(l>r) return 0;
	int mid=(l+r)>>1,p=++tot;
	e[p].f=f;
	e[p].s[0]=e[p].s[1]=0;
	e[p].cnt++;
	e[p].v=a[mid];
	e[p].sz++;
	e[p].s[0]=build(l,mid-1,p);
	e[p].s[1]=build(mid+1,r,p);
	pushup(p);
	//printf("%d: sz:%d ls:%d rs:%d v:%d\n",p,e[p].sz,ls(p),rs(p),e[p].v);
	return p;
}
il void rtt(int x)
{
	int f=e[x].f;
	int ff=e[f].f;
	pushdown(x),pushdown(f);
	int fs=rlt(x);
	e[f].s[fs]=e[x].s[fs^1];
	e[e[f].s[fs]].f=f;
	e[f].f=x;
	e[x].f=ff;
	e[x].s[fs^1]=f;
	if(ff)
		e[ff].s[e[ff].s[1]==f]=x;
	pushup(f);
}
il void splay(int x,int to)
{
	for(int u;(u=e[x].f)!=to;rtt(x))
	{
		if(e[u].f!=to)
		{
			rtt(rlt(x)==rlt(u)?u:x);
		}
	}
	if(to==0)
	{
		root=x;
	}
}
il int find(int x)
{
	int p=root;
	while(19260817)
	{
		pushdown(p);
		if(x<=e[ls(p)].sz)
		{
			p=ls(p);
			//printf("%d %d %d\n",x,p,e[ls(p)].sz);
			//QWQ;
		}
		else 
		{
			x-=(e[ls(p)].sz+1);
			if(!x) return p;
			p=rs(p);
			//QWQ;
		}
	}
}
il void rever(int x,int y)
{
	int l=x-1,r=y+1;
	l=find(l),r=find(r);
	//printf("233:%d %d\n",l,r);
	splay(l,0);
	splay(r,l);
	int p=rs(root);
	p=ls(p);
	e[p].tg^=1;
}
il void dfs(int nw)
{
	pushdown(nw);
	if(ls(nw)) dfs(ls(nw));
	if(e[nw].v!=-inf&&e[nw].v!=inf)
	{
		printf("%d ",e[nw].v);
	}
	if(rs(nw)) dfs(rs(nw));
}
int main()
{
	scanf("%d%d",&n,&m);
	a[1]=-inf,a[n+2]=inf;
	for(int i=1;i<=n;i++)
		a[i+1]=i;
	root=build(1,n+2,0);
	//printf("rt:%d\n",root);
	for(int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		rever(x+1,y+1);
	}
	dfs(root);
}
