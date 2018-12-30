#include <bits/stdc++.h>
using namespace std;
long long a,b,ans=0;
int getnum(int k)
{
	return k%2==0?1:-1;
}
int main()
{
	cin>>a>>b;
	for(int i=a;i<=b;i++)
	{
		for(int j=1;j<=i;j++)
		{
			ans+=(i/j)*getnum(j);
		}
	}
	cout<<ans;
}
