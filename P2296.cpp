#include <bits/stdc++.h>
#define Max 200005
using namespace std;
int head[Max],n,m,hd,tl,q[Max],s,t,vst[Max],d[Max],b[Max],tot=0,vv[Max];
struct node
{
	int ne,to;
}e[Max];
void add(int u,int h)
{
	e[++tot].to=h;
	e[tot].ne=head[u];;
	head[u]=tot;
}
int read()
{
	char c=getchar();
	int x=0;
	while(c<'0'||c>'9') c=getchar();
	while(c<='9'&&c>='0')
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return x;
}
void dfs(int nd)
{
	vst[nd]=1;
	for(int i=head[nd];i;i=e[i].ne)
	{
		if(!vst[e[i].to]) dfs(e[i].to);
	}
}
int main()
{
	n=read(),m=read();
	for(int i=1;i<=m;i++)
	{
		int u=read(),v=read();
		add(v,u); 
	}
	s=read(),t=read();
	dfs(t);
	for(int i=1;i<=n;i++)
		if(!vst[i])
			for(int j=head[i];j;j=e[j].ne)
				vv[e[j].to]=1;
	for(int i=1;i<=n;i++) if(vv[i]==1) vst[i]=0;
	hd=1;tl=1;
	q[hd]=t;
	b[t]=1;
	for(int i=1;i<=n;i++) d[i]=0x3f3f3f3f;
	//for(int i=1;i<=n;i++) printf("%d ",vst[i]);printf("\n");
	d[t]=0;
	while(hd<=tl)
	{
		for(int i=head[q[hd]];i;i=e[i].ne)
		{
			if(vst[e[i].to]&&d[e[i].to]>d[q[hd]]+1)
			{
				d[e[i].to]=d[q[hd]]+1;
				if(!b[e[i].to]) q[++tl]=e[i].to,b[e[i].to]=1;
			}
		}
		b[q[hd++]]=0;
	}
	printf("%d",d[s]==0x3f3f3f3f?-1:d[s]);
}
