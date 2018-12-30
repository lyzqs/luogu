#include <bits/stdc++.h>
#define Max 100005
using namespace std;
int n,m;
int head[Max],tot,cnt,u[Max],v[Max],rc[Max],a,b,vst[Max];
double len[Max],d[Max];
struct node
{
	int t,nt;
	double w;
}e[Max];
double x[Max],y[Max];
int read()
{
	char c=getchar();
	int x=0,num=1;
	while(c>'9'||c<'0') 
	{
		if(c=='-') 
			num=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9') 
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return x*num;
}
void add(int u1,int v1,double w)
{
	e[++tot].t=v1;
	e[tot].nt=head[u1];
	e[tot].w=w;
	head[u1]=tot;
}
int main()
{
	n=read(),m=read();a=read(),b=read();
	for(int i=1;i<=n;i++)
	{
		x[i]=read(),y[i]=read();
	}
	for(int i=1;i<=m;i++)
	{
		u[i]=read(),v[i]=read();
		len[i]=abs(x[u[i]]-x[v[i]])*abs(x[u[i]]-x[v[i]])+abs(y[u[i]]-y[v[i]])*abs(y[u[i]]-y[v[i]]);
		len[i]=sqrt(len[i]);
		//add(u,v,len);
		//add(v,u,len);
	}
	char cc;
	while(scanf("%c",&cc)!=EOF)
	{
		if(cc=='r') break;
		if(cc=='X') 
		{
			int p=read();
			rc[p]=1;
		}
		if(cc=='H')
		{
			int p=read();
			//printf("%d\n",p);
			rc[p]=0;
		}
	}
	for(int i=1;i<=m;i++)
	{
		if(rc[i]) continue;
		add(u[i],v[i],len[i]);
		add(v[i],u[i],len[i]);
	}
	for(int i=1;i<=n;i++) d[i]=0x3f3f3f3f;
	int k=a;
	d[a]=0;
	for(int i=1;!vst[k];i++) 
	{
		vst[k]=true;
		for(int j=head[k];j;j=e[j].nt)
        {
            int v=e[j].t;
            if(!vst[v]&&d[v]>d[k]+e[j].w)
                d[v]=d[k]+e[j].w;
        }
        int minn=2147483647;
        for(int j=1;j<=n;j++)
        {
            if(!vst[j]&&minn>d[j])
            {
                minn=d[j];
                k=j;
            }
        }
	}
	if(d[b]==0x3f3f3f3f) 
	{
		printf("-1");
		return 0;
	}
	printf("%.4f",d[b]);
}
