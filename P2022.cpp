#include <bits/stdc++.h>
#define il inline
#define ll unsigned long long
using namespace std;
ll n,m,k;
ll M[25],len,ans;
il ll calc(ll x)
{
	char s[25];
	sprintf(s,"%lld",x);
	ll res=0,qwq=0;
	len=strlen(s);
	for(ll i=0;i<len;i++)
	{
		qwq=qwq*10+s[i]-'0';
		res+=qwq-M[i]+1;
	}
	return res;
}
il ll read()
{
	char c=getchar();
	ll x=0;
	while(c>'9'||c<'0') c=getchar();
	while(c>='0'&&c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return x;
}
int main()
{
	M[0]=1;
	for(int i=1;i<19;i++) M[i]=M[i-1]*10;
	k=read(),m=read();
	for(ll i=0;i<10;i++)
	{
		if(k==M[i]&&m!=i+1)
		{
			puts("0"),exit(0);
		}
	}
	ll dis=calc(k);
	if(m<dis) puts("0"),exit(0);
	if(m==dis) cout<<k,exit(0);
	m-=dis;
	ll qwq;
	ans=M[len];
	for(int i=1;;i++)
    {
        qwq=k*M[i]-M[len+i-1];
        if(m>qwq)
        {
            m-=qwq; 
            ans*=10;
        }
        else break;
    }
    ans+=m-1;
    cout<<ans;
}
