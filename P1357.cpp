#include <bits/stdc++.h>
#define il inline
#define Mod 1000000007
#define ll long long
using namespace std;
ll Max;
struct node
{
	ll m[64<<1][64<<1];
}t,res,qwq;
ll n,m,k,ok[64<<1],pw[20],ans;
node operator * (node a,node b)
{
	node c;
	for(int i=0;i<=Max;i++)
		for(int j=0;j<=Max;j++)
		{
			c.m[i][j]=0;
			for(int k=0;k<=Max;k++)
				c.m[i][j]+=a.m[i][k]*b.m[k][j],c.m[i][j]%=Mod;
		}
	return c;
}
il void check(int zt,int num)
{
	ok[zt]=1;
	int last=zt>>1;
	t.m[last][zt]=1;
	if(num==k&&!(zt&1)) return;
	t.m[last+pw[m]][zt]=1;
}
il void dfs(int pos,int cnt,int zt)
{
	if(pos==m+1)
	{
		check(zt,cnt);
		return;
	}
	dfs(pos+1,cnt,zt);
	if(cnt<k) dfs(pos+1,cnt+1,zt|pw[pos]);
}
il void qpw()
{
	while(n)
	{
		if(n&1) res=res*t;
		t=t*t;
		n>>=1;
	}
}
int main()
{
	pw[1]=1;for(int i=2;i<=10;i++) pw[i]=pw[i-1]<<1;
	cin>>n>>m>>k;
	Max=1<<m;
	Max-=1;
	for(int i=0;i<=Max;i++) res.m[i][i]=1;
	dfs(1,0,0);
	qpw();
	for(int i=0;i<=Max;i++)
	{
		if(ok[i]) ans+=res.m[i][i],ans%=Mod;
	}
	cout<<ans;
}
