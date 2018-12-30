#include <bits/stdc++.h>
#define il inline
#define Mod 80000
using namespace std;
int a[Mod];
char o[6]={"TBIAQ"};
int main()
{
	freopen("P2596.in","w",stdout);
	srand(time(0));
	int n=rand()%Mod,m=rand()%10+n;
	printf("%d %d\n",n,m);
	for(int i=1;i<=n;i++) a[i]=i;
	random_shuffle(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		printf("%d ",a[i]);
	}
	puts("");
	for(int i=1;i<=m;i++)
	{
		int opt=rand()%5;
		printf("%c ",o[opt]);
		if(opt==1||opt==0||opt==3||opt==4)
			printf("%d\n",rand()%n+1);
		if(opt==2)
			printf("%d %d\n",rand()%(n-5)+3,1-(rand()%3));
	}
}
