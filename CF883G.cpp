#include <bits/stdc++.h>
#define il inline
#define Max 1005
using namespace std;
int n,a,b,e[Max][Max];
il void sol1()
{
	if(n==2||n==3) printf("NO"),exit(0);
	for(int i=1;i<n;i++) e[i][i+1]=e[i+1][i]=1;
}
il void sol2(int w)
{
	for(int i=w;i<n;i++) e[i][i+1]=e[i+1][i]=1;
}
int main()
{
	cin>>n>>a>>b;
	if(a>1&&b>1) printf("NO"),exit(0);
	else if(a==1&&b==1) sol1();
	else if(a>1) sol2(a);
	else
	{
		sol2(b);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(i!=j) e[i][j]^=1;
	}
	puts("YES");
	for(int i=1;i<=n;i++,puts(""))
		for(int j=1;j<=n;j++)
		{
			printf("%d",e[i][j]);
		}
}
