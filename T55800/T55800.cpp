#include <bits/stdc++.h>
#define il inline
using namespace std;
il int read()
{
	char c=getchar();
	int x=0;
	while(c>'9'||c<'0') c=getchar();
	while(c>='0'&&c<='9')
	{
		//cout<<"qwq";
		x=x*10+c-'0';
		x%=100;
		c=getchar();
	}
	return x;
}
int main()
{
	if(read()%2) cout<<"lll6924",exit(0);
	else cout<<"lll6925",exit(0);
}
