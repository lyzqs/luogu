#include <bits/stdc++.h>
#define il inline
#define Max 1005
using namespace std;
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
int n,a[Max],vst[Max],ans[Max],tot=n;
int main()
{
	n=read();
	for(int i=1;i<=n;i++) a[i]=read();
	int pos=1;
	while(tot<n-1)
	for(int i=1;i<=(int)(n-tot)/2;i++)
	{
		ans[pos]=a[++tot];
		vst[pos]=1;
		//printf("%d %d %d\n",pos,tot,ans[pos]);
		while(vst[pos]) pos=pos%n+1;
		pos=pos%n+1;
		while(vst[pos]) pos=pos%n+1;
	}
	for(int i=1;i<=n;i++) if(!vst[i]) ans[i]=a[tot+1];
	for(int i=1;i<=n;i++)
	{
		printf("%d ",ans[i]);
	}
}
