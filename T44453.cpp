#include <cstdio>
#include <iostream>
#define il inline
#define Max 1000010
#define inf 1e9
using namespace std;
int a[Max], maxv[Max<<2], addv[Max<<2],n,q,cnt=0;
#define lson (o << 1)
#define rson (o << 1 | 1)
il void pushup(int o) {
    maxv[o] = max(maxv[lson], maxv[rson]);
}
il void pushdown(int o) {
    if(!addv[o])return;
    addv[lson] += addv[o];
    addv[rson] += addv[o];
    maxv[lson] += addv[o];
    maxv[rson] += addv[o];
    addv[o] = 0;
}
il void build(int o, int l, int r) {
    if(l == r) {
        maxv[o] = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(lson, l, mid);
    build(rson, mid + 1, r);
    pushup(o);
}
il int querymax(int o, int l, int r, int ql, int qr) {
	cnt++;
    if(ql <= l && r <= qr) return maxv[o];
    int mid = (l + r) >> 1,ans=-inf;
    pushdown(o);
    if(ql <= mid) 
    {
		int last=cnt,qwq=querymax(lson, l, mid, ql, qr);
	if (ans < qwq) {
        ans = qwq,cnt+=(cnt-last);
    } 
	}
    if(qr > mid)
	{
		int last=cnt,qwq=querymax(rson, mid + 1, r, ql, qr);
	  if (ans < qwq) {
        ans = qwq,cnt+=(cnt-last);
    }
	}
    return ans;
}
il void add(int o,int l,int r,int ql,int qr,int k)
{
	if(ql<=l&&r<=qr)
	{
		maxv[o]+=k,addv[o]+=k;
		return;
	}
	int mid=(l+r)>>1;
	pushdown(o);
	if(ql<=mid) add(lson,l,mid,ql,qr,k);
	if(qr>mid) add(rson,mid+1,r,ql,qr,k);
	pushup(o);
}
il int read()
{
	char c=getchar();
	int x=0;
	while(c>'9'||c<'0') c=getchar();
	while(c>='0'&&c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return x;
}
int main()
{
	n=read();q=read();
	for(int i=1;i<=n;i++)
		a[i]=read();
	build(1,1,n);
	int opt,x,y,qwq;
	while(q--)
	{
		opt=read(),x=read(),y=read();
		if(opt==1)
		{
			qwq=read();
			add(1,1,n,x,y,qwq);
			continue;
		}
		else if(opt==2)
		{
			cnt=0;
			querymax(1,1,n,x,y);
			printf("%d\n",cnt);
		}
	}
}
