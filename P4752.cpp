#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,a[100005],b[100005],tot=0;
bool check(int s)
{
    if(s==1) return false;
    for(ll i=2;i<=sqrt(s);i++)
    {
        if(s%i==0) return false;
    }
    return true;
}
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
    tot=0;
    scanf("%lld%lld",&n,&m);
    ///int x=n,y=m;
    for(ll i=1;i<=n;i++) 
	{
		scanf("%lld",&a[i]);
		if(a[i]==1)
		{
			n--;i--;
		}
	}
    for(ll i=1;i<=m;i++) 
	{
		scanf("%lld",&b[i]);
		if(b[i]==1) m--,i--;
	}
	if(n-m!=1)
    {
        printf("NO\n");
        continue;
    }
    sort(a+1,a+1+n);
    sort(b+1,b+1+n);
    ll j=n;
    for(ll i=1;i<=m;i++)
    {
        if(a[i]!=b[i])
        {
            j=i;
            break;
        }
        //else break;
    }
    if(check(a[j])) printf("YES\n");
    else printf("NO\n");
    }
}
