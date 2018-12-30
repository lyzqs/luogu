#include <bits/stdc++.h>
#define Max 205
using namespace std;
int a[Max],f[Max][Max],n,ans=-1;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i],a[i+n]=a[i];
	for(int len=1;len<=n;len++)
	{
		for(int l=1;l<=n*2-len;l++)
		{
			int r=l+len;
			for(int k=l+1;k<r;k++)
			{
				f[l][r]=max(f[l][r],f[l][k]+f[k][r]+a[l]*a[k]*a[r]);
			}
		}
	}
	for(int i=1;i<=n;i++)	ans=max(ans,f[i][i+n]);
	cout<<ans;
}
