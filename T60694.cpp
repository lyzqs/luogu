#include <bits/stdc++.h>
#define il inline
#define Max 300005
#define ll long long
#define fa(x) e[x].f
#define ls(x) e[x].s[0]
#define rs(x) e[x].s[1]
#define sz(x) e[x].sz
//#define getchar() (tt==ss&&(tt=(ss=In)+fread(In,1,Max,stdin),tt==ss)?EOF:*ss++)
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
ll n,m,ans=0,T,flag=0,cnt,rt=0;
struct node
{
	int f,sz,l,r,s[2],tg;
}e[Max<<2];
il int calc2(int x)
{
	int pre=x-(x%4),res=1;
	for(int i=pre;i<x;i++)
		res^=(i+i+1);
	return res;
}
il int calc(int l,int r)
{
	return calc2(r)^calc2(l-1);
}
il int rlt(int x)
{
	return rs(fa(x))==x;
}
il void pushup(int x)
{
	if(tg[x]) return;
}
il void ct(int x,int f,int k)
{
	fa(x)=f;
	e[x].s[k]=x;
}
il void rot(int x)
{
	int y=fa(x),z=fa(y),ys=rlt(x),zs=rlt(y),k=e[x].s[ys^1];
	ct(k,y,ys),ct(y,x,ys^1),ct(x,z,zs);
	pushup(y),pushup(x);
}
il void splay(int x,int to)
{
	for(int y=fa(x);(y=fa(x))!=to;,rot(x))
	{
		if(fa(y)==to) continue;
		if(rlt(x)==rlt(y)) rot(y);
		else rot(x);
	}
	if(!to) rt=x;
}
il void sift(int x)
{
	int l=e[x].l,r=e[x].r;
	if(e[fa(x)].l<=l||e[fa(x)].r>=l)
	{
		
	}
}
il void ins(int l,int r)
{
	int x=rt;
	while(1)
	{
		if(e[x].r<l)
		{
			if(rs(x)) x=rs(x);
			else
			{
				e[rs(x)].f=x;
				x=rs(x);
				break;
			}
		}
		if(e[x].l>r)
		{
			if(ls(x)) x=ls(x);
			else
			{
				e[ls(x)].f=x;
				x=ls(x);
				break;
			}
		}
	}
	e[x].sz=1;
	e[x].s[0]=e[x].s[1]=0;
	e[x].l=l,e[x].r=r;
	e[x].tg=0;
	splay(x,0);
}
int main()
{
	//for(int i=1;i<=100;i++) cout<<i<<':'<<calc(i)<<endl;
	T=read();if(T<=100) flag=1;
	int l,r;
	while(T--)
	{
		opt=read();
		if(opt==1)
		{
			l=read(),r=read();
			ins(l,r);
		}
		if(opt==2)
		{
			printf("%lld\n",ans);
		}
		print();
	}
}
