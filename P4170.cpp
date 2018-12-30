#include <bits/stdc++.h>
using namespace std;
char c[1005];
int n,f[1005][1005];
int main()
{
	scanf("%s",c+1);
	n=strlen(c+1);
	memset(f,0x3f3f3f3f,sizeof(f));
	for(int i=1;i<=n;i++) f[i][i]=1;
	for(int len=1;len<=n;len++)
	{
		for(int l=1;l<=n-len;l++)
		{
			int r=l+len;
			if(c[l]==c[r])
				f[l][r]=min(min(f[l+1][r],f[l][r-1]),f[l][r]);
			for(int i=l;i<r;i++)
			{
				f[l][r]=min(f[l][r],f[l][i]+f[i+1][r]);
			}
		}
	}
	printf("%d",f[1][n]);
}
