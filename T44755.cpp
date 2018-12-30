#include <bits/stdc++.h>
#define il inline
#define Max 10000005
#define ll long long
using namespace std;
inline int cnt(unsigned int i)
{
    i=i-((i>>1)&0x55555555);
    i=(i&0x33333333)+((i>>2)&0x33333333);
    i=(i+(i>>4))&0x0f0f0f0f;
    i=i+(i>>8);
    i=i+(i>>16);
    return i&0x3f;
}
int cnt1=0,cnt2=0,n,p,a,b,c,nw,last;
ll ans=0;
int main()
{
	cin>>n>>a>>b>>c>>p>>last;
	//if(cnt(last)&1) cnt1++;
	//else cnt2++;
	for(int i=1;i<=n;i++)
	{
		nw=((ll)((((1ll*last*last)%p)*1ll*a)%p)+(ll)((1ll*last*b)%p)+1ll*c)%p;
		last=nw;
		if(cnt(nw)&1) ans+=cnt2,cnt1++;
		else ans+=cnt1,cnt2++;
	}
	cout<<ans;
}
