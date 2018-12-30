#include <bits/stdc++.h>
using namespace std;
#define Max 100003
#define ll long long
ll dp[Max],c[11],d[11],tot,s,ans;
ll f(ll l)
{
    return c[l]*(d[l]+1);
}
int main()
{
    for(int i=1;i<=4;i++) cin>>c[i];
    cin>>tot;
    dp[0]=1;
    for(int i=1;i<=4;++i)
        for(ll j=c[i];j<=Max;++j)
                dp[j]+=dp[j-c[i]];
    while(tot--)
    {
        for(int i=1;i<=4;i++) cin>>d[i];
        cin>>s;
        ans=dp[s];
        if(s>=f(1)) ans-=dp[s-f(1)];
        if(s>=f(2)) ans-=dp[s-f(2)];
        if(s>=f(3)) ans-=dp[s-f(3)];
        if(s>=f(4)) ans-=dp[s-f(4)];
        if(s>=f(1)+f(2)) ans+=dp[s-f(1)-f(2)];
        if(s>=f(1)+f(3)) ans+=dp[s-f(1)-f(3)];
        if(s>=f(1)+f(4)) ans+=dp[s-f(1)-f(4)];
        if(s>=f(2)+f(3)) ans+=dp[s-f(2)-f(3)];
        if(s>=f(2)+f(4)) ans+=dp[s-f(2)-f(4)];
        if(s>=f(3)+f(4)) ans+=dp[s-f(3)-f(4)];
        if(s>=f(1)+f(2)+f(3)) ans-=dp[s-f(1)-f(2)-f(3)];
        if(s>=f(1)+f(2)+f(4)) ans-=dp[s-f(1)-f(2)-f(4)];
        if(s>=f(1)+f(3)+f(4)) ans-=dp[s-f(1)-f(3)-f(4)]; 
        if(s>=f(2)+f(3)+f(4)) ans-=dp[s-f(2)-f(3)-f(4)];
        if(s>=f(1)+f(2)+f(3)+f(4)) ans+=dp[s-f(1)-f(2)-f(3)-f(4)];
        cout<<ans<<endl;
    }
}
