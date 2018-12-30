#include <bits/stdc++.h>
#define il inline
#define ll long long
#define Max 50005
using namespace std;
int tot,head[Max],n,m,vst[Max],s;
struct node
{
	int t,nt;
}e[Max];
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
il void add(int u,int v)
{
	e[++tot].t=v;
	e[tot].nt=head[u];
	head[u]=tot;
}
il bool work(int u,int cl)
{
	vst[u]=cl;
	for(int i=head[u];i;i=e[i].nt)
	{
		int v=e[i].t;
		if(vst[v]&&vst[v]==vst[u]) return false;
		else if(vst[v]&&vst[v]!=vst[u]) continue;
		if(!vst[v])
		{
			if(!work(v,cl^1)) return false;
		}
	}
	return true;
}
int main()
{
	while(n=read())
	{
		memset(head,0,sizeof(head));
		memset(vst,0,sizeof(vst));
		tot=0;
		s=0;
		while(19260817)
		{
			int u=read(),v=read();
			if(u==0&&v==0) break;
			add(u,v);
			add(v,u);
			s=u;
		}
		if(work(s,1)) printf("YES\n");
		else printf("NO\n");
	}
}
