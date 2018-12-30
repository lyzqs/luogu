#include <bits/stdc++.h>
#define il inline
#define Max 1005
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
int e[Max][Max];
struct nd
{
	int x,y;
}t1[Max],t2[Max];
int tot,n,m,vst[Max],to[Max],cnt,ans;
il double dis(nd x,nd y)
{
	double a=abs(x.x-y.x),b=abs(x.y-y.y);
	return sqrt(a*a+b*b);
}
il bool dfs(int i)
{
	for(int j=1;j<n;j++)
	{
		if(vst[j]!=cnt&&e[i][j])
		{
			vst[j]=cnt;
			if(!to[j]||dfs(to[j]))
			{
				to[j]=i;
				return 1;
			}
		}
	}
	return 0;
}
int main()
{
	n=read(),m=read();
	for(int i=1;i<=n;i++)
	{
		t1[i].x=read(),t1[i].y=read();
	}
	for(int i=1;i<=m;i++)
	{
		t2[i].x=read(),t2[i].y=read();
	}
	for(int i=1;i<=n-1;i++)
		for(int j=1;j<=m;j++)
		{
			if(dis(t1[i],t1[i+1])>(dis(t1[i],t2[j])+dis(t2[j],t1[i+1]))/2.0)
				e[j][i]=1;
		}
	for(int i=1;i<=m;i++)
	{
		cnt++;
		ans+=dfs(i);
	}
	cout<<ans+n<<endl;
	for(int i=1;i<=n;i++)
	{
		cout<<t1[i].x<<' '<<t1[i].y;
		if(i==n) puts("");
		else
		{
			cout<<' ';
			if(to[i])
			{
				cout<<t2[to[i]].x<<' '<<t2[to[i]].y<<' ';
			}
		}
	}
}
