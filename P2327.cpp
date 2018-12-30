#include <bits/stdc++.h>
#define il inline
#define Max 10005
using namespace std;
int a[Max],b[Max],ans,n,w[Max];
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
il void check()
{
	for(int i=2;i<=n;i++)
	{
		if(w[i-1]<0||w[i-1]>1)
		{
			ans--;
			return;
		}
		else if(w[i-1]==0)
		{
			b[i]=0;
		}
		else if(w[i-1]==1)
		{
			b[i]=1;
			w[i-1]--;
			w[i]--;
			w[i+1]--;
		}
	}
	if(w[n]) ans--;
}
int main()
{
	ans=2;
	n=read();
	w[0]=0;
	for(int i=1;i<=n;i++) a[i]=read(),w[i]=a[i];
	b[1]=1;
	w[1]--;
	w[2]--;
	check();
	for(int i=1;i<=n;i++) w[i]=a[i];
	memset(b,0,sizeof(b));
	b[1]=0;
	check();
	cout<<ans;
}
