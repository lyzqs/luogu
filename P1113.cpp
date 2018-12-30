#include <bits/stdc++.h>
#define Max 20005
using namespace std;
int n,ans[Max],l,ma,s,k;
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
int main()
{
	n=read();
	for(int i=1;i<=n;i++)
	{
		i=read();
		l=read();
		s=0;
		while(k=read())
			s=max(s,ans[k]);
		ans[i]=s+l;
		ma=max(ans[i],ma);
	}
	cout<<ma;
}
