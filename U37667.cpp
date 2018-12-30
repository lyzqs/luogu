#include <bits/stdc++.h>
#define il inline
#define ll long long 
#define Max 500005
using namespace std;
ll l=0,r,n,m,s,q,ql,qr,top=0,Sum=0,ans=0,cs[Max];
queue<ll> al;
queue<ll> ar;
il ll hen(ll qwq)
{
	return qwq/m;
}
il ll shu(ll qwq)
{
	ll res=qwq%m;
	if(res==0) res=m;
	return res;
}
il ll read()
{
	char c=getchar();
	ll x=0,f=1;
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
int main()
{
	n=read(),m=read(),s=read(),q=read();
	r=m;
	for(ll i=1;i<=s;i++)
	{
		ql=read(),qr=read();
		//al[i]=ql,ar[i]=qr;
		if((ql+l)/m+1==(qr+l)/m) l+=(m-shu(ql)+1),r-=(m-qr-l);
		else if(hen(ql+l)==hen(qr+l)&&hen(qr+l)>n)
		{
			printf("Impossible!");
			return 0;
		}
		else if(hen(qr+m)>n)
		{
			r-=(m-qr-l);
		}
		else if(hen(ql+l)==hen(qr+l)) 
		{
			al.push(ql),ar.push(qr);
		}
		if(l==r)
		{
			break;
		}
		if(l>r)
		{
			printf("Impossible!");
			return 0;
		}
	}
	while(!al.empty())
	{
		ql=al.front(),qr=ar.front();
		al.pop(),ar.pop();
		if((ql+l)/m+1==(qr+l)/m) l+=(m-shu(ql+l)+1),r-=(m-shu(qr+l));
		else if(hen(ql+l)==hen(qr+l)&&hen(qr+l)>n)
		{
			printf("Impossible!");
			return 0;
		}
		else if(hen(qr+m)>n)
		{
			r-=(m-qr-l);
		}
		else if(hen(ql+l)==hen(qr+l)) 
		{
			al.push(ql),ar.push(qr);
		}
		if(l==r)
		{
			break;
		}
		if(l>r)
		{
			printf("Impossible!");
			return 0;
		}
	}
	if(l<r)
	{
		printf("Uncertain!");
		return 0;
	}
	for(int i=1;i<=q;i++)
	{
		int qu=read();
		if(hen(qu+l)>n)
		{
			Sum^=0;
			Sum^=0;
			continue;
		}
		Sum^=hen(qu+l);
		Sum^=shu(qu+l);
	}
	printf("%lld",Sum);
}
// n*m+1<=l<r<=(n+1)*m
// a%m
//
