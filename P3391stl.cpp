#include <bits/stdc++.h>
using namespace std;
vector<int> num;
int n,m;
int main()
{
	scanf("%d%d",&n,&m);
	num.push_back(0);
	for(int i=1;i<=n;i++) num.push_back(i);
	for(int i=1;i<=m;i++)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		reverse(num.begin()+l,num.begin()+r+1);
	}
	for(int i=1;i<=n;i++) printf("%d ",num[i]);
}
