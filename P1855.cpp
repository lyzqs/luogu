#include <bits/stdc++.h>
#define Max 205
using namespace std;
int n,m,t;
int c[Max],w[Max];
int f[Max][Max];
int main()
{
	cin>>n>>m>>t;
	for(int i=1;i<=n;i++) cin>>c[i]>>w[i];
	for(int i=1;i<=n;i++)
		for(int j=m;j>=c[i];j--)
			for(int k=t;k>=w[i];k--)
				f[j][k]=max(f[j][k],f[j-c[i]][k-w[i]]+1);
	cout<<f[m][t];
}
