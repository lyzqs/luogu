#include <bits/stdc++.h>
using namespace std;
int e[2005][2005],tu[2005],tv[2005],ans,vst[1005],n,m,k,f[2005][2005],fn[2005],fl;
int read()
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
bool dfs(int u)
{
	for(int v=1;v<=m;v++)
	{
		if(e[u][v]&&!vst[v])
		{
			vst[v]=1;
			if(!tv[v]||dfs(tv[v]))
			{
				tu[u]=v;
				tv[v]=u;
				return 1;
			}
		}
	}
	return 0;
}
int main()
{
	n=read(),m=read(),k=read();
	for(int i=1;i<=k;i++)
	{
		int u=read(),v=read();
		if(u>n||v>m) continue;
		e[u][v]=1;
		//flag[v]=flag[u]=1;
	}
	for(int i=1;i<=n;i++)
	{
		memset(vst,0,sizeof(vst));
		if(!tu[i])
		ans+=dfs(i);
	}	
	//for(int i=1;i<=n+m;i++) printf("%d t:%d \n",i,t[i]);
	printf("%d",ans);
}
