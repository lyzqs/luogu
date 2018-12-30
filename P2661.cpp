#include <bits/stdc++.h>
using namespace std;
int to[200005],n,vst[200005],ans=2147483647,flag,rd[200005];
int read()
{
	char c=getchar();
	int x=0;
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return x;
}
void dfs(int s,int t,int l)
{
	if(s==t&&l)
	{
		ans=min(ans,l);
		//flag=1;
		return;
	}
	if(!vst[to[s]])
	{
		//printf("%d\n",to[s]);
		vst[to[s]]=1;
		dfs(to[s],t,l+1);
	}
}
void fun(int k)
{
	vst[k]=1;
	rd[to[k]]--;
	if(!rd[to[k]]&&!vst[to[k]]) fun(to[k]);
}
int main()
{
	n=read();
	//printf("%d",n);
	for(int i=1;i<=n;i++) to[i]=read(),rd[to[i]]++;
	for(int i=1;i<=n;i++) if(!rd[i]&&!vst[i]) fun(i);
	//for(int i=1;i<=n;i++) printf("%d\n",rd[i]);
	for(int i=1;i<=n;i++) 
	{
		if(!vst[i]) dfs(i,i,0);
	}
	printf("%d",ans);
}
