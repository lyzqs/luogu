#include <bits/stdc++.h>
#define il inline
#define Max 300005
#define fa(x) e[x].f
#define ls(x) e[x].s[0]
#define rs(x) e[x].s[1]
#define len(x) e[x].r-e[x].l
#define int long long
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
int n,m,cnt,q;
struct node
{
	int sz,f,s[2],l,r;
}e[5000005];
struct Splay
{
	int rt;
	il int add(int ql,int qr)
	{
		int x=++cnt;
		e[x].l=ql;
		e[x].r=qr;
		e[x].sz=1;
		fa(x)=ls(x)=rs(x)=0;
		return cnt;
	}
	il void pushup(int x)
	{
		e[x].sz=e[ls(x)].sz+e[rs(x)].sz+len(x);
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
		ct(k,y,ys),ct(y,x,ys^1),ct(x,z,zs);
		pushup(y),pushup(x);
	}
	il void splay(int x,int to)
	{
		for(int y;(y=fa(x))!=to;rot(x))
		{
			//puts("qwq");
			if(fa(y)==to) continue;
			if(rlt(y)==rlt(x)) rot(y);
			else rot(x);
			//cout<<x<<' '<<y<<endl;
		}
		if(to==0) rt=x;
	}
	il int spt(int x,int k)
	{
		k+=e[x].l;
		int y=add(k,e[x].r);
		e[x].r=k;
		if(!rs(x))
		{
			rs(x)=y;
			fa(y)=x;
		}
		else
		{
			int nw=rs(x);
			while(ls(nw)) nw=ls(nw);
			ls(nw)=y;
			fa(y)=nw;
			while(nw!=x) pushup(nw),nw=fa(nw);
		}
		splay(y,0);
		return y;
	}
	il int pop(int k)
	{
		int x=rt;
		while(1)
		{
			//puts("qwq");
			if(e[ls(x)].sz>=k) x=ls(x);
			else
			{
				k-=e[ls(x)].sz;
				if(k<=len(x))
				{
					if(k!=len(x)) spt(x,k);
					if(k!=1) x=spt(x,k-1);
					break;
				}
				else k-=len(x),x=rs(x);
			}
		}
		splay(x,0);
		fa(rs(x))=fa(ls(x))=0;
		if(!ls(x)) rt=rs(x);
		else
		{
			int t=ls(x);
			//cout<<t<<endl;
			while(rs(t)) t=rs(t);//cout<<t<<endl;
			splay(t,0);
			pushup(rt=fa(rs(t)=rs(x))=t);
		}
		return e[x].l;
	}
	il void push(int k)
	{
		int x=add(k,k+1);
		if(!rt)
		{
			rt=x;
		}
		else
		{
			int o=rt;
			while(rs(o)) o=rs(o);
			splay(o,0);
			pushup(fa(rs(o)=x)=o);
		}
	}
	il void init(int l,int r)
	{
		rt=add(l,r);
	}
}s[Max];
signed main()
{
	n=read(),m=read();q=read();
	for(int i=1;i<=n;i++)
	{
		s[i].init((i-1)*m+1,i*m);
	}
	s[0].init(m,m+1);
	for(int i=2;i<=n;i++) s[0].push(i*m);
	int x,y,p;
	while(q--)
	{
		x=read(),y=read();
		s[x].push(s[0].pop(x));
		//puts("qwq");
		printf("%lld\n",p=s[x].pop(y));
		s[0].push(p);
	}
}
