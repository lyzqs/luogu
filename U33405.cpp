#include <bits/stdc++.h>
using namespace std;
int n,r;
int w[2005],s[2005],vst[2005],ans;
bool check(int k)
{
	int a=k,cnt=0,tot=0;
	memset(vst,0,sizeof(vst));
	while(tot<n)
	{
		for(int i=1;i<=n;i++)
		{
			if(a>=w[i]&&!vst[i])
			{
				a-=w[i];
				vst[i]=1;
				tot++;
			}
		}
		cnt++;
		if(cnt>r) return 0;
		a=k;
	}
	return 1;
}
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	scanf("%d%d",&n,&r);
	for(int i=1;i<=n;i++) scanf("%d",&w[i]);
	sort(w+1,w+1+n,cmp);
	//for(int i=1;i<=n;i++) printf("%d ",w[i]);printf("\n");
	int l=1,r=40000000;
	for(int i=1;i<=200;i++)
	{
		int mid=(l+r)>>1;
		if(check(mid)) r=mid;
		else l=mid+1;
		//printf("%d %d\n",l,r);
	}
	for(int i=l;i>=l-100;i--)
	{
		if(check(i)) ans=i;
	}
	printf("%d",ans);
}
