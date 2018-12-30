#include <bits/stdc++.h>
using namespace std;
int n,k;
int e[100005];
int main()
{
	cin>>n>>k;
	e[0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=k&&i-j>=0;j++)
		{
			e[i]+=e[i-j];
			e[i]%=100003;
		}
	}
	printf("%d",e[n]);
}
