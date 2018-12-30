#include <bits/stdc++.h>
#define il inline
using namespace std;
long long a,b,n;
long long a1[1000005],b1[1000005];
il long long gcd(long long a,long long b)
{
	if(a%b==0) return b;
	else return gcd(b,a%b);
}
int main()
{
	//freopen("U38343.txt","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		//printf("day%d:",i);
		//a=0,b=0;
		for(int j=1;j<=i;j++)
		{
			long long a1=i%j,b1=j;
			if(a==0&&b==0)
			{
				a=a1,b=b1;
			}
			else 
			{
			a=(a1*b+a*b1)%998244353;
			b=b*b1%998244353;
			}
			int k=gcd(a,b);
			a/=k,b/=k;
			printf("%d/%d ",i%j,j);
		}
		printf("%d %d\n",a,b);
		a1[i]=a,b1[i]=b;
		
		//printf("%lld,",a1[i]);
	}
	//cout<<a;
}
