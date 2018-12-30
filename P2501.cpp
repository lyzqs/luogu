#include <bits/stdc++.h>
#define il inline
#define Max 35005
#define int long long
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
	int t,nt;
}e[Max<<2];
int a[Max],n,b[Max],f[Max],ans,head[Max],tot,l[Max],r[Max],g[Max];
il void add(int u,int v)
{
	e[++tot].t=v;
	e[tot].nt=head[u];
	head[u]=tot;
}
signed main()
{
	n=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		b[i]=a[i]-i;
	}
	g[0]=-inf;
	b[n+1]=inf;
	for(int i=1;i<=n+1;i++)
	{
		int ps=upper_bound(g+1,g+1+ans,b[i])-g;
		if(ps-1==ans) ans++;
		g[ps]=b[i];f[i]=ps;
	//	cout<<ps<<' '<<ans<<' '<<b[i]<<endl;
	}
	cout<<n-ans+1<<endl;
	b[0]=-inf;
	memset(g,0x3f,sizeof(g));
	g[0]=0;
	add(0,0);
	for(int i=1;i<=n;i++)
		add(f[i],i);
	for(int u=1;u<=n+1;u++)
		for(int i=head[f[u]-1];i;i=e[i].nt)
		{
			int v=e[i].t;
			if(v>=u||b[v]>b[u]) continue;
			l[v-1]=0;r[v-1]=0;
			for(int j=v;j<=u;j++) l[j]=l[j-1]+abs(b[j]-b[v]),r[j]=r[j-1]+abs(b[j]-b[u]);
			for(int j=v-1;j<=u;j++)
			{
				g[u]=min(g[u],g[v]+l[j]-l[v-1]+r[u]-r[j]);
			}
		}
	cout<<g[n+1]<<endl;
}
