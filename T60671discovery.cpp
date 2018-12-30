#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	int n,m,res=0;
	cin>>m;
	//cout<<calc(m);
	for(int i=1;i<=m;i++)
	{
		cout<<i<<':'<<res<<endl;
		res^=(i+i+1);
	}
}
