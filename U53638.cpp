#include <bits/stdc++.h>
#define il inline
#define Max 50000005
#define Mod 1000000007
#define Mod2 1000000006
#define Mod3 40000
#define ull unsigned long long
#define rg register
#define ll long long
using namespace std;
ull T,n,ans=0,t;
int a[Mod3+23],b[Mod3+23],c[Mod3+23],d[Mod3+23];
namespace Mker
{
    unsigned long long SA,SB,SC;
    il void init(){scanf("%llu%llu%llu",&SA,&SB,&SC);}
    il unsigned long long rand()
    {
        SA^=SA<<32,SA^=SA>>13,SA^=SA<<1;
        unsigned long long t=SA;
        SA=SB,SB=SC,SC^=t^SA;return SC;
    }
}
il ull qpw(ull a,ull b)
{
	ull res=1;
	while(b)
	{
		if(b&1ll) res=res*a%Mod;
		a=a*a%Mod;
		b>>=1;
	}
	return res;
}
int main()
{
	scanf("%llu",&T);
	Mker::init();
	int m=Mod2/Mod3;
	a[0]=b[0]=c[0]=d[0]=1;
	rg int t1=qpw(94153035,m),t2=qpw(905847205,m);
	for(rg int i=m;i<=Mod2;i+=m) a[i/m]=(1ll*a[i/m-1]*t1)%Mod,b[i/m]=(1ll*b[i/m-1]*t2)%Mod;
	for(rg int i=1;i<m;i++) c[i]=(1ll*c[i-1]*94153035)%Mod,d[i]=(1ll*d[i-1]*905847205)%Mod;
	while(T--)
	{
		n=Mker::rand()%Mod2;
		ans^=((((1ll*a[n/m]*c[n%m]%Mod)-(1ll*b[n/m]*d[n%m]%Mod))*233230706%Mod)+Mod)%Mod;
	//	if(ans==391030355) printf("id:%llu\n",i);
	}
	printf("%llu\n",ans);
}
