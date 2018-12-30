#include <bits/stdc++.h>
using namespace std;
int a,b,c;
//#define exp 0.0000001
int p=168;
bool check(int x,int y,int z)
{
	a=x,b=y,c=z;
	if(a<b+c) return false;
	a-=(b+c);
	b*=2,c*=2;
	if(b<a+c) return false;
	b-=(a+c);
	a*=2,c*=2;
	if(c<a+b) return false;
	c-=(a+b);
	a*=2,b*=2;
	//if(fun(a/c,7/13))
	if(a*7==c*13&&a!=0&&c!=0) 
	{
		//printf("%d %d %d\n",a,b,c); 
		return true;
	}
	return false;
}
int main()
{
	for(int i=1;i<=p;i++)
		for(int j=1;j<=p-i;j++)
			{
				int k=p-i-j;
				if(check(i,j,k)) printf("i,j,k:%d %d %d\n",i,j,k);
			}
}
