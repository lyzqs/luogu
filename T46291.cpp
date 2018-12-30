#include <bits/stdc++.h>
#define Max 50005
#define Mod 1000000007
#define il inline
using namespace std;
int a[Max],b[Max],c[Max],n,q,ans=1;
inline int read()
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
il int qpw(int a,int b)
{
	int ans=1,s=a;
	while(b)
	{
		if(b&1) ans=(1ll*ans*s)%Mod;
		s=(1ll*s*s)%Mod;
		b>>=1;
	}
	return ans;
}
int main()
{
	//printf("%d\n",qpw(2,10));
	n=read(),q=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
	}
	for(int i=1;i<=n;i++) b[i]=read();
	c[0]=0;
	for(int i=1;i<=n;i++) c[i]=max(c[i-1],a[i]),ans=(ans*min(c[i],b[i]))%Mod;
	for(int i=1;i<=q;i++)
	{
		int opt=read(),x=read(),y=read();
		if(opt==1)
		{
			int qwq=min(c[x],b[x]);
			b[x]=y;
			qwq=qpw(qwq,Mod-2);
			ans=(1ll*ans*min(c[x],b[x]))%Mod;
			if(ans%qwq==0) ans/=qwq;
			else
			ans=(ans*qwq)%Mod;
			printf("%d\n",ans);
		}
		if(opt==0)
		{
			a[x]=y;
			for(int j=x;j<=n;j++)
			{
				//ans=(ans*qpw(min(c[j],b[j]),Mod-2))%Mod;
				int qwq=min(c[x],b[x]);
				c[x]=max(c[x-1],a[x]);
				
				ans=(1ll*ans*min(c[x],b[x]))%Mod;
				if(ans%qwq==0) ans/=qwq;
				else
				{
				qwq=qpw(qwq,Mod-2);
				ans=(ans*qwq)%Mod;
				}
			}
			printf("%d\n",ans);
		}
	}
	for(int i=1;i<=n;i++)
		printf("i:%d c:%d b:%d\n",i,c[i],b[i]);
}
