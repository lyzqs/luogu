#include <bits/stdc++.h>
#define Max 105
#define inf 0x3f3f3f3f
using namespace std;
int f[Max][Max][Max];
int a[Max][Max];
int n,m;
inline int mymax(int f,int b,int c,int d,int e)
{
	return max(f,max(b,max(c,max(d,e))));
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>a[i][j];
	memset(f,-1,sizeof(f));
	f[2][1][1]=0;
	for(int k=3;k<=n+m-1;k++)
		for(int i=1;i<m;i++)
			for(int j=i+1;j<=m;j++)
			{
				f[k][i][j]=mymax(f[k][i][j],f[k-1][i][j],f[k-1][i-1][j],f[k-1][i][j-1],f[k-1][i-1][j-1]);
				if(f[k][i][j]!=-1) f[k][i][j]+=(a[k-i][i]+a[k-j][j]);
			}
	cout<<f[m+n-1][m-1][m];
}
