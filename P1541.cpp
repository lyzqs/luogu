#include <bits/stdc++.h>
#define Max 55
using namespace std;
int f[Max][Max][Max][Max],n,m,g[5],k[355],x;
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>k[i];
	for(int i=1;i<=m;i++)
		cin>>x,g[x]++;
	f[0][0][0][0]=k[1];
	for(int a=0;a<=g[1];a++)
		for(int b=0;b<=g[2];b++)
			for(int c=0;c<=g[3];c++)
				for(int d=0;d<=g[4];d++)
				{
					int s=a+b*2+c*3+d*4+1;
					if(a) f[a][b][c][d]=max(f[a][b][c][d],f[a-1][b][c][d]+k[s]);
					if(b) f[a][b][c][d]=max(f[a][b][c][d],f[a][b-1][c][d]+k[s]);
					if(c) f[a][b][c][d]=max(f[a][b][c][d],f[a][b][c-1][d]+k[s]);
					if(d) f[a][b][c][d]=max(f[a][b][c][d],f[a][b][c][d-1]+k[s]);
				}
 	cout<<f[g[1]][g[2]][g[3]][g[4]];
}
