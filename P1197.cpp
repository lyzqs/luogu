#include <bits/stdc++.h>
#define Max 500005
using namespace std;
int n,m,k,f[Max],u[Max],v[Max],kk[Max][105],kn[Max],brk[Max],brn[Max],ans[Max];
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
int ff(int nw)
{
	if(f[nw]==nw) return nw;
	else return f[nw]=ff(f[nw]);
}
void merge(int x,int y)
{
	int f1=ff(x),f2=ff(y);
	if(f1!=f2) f[f1]=f2;
}
int Cnt()
{
	int Ans=0;
	for(int i=1;i<=n;i++) if(f[i]==i) Ans++;
	return Ans;
}
int main()
{
	n=read(),m=read();
	for(int i=1;i<=m;i++)
	{
		u[i]=read(),v[i]=read();
	}
	k=read();
	for(int i=1;i<=k;i++)
	{
		brk[i]=read();
		brn[brk[i]]=1;
	}
	for(int i=1;i<=n;i++) f[i]=i;
	for(int i=1;i<=m;i++)
	{
		if(brn[u[i]]) kk[u[i]][++kn[u[i]]]=v[i];
		if(brn[v[i]]) kk[v[i]][++kn[v[i]]]=u[i];
		else merge(u[i],v[i]);
	}
	ans[1]=Cnt();
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=kn[brk[i]];j++)
		{
			merge(brk[i],kk[brk[i]][j]);
		}
		ans[i+1]=Cnt();
	}
	for(int i=1;i<=k+1;i++) printf("%d\n",ans[i]);
}
