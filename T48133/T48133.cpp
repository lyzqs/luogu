#include <bits/stdc++.h>
#define il inline
#define Max 5000005
#define dep 4
using namespace std;
int head[Max],tot,n,m,qr,d[Max],vst[Max],cnt,q[Max<<2];
struct node
{
	int t,nt;
}e[Max<<1];
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
il int bfs(int s,int t)
{
	//int res=0;
	//memset(vst,0,sizeof(vst));
	memset(d,0,sizeof(d));
	//queue<int> q;
	int l=1,r=0;
	q[++r]=s;
	vst[s]=++cnt;
	d[s]=0;
	while(l<=r)
	{
		int u=q[l++];
		for(int i=head[u];i;i=e[i].nt)
		{
			int v=e[i].t;
			if(vst[v]!=cnt)
			{
				q[++r]=v;
				d[v]=d[u]+1;
				vst[v]=cnt;
				//printf("u:%d v:%d\n",u,v);
				if(v==t) return d[v];
			}
		}
	}
	return -1;
}
il int sol(int s,int t)
{
	int res=0x3f3f3f3f;
	//memset(vst,0,sizeof(vst));
	memset(d,0,sizeof(d));
	//queue<int> q1,q2;
	int l=1,r=0;
	q[++r]=s;
	vst[s]=++cnt;
	while(d[q[l]]<dep)
	{
		int u=q[l++];
		//if(vst[u]) continue;
		for(int i=head[u];i;i=e[i].nt)
		{
			int v=e[i].t;
			if(vst[v]!=cnt)
			{
				d[v]=d[u]+1;
				q[++r]=v;
				d[v]=d[u]+1;
				vst[v]=cnt;
				//printf("1:%d %d\n",u,v);
			}
		}
	}
	l=1,r=0;
	q[++r]=t;
	vst[t]=++cnt;
	//printf("qwq")
	if(d[t]) return d[t];
	while(d[q[l]]<=dep)
	{
		int u=q[l++];
		//if(vst[u]) continue;
		for(int i=head[u];i;i=e[i].nt)
		{
			int v=e[i].t;
			if(vst[v]!=cnt&&vst[v]!=cnt-1)
			{
				q[++r]=v;
				d[v]=d[u]+1;
				vst[v]=cnt;
				//printf("2:%d %d\n",u,v);
			}
			else if(vst[v]==cnt-1) res=min(res,d[v]+d[u]+1);//,printf("!%d %d %d %d\n",u,v,d[u],d[v]);
		}
		if(res!=0x3f3f3f3f) break;
	}
	if(res==0x3f3f3f3f)
	{
		return bfs(s,t);
	}
	//cout<<"qwq";
	return res;
}
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.ans","w",stdout);
	n=read(),m=read(),qr=read();//cout<<n<<m<<q;
	//printf("%d %d %d\n",n,m,q);
	for(int i=1;i<=m;i++) 
	{
		int u=read(),v=read();
		add(u,v);add(v,u);
		//printf("%d %d\n",u,v);
	}
	for(int i=1;i<=qr;i++)
	{
		int u=read(),v=read();
		//int s=clock();
		printf("%d\n",sol(u,v));
		//int t=clock(); printf("time:%dms\n",t-s);
		//printf("%d %d\n",u,v);
	}
}
