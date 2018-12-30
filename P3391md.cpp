#include <bits/stdc++.h>
#define Max 100005
using namespace std;
int n,m;
int main()
{
	srand(time(0));
	n=rand()%Max+1;
	m=rand()%Max+1;
	printf("%d %d\n",n,m);
	for(int i=1;i<=m;i++)
	{
		int l=rand()%n+1,len=rand()%(n-l-1),r=l+len;
		printf("%d %d\n",l,r);
	}
}
