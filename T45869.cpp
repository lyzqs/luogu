#include <bits/stdc++.h>
#define il inline
#define Max 2005
using namespace std;
int n,q;
char e[Max][Max];
inline int read()
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
inline int work(int a,int b)
{
	int ans=1,maxs=0,k1=a,k2=a;
	while(e[--k1][b]==e[++k2][b]&&k1>0&&k2<=n) maxs+=2;
	ans+=maxs;
	k1=b,k2=b,maxs=0;
	while(e[a][++k1]==e[a][--k2]&&k1<=n&&k2>0) maxs+=2;
	ans=max(ans,maxs+1);
	return ans;
}
int main()
{
	n=read(),q=read();
	for(int i=1;i<=n;i++)
		scanf("%s",e[i]+1);
	for(int i=1;i<=q;i++)
	{
		int x=read(),y=read();
		printf("%d\n",work(x,y));
	}
}
