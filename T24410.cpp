#include <bits/stdc++.h>
using namespace std;
int main()
{
	double n,m;
	cin>>n>>m;
	n=abs(n);m=abs(m);
	double a=n*n+m*m;
	a=sqrt(a);
	a*=sqrt(2);
	printf("%.2f ",4*a);
	printf("%.2f",a*a);
}
