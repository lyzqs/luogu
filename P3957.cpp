#include <bits/stdc++.h>
#define il inline
#define ll long long
#define Max 500005
using namespace std;
ll n,k,dis;
ll f[Max],q[Max],Sum=0,d[Max],w[Max];
il ll read()
{
	char c=getchar();
	ll x=0,f=1;
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
ll p,h,t;
il void push(int x)
{
	while(f[q[t]]<=f[x]&&t>=h) t--;
	q[++t]=x;
}
il bool check(ll c)
{
	p=0,h=1,t=0,q[h]=0;
	for(int i=1;i<=n;i++) f[i]=-0x7f7f7f7f;
	for(int i=1;i<=n;i++)
	{
		while(d[i]-d[p]>=max(dis-c,1ll)&&p<i) push(p++);
		while(d[i]-d[q[h]]>dis+c&&h<=t) h++;
		if(h>t||f[q[h]]==-0x7f7f7f7f) continue;
		else f[i]=f[q[h]]+w[i];
		//printf("%d %d %d\n",c,i,f[i]);
		if(f[i]>=k) return 1;
	}
	return 0;
}
int main()
{
	n=read(),dis=read(),k=read();
	for(int i=1;i<=n;i++)
	{
		d[i]=read();
		w[i]=read();
		Sum+=w[i];
	}
	if(!check(2147483647))
	{
		printf("-1");
		return 0;
	}
	ll l=1,r=(ll)1e9,mid,ans=-1;
	while(l<=r)
	{
		mid=(l+r)>>1;
		if(check(mid)) ans=mid,r=mid-1;
		else l=mid+1;
	}
	printf("%lld",ans);
}
