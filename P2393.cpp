#include <bits/stdc++.h>
#define il inline
using namespace std;
long double a,s;
int main()
{
	while(scanf("%Lf",&a)!=EOF) s+=a*1000000;
	printf("%.5Lf",s/1000000);
}
