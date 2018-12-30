#include <bits/stdc++.h>
#define il inline
#define Max 2005
using namespace std;
int n,m,p[Max];
long long ans=2147483647;
struct node
{
	int l,r,len;
}e[Max];
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
il bool cmp(node a,node b)
{
	return a.l<b.l;
}
long long getnum()
{
	
}
//priority_queue<int> q1,q2;
void dfs(int nd,int k)
{
	if(nd==n)
	{
		if(k-1>0) return; 
		ans=min(ans,getnum());
		if(k) p[nd]=1,ans=min(ans,getnum());
		p[nd]=0;
		return;
	}
	dfs(nd+1,k);
	if(k) return;
	f[nd]=1;
	dfs(nd+1,k-1);
	f[nd]=0;
}
int main()
{
	//printf("%d",1<<30);
	n=read(),m=read();
	for(int i=1;i<=n;i++)
	{
		e[i].l=read(),e[i].r=read();
		e[i].len=e[i].r-e[i].l+1;
	}
	sort(e+1,e+1+n,cmp);
	dfs(1,m);
}

/*
4                     ================                 have
3/5       -------                              ------
2      -------------------------
1   =========================                          have
    1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17
dp  X  O  O  O  X  X  X  X  O  X  X  X  X  X  O  O  X

f[i][j][1]=
*/
