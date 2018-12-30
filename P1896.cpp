#include <bits/stdc++.h>
#define il inline
#define Max 1<<15
#define m 1<<n
#define ll long long
using namespace std;
ll f[15][Max][15*15],cnt[Max];
ll n,t;
il bool checkup(int a,int b)
{
	if((!((a<<1)&a))&&(!((a>>1)&a))&&!((a<<1)&b)&&!((a>>1)&b)&&!(a&b)) return true;
	return false;
}
il bool checklr(int a)
{
	return (!((a<<1)&a))&&(!((a>>1)&a));
}
il int get(int qwq)
{
	int res=0;
	while(qwq)
	{
		if(qwq&1) res++;
		qwq>>=1;
	}
	return res;
}
int main()
{
	cin>>n>>t;
	for(int i=0;i<m;i++) cnt[i]=get(i);
	for(int i=0;i<m;i++) f[1][i][cnt[i]]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(checklr(j))
				for(int k=0;k<m;k++)
				{
					if(checkup(j,k)&&checklr(k))
					{
						for(int l=0;l<=t;l++)f[i][j][cnt[j]+l]+=f[i-1][k][l];
					}
				}
		}
	}
	ll ans=0;
	for(int i=0;i<m;i++) ans+=f[n][i][t];
	cout<<ans;
}
