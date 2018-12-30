#include <bits/stdc++.h>
#define il inline
//#define getchar() (tt==ss&&(tt=(ss=In)+fread(In,1,Max,stdin),tt==ss)?EOF:*ss++)
#define Max 10000005
using namespace std;
char In[Max],*tt=In,*ss=In;
il int read()
{
	char c=getchar();
	int x=0,f=1;
	while(c>'9'||c<'0')
	{
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
int f[Max],n,m,t,qwq,cnt[Max],s[Max],q[Max],l=1,r=0,ans=0x3f3f3f3f;
il double slope(int i,int j)
{
	return (double)(f[j]+s[j]-f[i]-s[i])/(double)(cnt[i]==cnt[j]?1e-9:cnt[j]-cnt[i]);
}
int main()
{
	n=read(),m=read();
	for(int i=1;i<=n;i++)
	{
		qwq=read(),t=max(qwq,t);
		cnt[qwq]++,s[qwq]+=qwq;
	}
	for(int i=1;i<t+m;i++) cnt[i]+=cnt[i-1],s[i]+=s[i-1];
	for(int i=0;i<t+m;i++)
	{
		if(i-m>=0)
		{
			while(l<r&&slope(q[r-1],q[r])>=slope(q[r],i-m)) r--;
			q[++r]=i-m;
		}
		while(l<r&&slope(q[l],q[l+1])<=i) l++;
		f[i]=cnt[i]*i-s[i];
		if(l<=r) f[i]=min(f[i],f[q[l]]+(cnt[i]-cnt[q[l]])*i-s[i]+s[q[l]]);
	}
	for(int i=t;i<t+m;i++) ans=min(ans,f[i]);
	cout<<ans;
}
