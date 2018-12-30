#include <bits/stdc++.h>
#define il inline
using namespace std;
int n,m;
double a[1005],x;
double l,r;
il double calc(double x)
{
	double res=0;
	for(int i=1;i<=n+1;i++)
		res=res*x+a[i];
	return res;
}
int main()
{
	scanf("%d%lf%lf",&n,&l,&r);
	for(int i=1;i<=n+1;i++)
	{
		scanf("%lf",&a[i]);
	}
	for(int i=1;i<=1000;i++)
	{
		double k=(r-l)/3.0;
		double mid1=l+k,mid2=r-k;
		if(calc(mid1)>calc(mid2)) r=mid2;
		else l=mid1;
	}
	printf("%.5f",l);
}
