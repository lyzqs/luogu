#include <bits/stdc++.h>
#define il inline
#define Max 500005
#define ll long long
#define int ll
//#define getchar() (tt==ss&&(tt=(ss=In)+fread(In,1,Max,stdin),tt==ss)?EOF:*ss++)
using namespace std;
char In[Max],*tt=In,*ss=In;
il ll read()
{
	char c=getchar();
	ll x=0,f=1;
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
ll f[Max];
ll n,m,s[Max];
ll c[Max],a[Max],b[Max],q[Max];
il int Y(int i)
{
	return f[i]+b[i]*b[i];
}
il double slope(int i,int j)
{
	return (double)((double)(Y(i)-Y(j))/(double)(b[i]-b[j]));
}
signed main()
{
	n=read(),m=read();
	for(int i=1;i<=n;i++)
	{
		c[i]=read();
		s[i]=s[i-1]+c[i];
	}
	for(int i=0;i<=n;i++)
		a[i]=s[i]+i,b[i]=s[i]+i+m+1;
	int l=1,r=1;
	for(int i=1;i<=n;i++)
	{
		while(l<r&&slope(q[l],q[l+1])<2.0*a[i]) l++;
		f[i]=f[q[l]]+(a[i]-b[q[l]])*(a[i]-b[q[l]]);
		//cout<<a[i]<<' '<<b[i]<<' '<<q[l]<<' '<<a[i]-b[q[l]]<<endl;
		while(l<r&&slope(i,q[r-1])<slope(q[r-1],q[r])) r--;
		q[++r]=i;
	}
	printf("%lld\n",f[n]);
}
