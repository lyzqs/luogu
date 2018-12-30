#include <bits/stdc++.h>
#define il inline
#define Max 100005
using namespace std;
int a[Max],b[Max],n,ans,f[Max],c[Max];
il int read()
{
	char c=getchar();
	int x=0;
	while(c>'9'||c<'0') c=getchar();
	while(c>='0'&&c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return x;
}
int main()
{
	n=read();
	for(int i=1;i<=n;i++) a[read()]=i;
	for(int i=1;i<=n;i++) b[i]=a[read()];
	for(int i=1;i<=n;i++)
	{
		if(f[ans]<b[i]) f[++ans]=b[i];
		else f[lower_bound(f+1,f+1+ans,b[i])-f]=b[i];
	}
	cout<<ans;
}
