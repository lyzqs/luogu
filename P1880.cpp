#include <bits/stdc++.h>
#define Max 205
#define inf 0x3f3f3f3f
using namespace std;
int n,a[Max],f[Max][Max],f2[Max][Max],s[Max],ans1=inf,ans2=-inf;
int main()
{
	cin>>n;
	memset(f,-inf,sizeof(f));
	memset(f2,inf,sizeof(f2));
	for(int i=1;i<=n;i++) cin>>a[i],f2[i][i]=f[i][i]=0,s[i]=s[i-1]+a[i];
	for(int i=n+1;i<=n*2;i++) a[i]=a[i-n],f2[i][i]=f[i][i]=0,s[i]=s[i-1]+a[i];
	//for(int i=1;i<n;i++) f2[i][i+1]=f[i][i+1]=a[i]+a[i+1];
	for(int len=1;len<n;len++)
	{
		for(int l=1;l<=n*2-len;l++)
		{
			int r=l+len;
			for(int k=l;k<r;k++)
			{
				f[l][r]=max(f[l][r],f[l][k]+f[k+1][r]);
				f2[l][r]=min(f2[l][r],f2[l][k]+f2[k+1][r]);
			}
			f[l][r]+=s[r]-s[l-1];
			f2[l][r]+=s[r]-s[l-1];
		}
	}
	for(int i=1;i<=n;i++) ans1=min(ans1,f2[i][i+n-1]),ans2=max(ans2,f[i][i+n-1]);
	cout<<ans1<<endl<<ans2;
}
