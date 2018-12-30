#include <bits/stdc++.h>
#define il inline
#define ll long long
#define Max 1005
using namespace std;
il ll read()
{
	char c=getchar();
	ll x=0;
	while(c>'9'||c<'0')c=getchar();
	while(c>='0'&&c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return x;
}
ll n,m,a[Max],T,vst[Max],q[Max],cnt,tot,h[200005];
il int work()
{
	memset(h,0,sizeof(h));
	q[1]=1;
	for(int k=1;k<=n;k++)
	{
		h[a[q[k]]]=1;
		for(int i=0;i<=m;i++)
			if(h[i])
			{
				h[i+a[q[k]]]=1;
			}
		for(int i=1;i<=n;i++)
		{
			if(!h[a[i]]&&!vst[i]) vst[i]=1,q[k+1]=i;
			if(q[k+1]) break;
			if(i==n) //goto ed;//
				return k;
		}
	}
	return n;
	//ed:
	//for(int i=1;i<=n;i++) cout<<q[i]<<' ';cout<<endl;
}
int main()
{
	T=read();
	while(T--)
	{
		memset(vst,0,sizeof(vst));
		memset(q,0,sizeof(q));
		m=0;cnt=0;tot=0;
		n=read();
		for(int i=1;i<=n;i++) a[i]=read(),m=max(m,a[i]);
		sort(a+1,a+1+n);
		printf("%d\n",work());
	}
}
