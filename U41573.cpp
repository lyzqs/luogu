#include <bits/stdc++.h>
#define il inline
#define ll long long
#define Max 55
using namespace std;
ll vst[Max],w[Max],n,m,k,e[Max][Max],ans,s[Max],top,f[25][500005],cnt[500005],MAX=0;
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
il ll check(ll k)
{
	ll res=0;
	while(k)
	{
		if(k&1) res++;
		k>>=1; 
	}
	return res;
}
int main()
{
	//freopen("War3.in","r",stdin);
	n=read();
	for(int i=1;i<=(1<<(n+1));i++)
	{
		 cnt[i]=check(i);
		 //printf("%d:%d\n",i,cnt[i]);
	}
	m=read(),k=read();
	for(int i=0;i<n;i++)
		w[i]=read(),MAX=max(MAX,w[i]);
	if(m==1) 
	{
		printf("%d\n",MAX);
		return 0;
	}
	for(int i=0;i<k;i++)
	{
		int u=read()-1,v=read()-1,c=read();
		e[u][v]+=c;
	} 
	for(int i=0;i<n;i++) f[i][1<<i]=w[i];
	for(int S=1;S<(1<<(n));S++)
	{
		if(cnt[S]<=m&&cnt[S]>1)
		{
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<n;j++)
				{
					if(S&(1<<i)&&S&(1<<j)&&i!=j)
					{
						f[i][S]=max(f[i][S],f[j][S^(1<<i)]+e[j][i]+w[i]);
					}
				}
				if(cnt[S]==m) ans=max(ans,f[i][S]);
			}
		}
	}
	printf("%lld",ans);
}
