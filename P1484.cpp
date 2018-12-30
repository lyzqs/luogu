#include <bits/stdc++.h>
#define il inline
#define Max 1000005
#define ll long long
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
ll n,k,vst[Max],a[Max],ans=0,cnt,l[Max],r[Max];
struct node
{
	ll num,w;
};
bool operator < (node a,node b)
{
	return a.w<b.w;
};
priority_queue<node> q;
int main()
{
	n=read();k=read();
	cnt=n+2;
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		q.push((node){i,a[i]});
		l[i]=i-1;
		r[i]=i+1;
	}
	r[0]=1;l[n+1]=n;
	for(int i=1;i<=k;i++)
	{
		while(vst[q.top().num]&&!q.empty()) q.pop();
		node qwq=q.top();
		q.pop();
		int p=qwq.num,w=qwq.w;
		if(w<0) break;
		ans+=w;
		a[p]=a[l[p]]+a[r[p]]-a[p];
		vst[l[p]]=vst[r[p]]=1;
		l[p]=l[l[p]],r[l[p]]=p;
		r[p]=r[r[p]],l[r[p]]=p;
		qwq.w=a[p];
		q.push(qwq);
	}
	if(ans<0) ans=0;
	cout<<ans;
}
