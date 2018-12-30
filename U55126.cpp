#include <bits/stdc++.h>
#define il inline
#define Max 10005
#define il inline
using namespace std;
char a[Max];
int k1,k2,n;
unsigned long long ans=0;
il int get1(int x,int y)
{
	for(int i=0;i<=n-max(x,y)+1;i++)
	{
		if(a[i+x]!=a[i+y]) return i;
	}
	return n-max(x,y);
}
il int get2(int x,int y)
{
	for(int i=0;i<=max(x,y)-1;i++)
	{
		if(a[x-i]!=a[y-i]) return i;
	}
	return max(x,y);
}
int main()
{
	scanf("%s",a+1);
	cin>>k1>>k2;
	n=strlen(a+1);
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			int len1=get1(i,j),len2=get2(i,j);
			if(len1>k1||len2>k2) continue;
			else ans+=len1*len2;
		}
	}
	cout<<ans<<endl;
}
