#include <bits/stdc++.h>
#define il inline
//inf must be 0x3f3f3f3f ,or int will boom
#define inf 0x3f3f3f3f//2147483647
#define ls(x) e[x].s[0]
#define rs(x) e[x].s[1]
#define S(x) e[x].sum
#define fa(x) e[x].f
#define sz(x) e[x].sz
#define mx(x) e[x].mx
#define lx(x) e[x].lx
#define rx(x) e[x].rx
#define Max 5000005
#define dg puts("qwq")
using namespace std;
il int read()
{
    char c=getchar();
    int x=0,f=1;
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
struct node
{
    int s[2],f,sz,c,rev,tg,v,lx,rx,mx,sum;
}e[Max];
int id[Max],cnt,rt,n,m,a[Max];
queue<int> q;
il void pushup(int x)
{
    int l=ls(x),r=rs(x);
    S(x)=S(l)+S(r)+e[x].v;
    sz(x)=sz(l)+sz(r)+1;
    mx(x)=max(mx(l),max(mx(r),rx(l)+e[x].v+lx(r)));
    //cout<<x<<' '<<mx(l)<<' '<<mx(r)<<' '<<rx(l)+e[x].v+lx(r)<<endl;
    lx(x)=max(lx(l),S(l)+e[x].v+lx(r));
    rx(x)=max(rx(r),S(r)+e[x].v+rx(l));
}
il void pushdown(int x)
{
    int l=ls(x),r=rs(x);
    if(e[x].tg)
    {
        e[x].rev=e[x].tg=0;
        if(l) e[l].tg=1,e[l].v=e[x].v,S(l)=e[x].v*sz(l);
        if(r) e[r].tg=1,e[r].v=e[x].v,S(r)=e[x].v*sz(r);
        if(e[x].v>=0)
        {
            if(l) lx(l)=rx(l)=mx(l)=S(l);
            if(r) lx(r)=rx(r)=mx(r)=S(r);
        }
        else
        {
            if(l) lx(l)=rx(l)=0,mx(l)=e[x].v;
            if(r) lx(r)=rx(r)=0,mx(r)=e[x].v;
        }
    }
    if(e[x].rev)
    {
        e[x].rev=0;
        e[l].rev^=1;
        e[r].rev^=1;
        swap(lx(l),rx(l)),
		swap(lx(r),rx(r));
        swap(ls(l),rs(l)),
		swap(ls(r),rs(r));
    }
}
il int rlt(int x)
{
    return rs(fa(x))==x;
}
il void ct(int x,int f,int k)
{
    fa(x)=f;
    e[f].s[k]=x;
}
il void rot(int x)
{
    int y=fa(x),z=fa(y),ys=rlt(x),zs=rlt(y),k=e[x].s[ys^1];
    //if(y==rt) rt=x;
    pushdown(x),pushdown(y);
    ct(k,y,ys),ct(y,x,ys^1),ct(x,z,zs);
    pushup(y),pushup(x);
}
il void splay(int x,int to)
{
    for(int y;(y=fa(x))!=to;rot(x))
    {
    	//dg;
    	//cout<<x<<' '<<y<<' '<<to<<endl;
        if(fa(y)==to) continue;
        else if(rlt(y)==rlt(x)) rot(y);
        else rot(x);
    }
    if(to==0) rt=x;
}
il int find(int x,int k)
{
    pushdown(x);
    int l=ls(x),r=rs(x);
    //cout<<l<<' '<<sz(l)+1<<' '<<k<<endl;
    if(sz(l)+1==k) return x;
    if(sz(l)>=k) return find(l,k);
    else return find(r,k-sz(l)-1);
}
il void rec(int x)
{
	//dg;
	if(ls(x)) rec(ls(x));
	if(rs(x)) rec(rs(x));
	q.push(x);
	fa(x)=ls(x)=rs(x)=e[x].tg=e[x].rev=0;
}
il int spt(int x,int tot)
{
    int l=find(rt,x),r=find(rt,x+tot+1);
    splay(l,0),splay(r,l);
    return ls(rs(rt));
}
il void qry(int x,int tot)
{
    x=spt(x,tot);
    printf("%d\n",S(x));
}
il void modify(int x,int tot,int k)
{
    x=spt(x,tot);
    int y=fa(x);
    e[x].v=k;
    e[x].tg=1;
    S(x)=sz(x)*k;
    if(k>=0)
    {
        lx(x)=rx(x)=mx(x)=S(x);
    }
    else lx(x)=rx(x)=0,mx(x)=k;
    pushup(y);
    pushup(fa(y));
}
il void rever(int x,int tot)
{
    x=spt(x,tot);
    //cout<<"qwq "<<x<<endl;
    int y=fa(x);
    //pushdown(y);
    //pushdown(x);
    if(!e[x].tg)
    {
        e[x].rev^=1;
        swap(ls(x),rs(x));
        swap(lx(x),rx(x));
        //cout<<ls(x)<<' '<<rs(x)<<' '<<lx(x)<<' '<<rx(x)<<endl;
        pushup(y),pushup(fa(y));
        //cout<<mx(rt)<<endl;
        //cout<<y<<' '<<fa(y)<<endl;
    }
}
il void era(int x,int tot)
{
	x=spt(x,tot);
	int y=fa(x);
	rec(x);
	ls(y)=0;
	pushup(y),pushup(fa(y));
}
il void build(int l,int r,int f)
{
	int mid=(l+r)>>1,nw=id[mid],lst=id[f];
	if(l==r)
	{
		mx(nw)=S(nw)=a[l];
		e[nw].tg=e[nw].rev=0;
		lx(nw)=rx(nw)=max(a[l],0);
		sz(nw)=1;
	}
	if(l<mid) build(l,mid-1,mid);
	if(r>mid) build(mid+1,r,mid);
	e[nw].v=a[mid];fa(nw)=lst;
	pushup(nw);
	e[lst].s[mid>=f]=nw;
	//pushup(lst);
}
il void ins(int k,int tot)
{
	for(int i=1;i<=tot;i++) a[i]=read();
	for(int i=1;i<=tot;i++)
	{
		if(!q.empty()) id[i]=q.front(),q.pop();
		else id[i]=++cnt;
	}
	build(1,tot,0);
	int z=id[(1+tot)>>1];
	int x=find(rt,k+1),y=find(rt,k+2);
	splay(x,0);splay(y,x);
	y=rs(rt);
	fa(z)=y;
	ls(y)=z;
	pushup(y);
	pushup(rt);
}
int main()
{
	n=read(),m=read();
	mx(0)=a[1]=a[n+2]=-inf;
	for(int i=1;i<=n;i++) a[i+1]=read();
	for(int i=1;i<=n+2;i++) id[i]=i;
	build(1,n+2,0);
	rt=(n+3)>>1;cnt=n+2;
	int k,tot,v;
	char opt[10];
	for(int i=1;i<=m;i++)
	{
		scanf("%s",opt);
		if(opt[0]!='M'||opt[2]!='X') k=read(),tot=read();
		if(opt[0]=='I') ins(k,tot);
		if(opt[0]=='D') era(k,tot);
		if(opt[0]=='M')
		{
			if(opt[2]=='X') printf("%d\n",mx(rt));
			else v=read(),modify(k,tot,v);
		}
		if(opt[0]=='R') rever(k,tot);
		if(opt[0]=='G') qry(k,tot);
	}
}
