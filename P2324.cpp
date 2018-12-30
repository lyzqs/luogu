#include <bits/stdc++.h>
#define il inline
#define Max 15
#define xx x+nx[i]
#define yy y+ny[i]
using namespace std;
int nx[]={0,1,1,-1,-1,2,2,-2,-2};
int ny[]={0,2,-2,2,-2,1,-1,1,-1};
int to[Max][Max]=
{
	{0,0,0,0,0,0},
	{0,1,1,1,1,1},
	{0,0,1,1,1,1},
	{0,0,0,2,1,1},
	{0,0,0,0,0,1},
	{0,0,0,0,0,0}
};
int e[Max][Max],T,n,flg,sx,sy;
il bool ok(int x,int y)
{
	if(x<1||x>5||y<1||y>5) return 1;
	return 0;
}
il int calc()
{
	int res=0;
	for(int i=1;i<=5;i++)
		for(int j=1;j<=5;j++)
		{
			if(e[i][j]!=to[i][j]) res++;
		}
	return res;
}
il void dfs(int s,int x,int y,int lim)
{
	if(s==lim)
	if(!calc())
	{
		flg=1;
		return;
	}
	for(int i=1;i<=8;i++)
	{
		if(ok(xx,yy)) continue;
		swap(e[x][y],e[xx][yy]);
		int w=calc();
		if(w+s<=lim)
		{
			dfs(s+1,xx,yy,lim);
		}
		swap(e[x][y],e[xx][yy]);
	}
}
int main()
{
	cin>>T;
	while(T--)
	{
		flg=0;
		char ch;
		for(int i=1;i<=5;i++)
			for(int j=1;j<=5;j++)
			{
				cin>>ch;
				if(ch=='*') e[i][j]=2,sx=i,sy=j;
				else e[i][j]=ch-'0';
			}
		if(!calc()) 
		{
			puts("0");
			continue;
		}
		for(int i=1;i<=15;i++)
		{
			dfs(0,sx,sy,i);
			if(flg)
			{
				cout<<i<<endl;
				break;
			}
		}
		if(!flg) cout<<"-1\n";
	}
}
