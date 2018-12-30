#include <bits/stdc++.h>
#define il inline
#define Max 1005
using namespace std;
int e[Max][Max],f1[Max][Max],f2[Max][Max],n,m,k,ans=0,logk,g1[Max][Max],g2[Max][Max];
il int read()
{
	char c=getchar();
	int x=0,f=1;
	while(c>'9'||c<'0')
	{
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
il int query(int x,int y)
{
	int maxv=0,minv=0;
	int h=1<<logk;
	maxv=max(g1[x][y],max(g1[x+k-h][y+k-h],max(g1[x][y+k-h],g1[x+k-h][y])));
	minv=min(g2[x][y],min(g2[x+k-h][y+k-h],min(g2[x][y+k-h],g2[x+k-h][y])));
	//cout<<maxv<<' '<<minv<<endl;
	return maxv-minv;
}
int main()
{
	n=read(),m=read(),k=read();
	//memset(f1,~0x3f,sizeof(f1));
	//memset(f2,0x3f,sizeof(f2));
	//memset(g1,~0x3f,sizeof(g1));
	//memset(g2,0x3f,sizeof(g2));
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			g1[i][j]=g2[i][j]=e[i][j]=f1[i][j]=f2[i][j]=read();
	//cout<<logk<<"~\n";
	for(logk=0;1<<(logk+1)<=k;logk++);
	for(int t=0;t<logk;t++)
	{
		for(int i=0;i+(1<<t)<n;i++)
		{
			for(int j=0;j+(1<<t)<m;j++)
			{
				f1[i][j]=max(f1[i][j],
							max(f1[i+(1<<t)][j+(1<<t)],
							max(f1[i][j+(1<<t)],
							f1[i+(1<<t)][j])));
				f2[i][j]=min(f2[i][j],
							min(f2[i+(1<<t)][j+(1<<t)],
							min(f2[i][j+(1<<t)],
							f2[i+(1<<t)][j])));
				//cout<<"nw:"<<i<<' '<<j<<endl;
				g1[i][j]=max(g1[i][j],f1[i][j]);
				g2[i][j]=min(g2[i][j],f2[i][j]);
			}
		}
	}
	ans=2147483647;
	for(int i=0;i<=n-k;i++)
	{
		for(int j=0;j<=m-k;j++)
			ans=min(ans,query(i,j));//cout<<ans<<' '<<i<<' '<<j<<endl;
	}
	cout<<ans;
}
