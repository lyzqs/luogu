#include <bits/stdc++.h>
#define il inline
#define ull unsigned long long 
using namespace std;
ull x=1,y=1;
int main()
{
	ull mod;
	cin>>mod;
    ull now=2;
    while(1)
    {
        ull tmp=(x+y)%mod;
        now++;
        if(y==1&&tmp==1)
        {
            printf("%lld",now-2);
            return 0;
        }
        x=y,y=tmp;
    }
}
