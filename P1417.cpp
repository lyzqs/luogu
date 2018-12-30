#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll f[100005],n,t;
struct node
{
	ll a,b,c;
}e[100005];
inline bool cmp(node x,node y)
{
	return x.b*y.c>x.c*y.b;
}
int main()
{
	cin>>t>>n;
	for(int i=1;i<=n;i++) cin>>e[i].a;
	for(int i=1;i<=n;i++) cin>>e[i].b;
	for(int i=1;i<=n;i++) cin>>e[i].c;
	sort(e+1,e+1+n,cmp);
	for(ll i=1;i<=n;i++)
		for(ll j=t;j>=e[i].c;j--)
			f[j]=max(f[j],f[j-e[i].c]+e[i].a-(j*e[i].b));
	ll ans=0;
	for(ll i=1;i<=t;i++) ans=max(ans,f[i]);
	cout<<ans;
}
