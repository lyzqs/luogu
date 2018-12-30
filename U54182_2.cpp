#include <bits/stdc++.h>
#define il inline
#define Max 4
#define ll __int128
using namespace std;
ll Mod;
il ll qpw2(ll a,ll b)
{
	ll res=1;
	while(b)
	{
		if(b&1) res=res*a%Mod;
		a=a*a%Mod;
		b>>=1;
	}
	return res;
}
struct node
{
    ll m[4][4];
}a,b,c;
node operator * (node x,node y)
{
    node res;
    memset(res.m,0,sizeof(res.m));
    for(int i=1;i<=2;i++)
        for(int j=1;j<=2;j++)
            for(int k=1;k<=2;k++)
            {
                res.m[i][j]+=x.m[i][k]*y.m[k][j];
                res.m[i][j]%=Mod;
            }
    return res;
}
il node qpw(node x,ll k)
{
    node res=b;
    while(k)
    {
        if(k&1) res=res*x;
        x=x*x;
        k>>=1;
    }
    return res;
}
ll n;
long long qwq,qwq2;
il void print(ll a)
{
	if(a>=10) print(a/10);
	putchar(a%10+'0');
}
int main()
{
    a.m[1][1]=a.m[1][2]=a.m[2][1]=1;
    for(int i=1;i<=2;i++) b.m[i][i]=1;
    cin>>qwq>>qwq2;
    n=qwq,Mod=qwq2;
    n+=3;
    c=qpw(a,n-1);
    print(qpw2(((c.m[1][1]-n+1)%Mod+Mod)%Mod,n-2));
}
