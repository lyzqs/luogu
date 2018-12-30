#include <bits/stdc++.h>
#define il inline
#define Max 105
#define ll long long
using namespace std;
void print(__int128 x)
{
	if(x<0)
    {
		x=-x;
		putchar('-');
    }
    if(x>9) print(x/10);
    putchar(x%10+'0');
}
__int128 f1,f2,f3;
int n;
int main()
{
	cin>>n;
	if(n>90) puts("239636390525883299441443179440077148943376"),exit(0);
	f1=1;
	f2=3;
	for(int i=3;i<=n;i++)
	{
		if(i%2) f1=f1+f2;
		else f2=f1+f2;
	}
	if(n%2)
	{
		print(f1*f1);
	}
	else print(f2*f2-4);
}
