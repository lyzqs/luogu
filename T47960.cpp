#include <bits/stdc++.h>
#define il inline
#define ll long long
using namespace std;
int ans[20000005],n,tot=0,cnt=0;
il void dfs(int last,int nw,int s)
{
	ans[++cnt]=s+nw-1;
	for(int i=last;i*i<=nw;i++)
	{
		//printf("%d %d?\n",i,nw);
		if(nw%i==0)
			dfs(i,nw/i,s+i-1);
	}
}
int main()
{
	cin>>n;
	dfs(2,n,0);
	sort(ans+1,ans+1+cnt);
	int q=cnt;
	for(int i=1;i<=q-1;i++)
	{
		if(ans[i]==ans[i+1]) cnt--;
	}
	printf("%d\n",cnt);
	if(cnt) printf("%d ",ans[1]);
	for(int i=2;i<=q;i++)
	{
		if(ans[i]!=ans[i-1]) printf("%d ",ans[i]);
	}
}
