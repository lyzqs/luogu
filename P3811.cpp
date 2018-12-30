#include <bits/stdc++.h>
#define ll long long 
using namespace std;
ll inv[23333333],n,p;
int main()
{
	cin>>n>>p;inv[1]=1;
	cout<<"1"<<endl;
	for(ll i=2;i<=n;i++)
	{
		inv[i]=(ll)(p-p/i)*inv[p%i]%p;
		printf("%d\n",inv[i]);
	}
}
