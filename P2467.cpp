#include <bits/stdc++.h>
using namespace std;
int n,p,f[5][100005],res;
int main()
{
	cin>>n>>p;
	f[0][2]=1;
	for(int i=3;i<=n;i++)
	{
		for(int j=2;j<=i;j++)
		{
			f[i&1][j]=(f[i&1][j-1]+f[(i-1)&1][i-j+1])%p;
		}
	}
	for(int i=2;i<=n;i++)
		res+=f[n&1][i],res%=p;
	cout<<(res*2)%p;
}
