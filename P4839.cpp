#include <bits/stdc++.h>
#define il inline
#define getchar() (tt==ss&&(tt=(ss=In)+fread(In,1,Max,stdin),tt==ss)?EOF:*ss++)
#define Max 100005
#define ls(x) x<<1
#define rs(x) x<<1|1
using namespace std;
char In[Max],*ss=In,*tt=In;
struct node
{
	int b[65];
	il void add(int x)
	{
		bool res=1;
		for(int i=31;i>=0;i--)
		{
			res=res&&b[i];
			if(!(x>>i)) continue;
			if(!b[i])
			{
				b[i]=x;
				return;
			}
			x^=b[i];
		}
		return;
	}
	il void add(node x)
	{
		for(int i=31;i>=0;i--)
		{
			if(x.b[i])
				add(x.b[i]);
		}
	}
}t[Max<<2],ans;
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
int n,m;
il void ins(int x,int l,int r,int k,int p)
{
	t[x].add(p);
	if(l==r) return;
	int mid=(l+r)>>1;
	if(k<=mid) ins(ls(x),l,mid,k,p);
	else ins(rs(x),mid+1,r,k,p);
}
il void qry(int x,int l,int r,int ql,int qr)
{
	if(ql<=l&&r<=qr)
	{
		ans.add(t[x]);
		return;
	}
	int mid=(l+r)>>1;
	if(ql<=mid) qry(ls(x),l,mid,ql,qr);
	if(qr>mid) qry(rs(x),mid+1,r,ql,qr);
}
il void clear()
{
	memset(ans.b,0,sizeof(ans.b));
}
il int getans()
{
	int res=0;
	for(int i=31;i>=0;i--)
	{
		if((res^ans.b[i])>res) res^=ans.b[i];
	}
	return res;
}
int main()
{
	n=read(),m=read();
	while(n--)
	{
		int opt=read(),x=read(),y=read();
		if(opt==1)
		{
			ins(1,1,m,x,y);
		}
		if(opt==2)
		{
			clear();
			qry(1,1,m,x,y);
			printf("%d\n",getans());
		}
	}
}
