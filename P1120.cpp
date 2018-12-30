#include <bits/stdc++.h>
#define il inline
using namespace std;
int a[55],n,maxa,mina;
long long s=0;
il bool check(int ans,int sum,int goal,int now)
{
	for(int i=1;i<=50;i++) 
	{
		if(a[i]) dfs(i,w);
		for(int i=50;i>=1&&a[k];i--)
		{
				
		}
	}
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[0];
		if(a[0]>50) continue;
		a[a[0]]++;
		s+=a[0];
		maxa=max(maxa,a[a[0]]);
		mina=min(mina,a[a[0]]);
	}
	for(int i=maxa;i<=s>>1;i++)
	{
		if(s%i==0)
		{
			dfs(s/i,0,i,maxa);
		}
	}
}
