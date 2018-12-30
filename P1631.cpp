#include <bits/stdc++.h>
#define il inline
#define Max 200005
#define nx1 p1+1
#define nx2 p2+1
using namespace std;
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
int a[Max],b[Max],n;
struct node
{
	int w,x,y;
};
bool operator < (node a,node b)
{
	return a.w>b.w;
}
priority_queue<node> q;
int main()
{
	n=read();
	for(int i=1;i<=n;i++)
		a[i]=read();
	for(int i=1;i<=n;i++)
		b[i]=read();
	sort(a+1,a+1+n);
	sort(b+1,b+1+n);
	for(int i=1;i<=n;i++)
	{
		q.push((node){a[i]+b[1],i,1});
	}
	for(int i=1;i<=n;i++)
	{
		node qwq=q.top();
		q.pop();
		printf("%d ",qwq.w);
		q.push((node){a[qwq.x]+b[qwq.y+1],qwq.x,qwq.y+1});
	}
}
