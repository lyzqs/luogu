#include <bits/stdc++.h>
#define il inline
#define Max 10005
using namespace std;
double a[Max],b[Max];
int n,T;
il double calc(double x,double y)
{
	double res=0;
	for(int i=1;i<=n;i++)
		res+=sqrt((x-a[i])*(x-a[i])+(y-b[i])*(y-b[i]));
	return res;
}
il double soly(int x)
{
	double l=0,r=10000;
	for(int i=1;i<=300;i++)
	{
		double k=(r-l+1)/3;
		double mid1=k+l,mid2=r-k;
		if(calc(x,mid1)<calc(x,mid2)) r=mid2;
		else l=mid1;
	}
	return calc(x,l);
}
il double solx()
{
	double l=0,r=10000;
	for(int i=1;i<=300;i++)
	{
		double k=(r-l+1)/3;
		double mid1=k+l,mid2=r-k;
		if(soly(mid1)<soly(mid2)) r=mid2;
		else l=mid1;
	}
	return soly(l);
}
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%lf%lf",&a[i],&b[i]);
		}
		printf("%.0f\n",solx());if(T) puts("");
	}
}
