#include <bits/stdc++.h>
#define il inline
#define Max 6000005
using namespace std;
int t[Max<<1],ls[Max<<1],rs[Max<<1],rt[Max];
int n,q,cnt,a[Max],b[Max],m;
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
il void build(int &x,int l,int r)
{
	x=++cnt;
	if(l==r) return;
	int mid=(l+r)>>1;
	build(ls[x],l,mid);
	build(rs[x],mid+1,r);
}
il int modify(int o,int l,int r,int p)
{
	int x=++cnt;
	t[x]=t[o]+1,ls[x]=ls[o],rs[x]=rs[o];
	if(l==r) return x;
	int mid=(l+r)>>1;
	if(p<=mid) ls[x]=modify(ls[x],l,mid,p);
	else rs[x]=modify(rs[x],mid+1,r,p);
	return x;
}
il int query(int o,int x,int l,int r,int k)
{
	if(l==r) return l;
	int lc=t[ls[x]]-t[ls[o]],rc=t[rs[x]]-t[rs[o]];
	int mid=(l+r)>>1;
	if(lc*2>k) return query(ls[o],ls[x],l,mid,k);
	if(rc*2>k) return query(rs[o],rs[x],mid+1,r,k);
	return 0;
}
int main()
{
	n=read(),q=read();
	for(int i=1;i<=n;i++) b[i]=a[i]=read();
	sort(b+1,b+1+n);
	m=unique(b+1,b+1+n)-b-1;
	build(rt[0],1,m);
	for(int i=1;i<=n;i++)
	{
		int p=lower_bound(b+1,b+1+m,a[i])-b;
		rt[i]=modify(rt[i-1],1,m,p);
	}
	while(q--)
	{
		int l=read(),r=read(),len=r-l+1;
		printf("%d\n",query(rt[l-1],rt[r],1,m,len));
	}
}
