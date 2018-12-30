#include <bits/stdc++.h>
#define Max 1005
#define il inline
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
int e[Max][Max],n,cnt,f[Max],ans;
struct node
{
	int w,u,v;
};
bool operator < (node a,node b)
{
	return a.w>b.w;
}
il int getf(int u)
{
	if(f[u]==u) return f[u];
	else return f[u]=getf(f[u]);
}
priority_queue<node> q;
int main()
{
	n=read();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			e[i][j]=read(),q.push((node){e[i][j],i,j});
	for(int i=1;i<=n;i++) f[i]=i;
	while(cnt<n-1&&!q.empty())
	{
		node qwq=q.top();
		q.pop();
		int u=getf(qwq.u),v=getf(qwq.v);
		if(u==v) continue;
		cnt++;
		f[u]=v;
		ans+=qwq.w;
	}
	cout<<ans;
}
