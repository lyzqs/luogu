#include <bits/stdc++.h>
#define il inline
#define Max 100005
using namespace std;
int e[233][233],n,vst[Max],tot;
char a[Max],b[Max];
il void dfs1(int u)
{
	vst[u]=1;
	++tot;
	for(int i=1;i<=26;i++)
	{
		if(e[u][i]&&!vst[i])
			dfs1(i);
	}
}
il int cnt()
{
	int ans=0;
	memset(vst,0,sizeof(vst));
	for(int i=1;i<=26;i++)
	{
		if(!vst[i])
		{
			tot=0;
			dfs1(i);
			ans+=tot-1;
		}
	}
	return ans;
}
il void dfs2(int u)
{
	vst[u]=1;
	for(int v=1;v<=26;v++)
	{
		if(e[u][v]&&!vst[v])
		{
			putchar(u+'a'-1);
			putchar(' ');
			putchar(v+'a'-1);
			putchar('\n');
			dfs2(v);
		}
	}
}
il void sol()
{
	memset(vst,0,sizeof(vst));
	for(int i=1;i<=26;i++)
	{
		if(!vst[i])
			dfs2(i);
	}
}
int main()
{
	scanf("%d%s%s",&n,a+1,b+1);
	for(int i=1;i<=n;i++)
	{
		if(a[i]!=b[i])
		{
			int u=a[i]-'a'+1;
			int v=b[i]-'a'+1;
			e[u][v]=e[v][u]=1;
		}
	}
	cout<<cnt()<<endl;
	sol();
}
