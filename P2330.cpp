#include <bits/stdc++.h>
#define il inline
#define Max 100005
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
int n,m,f[Max],cnt=0,ans=0;
il int getf(int u)
{
	if(f[u]==u) return f[u];
	else return f[u]=getf(f[u]);
}
struct node
{
	int w,u,v;
};
bool operator < (node a,node b)
{
	return a.w>b.w;
}
priority_queue<node> q;
int main()
{
	n=read(),m=read();
	//printf("%d ",n-1);
	for(int i=1;i<=m;i++)
	{
		int u=read(),v=read(),w=read();
		q.push((node){w,u,v}); 
	}
	for(int i=1;i<=n;i++) f[i]=i;
	while(cnt<n-1&&!q.empty())
	{
		node qwq=q.top();
		q.pop();
		int u=getf(qwq.u),v=getf(qwq.v);
		if(u==v) continue;
		else f[u]=v;
		cnt++;
		ans=max(ans,qwq.w);
	}
	cout<<n-1<<' '<<ans;
}
