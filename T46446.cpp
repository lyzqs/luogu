#include <bits/stdc++.h>
#define il inline
#define ll long long
#define Max 1005
using namespace std;
ll w[Max],S,n,s,ans=-1,vst[Max];
il ll read()
{
	char c=getchar();
	ll x=0;
	while(c>'9'||c<'0') c=getchar();
	while(c>='0'&&c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return x;
}
il ll qpw(ll a,ll b)
{
	ll res=1;
	while(b)
	{
		if(b&1) res*=a;
		a*=a;
		b>>=1;
	}
	return res;
}
il void dfs1(ll nw)
{
	if(nw<S)
	{
		ans=max(ans,nw);
		return;
	}
	if(nw==S)
	{
		printf("%lld",S);
		exit(0);
	}
	for(int i=n;i>=1;i--)
	{
		if(vst[i]) continue;
		if(nw-w[i]<=ans) break;
		vst[i]=1;
		dfs1(nw-w[i]);
		vst[i]=0;
	}
}
il void dfs2(ll nw)
{
	if(nw==S)
	{
		printf("%lld",S);
		exit(0);
	}
	for(int i=n;i>=1;i--)
	{
		if(vst[i]) continue;
		if(nw+w[i]>S) continue;
		if(nw+w[i]<=ans) continue;
		vst[i]=1;
		dfs2(nw+w[i]);
		vst[i]=0;
	}
	//if(ans>nw) exit(0);
	ans=max(ans,nw);
}
int main()
{
	S=read();n=read();
	for(int i=1;i<=n;i++)
	{
		int a=read(),b=read();
		w[i]=qpw(a,b);
		//if(w[i]>S)
		//{
		//	n--,i--;
		//	continue;
		//}
		s+=w[i];
	}
	sort(w+1,w+1+n);
	if(S>s/2)dfs1(s);
	else dfs2(0);
	printf("%lld",ans);
}
