#include <bits/stdc++.h>
#define il inline
#define Max 100005
using namespace std;
double t[Max<<2],tg[Max<<2],a[Max],ans=1,k;
int n,m;
il int ls(int x)
{
	return x<<1;
}
il int rs(int x)
{
	return x<<1|1;
}
il void pushup(int x)
{
	t[x]=t[ls(x)]*t[rs(x)];
}
il void build(int x,int l,int r)
{
	if(l==r)
	{
		t[x]=a[l];
		return;
	}
	int mid=(l+r)>>1;
	build(ls(x),l,mid);
	build(rs(x),mid+1,r);
	pushup(x); 
}
il double qmul(int x,int l,int r,int ql,int qr)
{
	double res=1;
	if(ql<=l&&r<=qr) return t[x];
	int mid=(l+r)>>1;
	//pushdown(x,l,r);
	if(ql<=mid) res*=qmul(ls(x),l,mid,ql,qr);
	if(qr>mid) res*=qmul(rs(x),mid+1,r,ql,qr);
	return res;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lf",&a[i]);
	if(n<=1005&&m<=1005)
	{
		int opt,l,r;
		while(m--)
		{
			scanf("%d%d%d",&opt,&l,&r);
			if(opt==0)
			{
				ans=1;
				for(int i=l;i<=r;i++) ans*=(1.0-a[i]);
				printf("%.6f\n",ans);
			} 
			if(opt==1)
			{
				scanf("%lf",&k);
				for(int i=l;i<=r;i++)
					a[i]*=k;
			}
		}
	}
	else 
	{
		build(1,1,n);
		int opt,l,r;
		while(m--)
		{
			scanf("%d%d%d",&opt,&l,&r);
			if(opt==0)
			{
				printf("%.6f\n",qmul(1,1,n,l,r));
			} 
		}
	}
}
