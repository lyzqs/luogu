#include <bits/stdc++.h>
#define il inline
#define Max 100005
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
int f[Max];
int n,m,cnt;
struct node 
{
	int l,r,v;
}a[Max],e[Max],b[Max];
il bool cmp(node a,node b)
{
	if(a.l!=b.l) return a.l<b.l;
	else return a.r<b.r;
}
il bool cmp2(node a,node b)
{
	if(a.r!=b.r) return a.r<b.r;
	else return a.l<b.l;
}
il int find(int l,int r,int w)
{
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(b[mid].r<w) l=mid+1;
		else r=mid-1;
	}
	return r;
}
int main()
{
	n=read();m=n;
	int k=0;
	for(int i=1;i<=n;i++)
	{
		a[i].l=read()+1;
		a[i].r=n-read();
	}
	//for(int i=1;i<=n;i++) cout<<i<<' '<<e[i].l<<' '<<e[i].r<<endl;
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++) if(a[i].l<=a[i].r) e[++k]=a[i];
	n=k;
	for(int i=1;i<=n;i++)
	{
		if(i==1||e[i].l!=e[i-1].l||e[i].r!=e[i-1].r) b[++cnt]=e[i],b[cnt].v=1;
		else if(b[cnt].v<b[cnt].r-b[cnt].l+1) b[cnt].v++;
	}
	sort(b+1,b+1+cnt,cmp2);
	//for(int i=1;i<=cnt;i++) cout<<i<<' '<<b[i].l<<' '<<b[i].r<<' '<<b[i].v<<endl;
	//for(int i=1;i<=cnt;i++) cout<<i<<' '<<e[i].l<<' '<<e[i].r<<endl;
	f[1]=b[1].v;
	for(int i=2;i<=cnt;i++)
	{
		int pos=find(1,i-1,b[i].l);
		f[i]=max(f[i-1],f[pos]+b[i].v);
	}
	cout<<m-f[cnt];
}
