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
	while(c<='9'&&c>='0')
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
int n,m,c[Max],a[Max],l,r,ans[Max],cnt,len,k;
long long res=0;
struct node
{
	int id,l,r,n;
}e[Max];
il void add(int p)
{
	res+=2*(++c[a[p]])-1;
}
il void del(int p)
{
	res-=2*(--c[a[p]])+1;
}
il bool cmp(node a,node b)
{
	if(a.id!=b.id) return a.id<b.id;
	else return a.r<b.r;
}
int main()
{
	n=read(),m=read(),k=read();
	len=sqrt(n);
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=m;i++)
	{
		e[i].l=read(),e[i].r=read();
		e[i].id=e[i].l/len;
		e[i].n=i;
	}
	sort(e+1,e+1+m,cmp);
	l=e[1].l,r=e[1].l-1;
	for(int i=1;i<=m;i++)
	{
		while(l<e[i].l) del(l++);
		while(l>e[i].l) add(--l);
		while(r<e[i].r) add(++r);
		while(r>e[i].r) del(r--);
		ans[e[i].n]=res;
	}
	for(int i=1;i<=m;i++) printf("%d\n",ans[i]);
}
