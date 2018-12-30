#include <bits/stdc++.h>
#define il inline
#define ll long long
#define Mod 19491001
#define Max 19491005
using namespace std;
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
ll n,m,p,T;
int a[Max];
il ll qpw(ll a,ll b)
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
ll C(ll x,ll y)
{
    if(y>x) return 0;
    return (1ll*a[x]*qpw(a[y],Mod-2)%Mod)*qpw(a[x-y],Mod-2)%Mod;
}
il ll lucas(ll n,ll m)
{
    if(!m) return 1;
    return C(n%Mod,m%Mod)*lucas(n/Mod,m/Mod)%Mod; 
}
int main()
{
    T=read();
    a[1]=1;
    for(ll i=2;i<=Mod;i++) a[i]=1ll*a[i-1]*i%Mod;
    while(T--)
    {
        n=read(),m=read();
        cout<<lucas(n+m,min(n,m))<<endl;
    }
}
