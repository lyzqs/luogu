#include <bits/stdc++.h>
#define il inline
#define Max 1000005
using namespace std;
struct node
{
	int k,p;
}e[Max];
int q[Max],n,m,len,k,cnt;
il int read()
{
	char c=getchar();
	int x=0;
	while(c>'9'||c<'0') c=getchar();
	while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
	return x;
}
il bool cmp(node a,node b)
{
	return a.p<b.p;
}
int main()
{
	n=read();k=read();
	for(int i=1;i<=k;i++)
	{
		int qwq=read();
		for(int j=1;j<=qwq;j++)
		{
			e[++m].p=read();
			e[m].k=i;
		}
	}
	sort(e+1,e+1+n,cmp);
	int l=1;
	len=e[n].p-e[1].p;
	for(int i=1;i<=n;i++)
	{
		if(!q[e[i].k]) cnt++;
		q[e[i].k]=e[i].p;
		while(l<=i&&e[l].p!=q[e[l].k]) l++;
		if(cnt==k) len=min(len,e[i].p-e[l].p);
	}
	cout<<len<<endl;
}
