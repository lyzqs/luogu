#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define Max 1000005
#define il inline
using namespace std;
int n,a[Max],f[Max],ans=0;
il int find(int x,int opt)
{
	int l=1,r=ans,mid;
	if(opt==1)
	while(l<r)
	{
		mid=(l+r)>>1;
		if(f[mid]>=x) l=mid+1;
		else r=mid;
	}
	if(opt==2)
	while(l<r)
	{
		mid=(l+r)>>1;
		if(f[mid]>=x) r=mid;
		else l=mid+1;
	}
	return l;
}
int main()
{
	while(~scanf("%d",&a[++n]));
	n--;
	//for(int i=1;i<=n;i++) cout<<a[i]<<' ';cout<<endl;
	f[0]=inf;
	for(int i=1;i<=n;i++)
	{
		if(f[ans]>=a[i]) f[++ans]=a[i];
		else 
		{
			f[find(a[i],1)]=a[i];
		}
	}
	cout<<ans<<endl;
	f[0]=-inf;
	ans=0;
	for(int i=1;i<=n;i++)
	{
		if(f[ans]<a[i]) ans++,f[ans]=a[i];
		else 
		{
			f[find(a[i],2)]=a[i];
		}
	}
	cout<<ans;
	//printf()
}
