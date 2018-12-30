#include <bits/stdc++.h>
#define Max 105
using namespace std;
int n,m,a[105][105],ans=-1;
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			cin>>a[i][j];
			if(a[i][j]==1) a[i][j]=min(a[i-1][j-1],min(a[i-1][j],a[i][j-1]))+1;
			ans=max(ans,a[i][j]);
		}
	cout<<ans;
}
