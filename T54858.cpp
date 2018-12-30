#include <bits/stdc++.h>
#define il inline
#define Max 1005
#define nx xx+Nx[i]
#define ny yy+Ny[i]
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
int n,e[Max][Max],x[Max*Max],y[Max*Max],cnt,h=1,vst[Max*Max],no,vis[Max][Max],tot;
char in[Max];
int Nx[4]={1,0,-1,0};
int Ny[4]={0,1,0,-1};
il bool dfs(int xx,int yy,int nw)
{
	vis[xx][yy]=1;
	if(e[xx][yy]==no) return 0;
	if(e[xx][yy]==0) return 1;
	for(int i=0;i<4;i++)
	{
		if(nx>n||ny>n||nx<1||ny<1||e[nx][ny]==no||vis[nx][ny]) continue;
		if(dfs(nx,ny,nw)) return 1;
	}
	return 0;
}
il void pre()
{
	memset(vis,0,sizeof(vis));
}
il bool check(int xx,int yy,int nw)
{
	int flag=1;
	if(nw==1) no=1;
	else no=2;
	e[xx][yy]=no;
	if(xx+1<=n)
		pre(),flag=flag&&dfs(xx+1,yy,1^e[xx+1][yy]);
	if(xx-1>0)
		pre(),flag=flag&&dfs(xx-1,yy,1^e[xx-1][yy]);
	if(yy+1<=n)
		pre(),flag=flag&&dfs(xx,yy+1,1^e[xx][yy+1]);
	if(yy-1>0)
		pre(),flag=flag&&dfs(xx,yy-1,1^e[xx][yy-1]);
	if(!flag) e[xx][yy]=0;
	return flag;
}
int main()
{
	n=read();
	if(n==1) printf("-1 -1"),exit(0);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",in+1);
		for(int j=1;j<=n;j++)
		{
			if(in[j]=='X') e[i][j]=1;
			else if(in[j]=='O') e[i][j]=2;
			else e[i][j]=0,cnt++,x[cnt]=i,y[cnt]=j;
		}
	}
	/*
	for(int i=1;i<=n;i++,puts(""))
		for(int j=1;j<=n;j++)
			printf("%d ",e[i][j]);*/
	for(int i=1;i<=cnt;i++)
	{
		int use=0;
		for(int j=1;j<=cnt;j++)
		{
			if(vst[j]) continue;
			if(check(x[j],y[j],i%2))
			{
				tot++;
				printf("%d %d\n",x[j],y[j]);
				vst[j]=1;
				use=1;
				break;
			}
			if(tot==105) exit(0);
		}
		if(!use) printf("-1 -1"),exit(0);
	}
}
