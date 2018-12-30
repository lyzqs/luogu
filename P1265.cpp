#include <bits/stdc++.h>
#define il inline
#define Max 5005
#define inf 0x3f3f3f3f
using namespace std;
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
struct node
{
	int x,y;
}e[Max];
int n,vst[Max];
double d[Max],ans=0;
il double calc(node a,node b)
{
	return sqrt((double)(a.x-b.x)*(a.x-b.x)+(double)(a.y-b.y)*(a.y-b.y));
}
int main()
{
	n=read();
	for(int i=1;i<=n;i++)
	{
		e[i].x=read(),e[i].y=read();
		d[i]=inf;
	}
	int pos;
	d[1]=0;
	for(int i=1;i<=n;i++)
	{
		double mind=inf;
		for(int j=1;j<=n;j++)
		{
			if(!vst[j]&&d[j]<mind) mind=d[j],pos=j;
		}
		ans+=d[pos];
		vst[pos]=1;
		for(int j=1;j<=n;j++)
		{
			d[j]=min(d[j],calc(e[pos],e[j]));
		}
	}
	printf("%.2f",ans);
}
