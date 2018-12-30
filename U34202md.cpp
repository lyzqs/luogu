#include <bits/stdc++.h>
using namespace std;
int main()
{
	//freopen("U34202.in","w",stdout);
	srand(clock());
	int a=rand()%200000+1;
	int b=rand()%200000+1;
	if(a>b) swap(a,b);
	//if(a-b<200000) a=1,b=20000000;
	printf("%d %d",a,b);
}
