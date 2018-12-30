#include <bits/stdc++.h>
#define il inline
#define Max 1005
using namespace std;
int e[Max][Max],f[Max],vis[Max],f2[Max],vst[Max],a[Max],a2[Max];
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
il void qt(char *s)
{
	puts(s);
	exit(0);
}
il void dfs(int u,int fa)
{
	f[u]=fa;
	vst[u]=1;
}
il void solve()
{
	for(int i=1;i<=n;i++)
	{
		if(!vst[i]) dfs(i,0);
		qt("YES");
	}
}
int main()
{
	n=read(),m=read();
	for(int i=1;i<=m;i++) e[read()][read()]=1;
	solve();
}
