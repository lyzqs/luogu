#include <bits/stdc++.h>
#define il inline
#define rg register
using namespace std;
il int qpw(rg int a,rg int b)
{
	int res=1;
	while(b)
	{
		if(b&1) res=res*a;
		a=a*a;
		b>>=1;
	}
	return res;
}
il int mogic(rg int x)
{
	rg int res=0,cnt=0,s[23];
	while(x) s[++cnt]=x%10,x/=10;
	for(rg int i=1;i<=cnt-1;i++)
	{
		res+=abs(s[i]-s[i+1])*qpw(10,i-1);
	}
	if(res<10) return res;
	else return mogic(res);
}
il void print(rg int x)
{
	if(x%10) putchar(x%10+'0');
	if(x>=10) print(x/10);
}
int main()
{
	freopen("P1822tb.txt","w",stdout);
	int len=33344,l,r,res=1;
	for(rg int i=1;i<=30005;i++)
	{
		//if(i<=20333&&i>=5333) continue;
		l=(i-1)*len+1;
		r=min(1000000000,i*len);
		for(rg int j=l;j<=r;j++)
			if(mogic(j)==7) res++;
		if(!res) putchar('0');
		print(res),putchar(',');
		res=0;
	}
}
