#include <bits/stdc++.h>
#define il inline
#define Max 4000005
#define inf 0x3f3f3f3f
#define dg puts("qwq")
//#define getchar() (tt==ss&&(tt=(ss=In)+fread(In,1,Max,stdin),tt==ss)?EOF:*ss++)
using namespace std;
namespace lyzqs
{
	char In[Max],*ss=In,*tt=In;
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
		int t,nt,w;
	}e[Max<<1];
	int tot=1,cur[Max],head[Max],cnt,n,m,k,d[Max],vst[Max],s,t,q[Max];
	il void add1(int u,int v,int w)
	{
		e[++tot].t=v;
		e[tot].nt=head[u];
		e[tot].w=w;
		head[u]=tot;
	}
	il void add(int u,int v,int w)
	{
		//printf("added: %d %d\n",u,v);
		add1(u,v,w),add1(v,u,0);
	}
	il bool bfs()
	{
		int l=1,r=0;
		q[++r]=s;
		memset(d,0,sizeof(d));
		d[s]=1;
		while(l<=r)
		{
			int u=q[l++];
			for(int i=head[u];i;i=e[i].nt)
			{
				int v=e[i].t,w=e[i].w;
				//cout<<"to "<<v<<' '<<w<<endl;
				if(w&&!d[v])
				{
					//cout<<"ok "<<v<<endl;
					d[v]=d[u]+1;
					q[++r]=v;
				}
			}
		}
		return d[t];
	}
	il int dfs(int u,int flw)
	{
		if(u==t) return flw;
		for(int& i=cur[u];i;i=e[i].nt)
		{
			int v=e[i].t,w=e[i].w;
			if(d[v]==d[u]+1&&w)
			{
				int fw=dfs(v,min(w,flw));
				if(fw)
				{
					e[i].w-=fw;
					e[i^1].w+=fw;
					return fw;
				}
			}
		}
		return 0;
	}
	il int dinic()
	{
		int res=0;
		//dg;
		while(bfs())
		{
			//dg;
			for(int i=0;i<=t;i++) cur[i]=head[i];
			int nwflw;
			while((nwflw=dfs(s,inf))) 
				res+=nwflw;
		}
		return res;
	}
	il void main()
	{
		n=read(),m=read(),s=n+m+1,t=n+m+2;
		for(int i=1;i<=n;i++)
		{
			int nw=read();
			cnt+=nw;
			add(s,i,nw);
		}
		for(int i=1;i<=m;i++)
		{
			int p=read();
			for(int j=1;j<=p;j++)
			{
				int u=read();
				add(u,i+n,1);
			}
		}
		for(int i=1;i<=m;i++)
		{
			add(i+n,t,1);
		}
		int dic=dinic();
		//cout<<dic<<' '<<cnt<<endl;
		if(dic==cnt)
		{
			for(int u=1;u<=n;u++)
			{
				printf("%d: ",u);
				for(int i=head[u];i;i=e[i].nt)
				{
					int v=e[i].t,w=e[i].w;
					if(v!=s&&!w)
					{
						printf("%d ",v-n);
					}
				}
				puts("");
			}
		}
		else puts("No Solution!");
	}
}
int main()
{
	lyzqs::main();
}
