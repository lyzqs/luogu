#include <bits/stdc++.h>
#define il inline
#define Max 2000005
using namespace std;
#define ll long long 
int ans=0,n,x,y;
struct node
{
	int l,r;
}e[Max];
il int read()
{
	char c=getchar();
	int x=0,f=1;
	while(c>'9'||c<'0') 
	{
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
il bool cmp(node a,node b)
{
	return (a.r!=b.r?a.r<b.r:a.l<b.l);
}
int main()
{
	n=read();
	for(int i=1;i<=n;i++) 
		x=read(),y=read(),e[i].l=x-y,e[i].r=x+y;
	sort(e+1,e+1+n,cmp);
	int r=-(1<<30);
	for(int i=1;i<=n;i++)
    {
        if(e[i].l>=r)
        {
            ans++;
            r=e[i].r;
        }
    }
    printf("%d",ans);
}
