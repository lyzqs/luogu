#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n,r,ans;
int f[50005];
long long s[5005][2];
int find(int k)
{
	if(f[k]==k) return k;
	else return f[k]=find(f[k]);
}
void merge(int a,int b)
{
	int s1=find(a);
	int s2=find(b);
	if(s1!=s2) f[s2]=s1;
}
int main()
{
	scanf("%d%d",&r,&n);
	for(int i=1;i<=n;i++)scanf("%lld%lld",&s[i][0],&s[i][1]);
	ans=n;
	//printf("\n");
	for(int i=1;i<=n;i++) f[i]=i;
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			ll u=abs(s[i][0]-s[j][0]),v=abs(s[i][1]-s[j][1]);
			ll dis=u*u+v*v;
			if(dis<=1ll*4*r*r) 
			{
				if(find(i)!=find(j))
				{
					ans--;
					merge(i,j);
				}
				//printf("%d %d\n",i,j);
			}
		}
	}
	printf("%d",ans);
}
