#include <bits/stdc++.h>
#define il inline
#define Max 1005
using namespace std;
int cnt=0,n,m,a[Max][Max],u[Max][Max],l[Max][Max],r[Max][Max],ans=0;
char c; 
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
int main()
{
	n=read(),m=read();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			{
				cin>>c;
				//cout<<' '<<c<<endl;
				a[i][j]=(c=='F'?1:0),u[i][j]=1,l[i][j]=r[i][j]=j;
			}
	for(int i=1;i<=n;i++)
		for(int j=2;j<=m;j++)
			if(a[i][j]&&a[i][j-1]) l[i][j]=l[i][j-1];
	for(int i=1;i<=n;i++)
		for(int j=m-1;j>=1;j--)
			if(a[i][j]&&a[i][j+1]) r[i][j]=r[i][j+1];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			if((i-1)&&a[i][j]&&a[i-1][j])
			{
				u[i][j]=u[i-1][j]+1;
				l[i][j]=max(l[i][j],l[i-1][j]);
				r[i][j]=min(r[i][j],r[i-1][j]);
			}
			int len=r[i][j]-l[i][j]+1;
			ans=max(ans,len*u[i][j]);
		}
	printf("%d",ans*3);
}
