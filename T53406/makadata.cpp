#include <bits/stdc++.h>
#define Max 500005
#define Add 19260817
#define Mod 300000  
#define Mod2 100000  
#define ll long long
using namespace std;
ll n,m;
map<ll,ll> e;
int Rand()
{
	ll nw=rand()%Mod;
	while(e[nw+1]==1) nw=(nw+Add)%Mod;
	e[nw+1]=1;
	return nw+1;
}
int main()
{
	//freopen("7.in","w",stdout);
	srand(time(0));
	n=100000,m=100000;
	cout<<n<<endl;
	for(int i=1;i<=n;i++)
	{
		printf("%d ",Rand());
	}
	cout<<endl;
	e.clear();
	for(int i=1;i<=n;i++)
	{
		printf("%d ",Rand());
	}
	cout<<endl<<m<<endl;
	e.clear();
	for(int i=1;i<=m;i++)
	{
		printf("%d %d\n",Rand()%Mod2,Rand()%Mod2);
	}
}
