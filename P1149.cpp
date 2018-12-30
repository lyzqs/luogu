#include <bits/stdc++.h>
using namespace std;
int a[500005],b[15]={6,2,5,5,4,5,6,3,7,6},ans;
int main()
{
	a[0]=6;
	int n;
	cin>>n;
	for(int i=1;i<=2000;i++)
    {
		int j=i;
		while(j)
		{
			a[i]=a[i]+b[j%10];
			j=j/10;
		}
	}
	//for(int i=1;i<=800;i++) cout<<a[i]<<endl;
	for(int i=0;i<=800;i++)
		for(int j=0;j<=800;j++)
			if(a[i]+a[j]+a[i+j]+4==n) ans++;
	cout<<ans;
}
