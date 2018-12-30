#include <bits/stdc++.h>
using namespace std;
int n,T,c,f[100007],ans=2147483647,cnt,cn[100007],cc[100007],Sum=0;
long long SUM=0;
struct node
{
	int v,id;
}p[1000007];
#define QAQ printf("QAQ\n");
int read()
{
	char c=getchar();
	int x=0,num=1;
	while(c>'9'||c<'0') 
	{
		if(c=='-') 
			num=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9') 
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return x*num;
}
bool cmp(node a,node b)
{
	return a.v<b.v;
}
int main()
{
	T=read();
	for(int k=1;k<=T;k++)
	{
		n=read(),c=read();
		for(int i=1;i<=n;i++) p[++cnt].v=read(),p[cnt].id=k;
		cc[k]=c;
		Sum+=c;
	}
	sort(p+1,p+1+cnt,cmp);
	int l=1,r=n;
	for(int i=1;i<=Sum;i++)
	{
		while(!cc[p[l].id]) l++;
		while(!cc[p[r].id]) r--;
		int g1=
	}
    printf("%d",ans);
}
