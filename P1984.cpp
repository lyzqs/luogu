#include <bits/stdc++.h>
using namespace std;
double ans=0,nw;
int n;
int main()
{
	cin>>n;
	nw=420000.0/n;
	for(int i=1;i<=n;i++)
	{
		ans+=nw;
		nw*=(1-0.5/i);
	}
	printf("%.2f",ans);
}
