#include <bits/stdc++.h>
#define il inline
#define Max 1005
using namespace std;
il int read()
{
	char c=getchar();
	int x=0;
	while(c>'9'||c<'0') c=getchar();
	while(c>='0'&&c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return x;
}
int T,n,t[Max],b[Max],f[Max][1<<8][18];
int main()
{
	T=read();
	while(T--)
	{
		n=read();
		for(int i=1;i<=n;i++)
		{
			t[i]=read(),b[i]=read();
		}
		memset(f,0x3f,sizeof(f));
		f[1][0][7]=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<(1<<8);j++)
			{
				for(int k=-8;k<=7;k++)
				{
					if(f[i][j][k+8]<0x3f3f3f3f)
					{
						if(j&1) f[i+1][j>>1][k+7]=min(f[i+1][j>>1][k+7],f[i][j][k+8]);
						else
						{
							int l=0x3f3f3f3f;
							for(int h=0;h<=7;h++)
							{
								if(!((j>>h)&1))
								{
									if(i+h>l) break;
									l=min(l,i+h+b[i+h]);
									int nw=j|(1<<h);
									f[i][nw][h+8]=min(f[i][nw][h+8],f[i][j][k+8]+(i+k?(t[i+k]^t[i+h]):0));
								}
							}
						}
					}
				}
			}
		}
		int ans=0x3f3f3f3f;
		for(int i=0;i<=8;i++)
		{
			ans=min(ans,f[n+1][0][i]);
		}
		cout<<ans<<endl;
	}
}
