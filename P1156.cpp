#include <bits/stdc++.h>
#define Max 2005
using namespace std;
int f[Max];
struct node
{
	int t,h,ad;
}p[Max];
int h,m,n;
inline bool cmp(node a,node b)
{
	return a.t<b.t;
}
int main()
{
	cin>>m>>n;
	//cout<<m<<n;
	for(int i=1;i<=n;i++)
		cin>>p[i].t>>p[i].ad>>p[i].h;
	sort(p+1,p+1+n,cmp);
	f[0]=10;
	for(int i=1;i<=n;i++)
		for(int j=m;j>=0;j--)
		{
			if(f[j]>=p[i].t)
			{
				if(j+p[i].h>=m)
				{
					cout<<p[i].t;
					return 0;
				}
				f[j+p[i].h]=max(f[j],f[j+p[i].h]);
				f[j]+=p[i].ad;
			}
		}
	//for(int i=1;i<=m;i++) cout<<f[i]<<' ';cout<<endl;
	cout<<f[0];
}
//f[high]=life
