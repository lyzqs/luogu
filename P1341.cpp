#include <bits/stdc++.h>
#define Max 2005
using namespace std;
int head[Max],n,f[Max],tot,in[Max],cnt,st,e[Max][Max];
char qwq[233],ans[Max<<3];
int find(int x)
{
	if(f[x]==x) return x;
	else return f[x]=find(f[x]);
}
void dfs(int x)
{
	for(int i=0;i<Max;i++)
		if(e[x][i]) e[x][i]=e[i][x]=0,dfs(i);
	ans[n--]=x;
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<Max;i++) f[i]=i;
	for(int i=1;i<=n;i++)
	{
		scanf("%s",qwq);
		in[qwq[1]]++;
		in[qwq[0]]++;
		e[qwq[1]][qwq[0]]=e[qwq[0]][qwq[1]]=1;
		int f1=find(qwq[0]),f2=find(qwq[1]);
		f[f1]=f2;
	}
	for(int i=1;i<Max;i++) if(f[i]==i&&in[i]) cnt++;
	if(cnt!=1)
	{
		puts("No Solution");
		return 0;
	}
	cnt=0;
	for(int i=0;i<Max;i++) 
	{
		if(in[i]&1)
		{
			cnt++;
			if(!st) st=i;
		}
	}	
		
	if(cnt&&cnt!=2)
	{
		puts("No Solution");
		return 0;
	}
	if(!st)
	for(int i=0;i<Max;i++) 
	if(in[i])
	{
		st=i;
		break;
	}
	dfs(st);
	puts(ans);
}
