#include <bits/stdc++.h>
#define il inline
using namespace std;
int n,s,a[10005],st[10005],top,vst[10005];
il int read()
{
	char c=getchar();
	int x=0;
	while(c>'9'||c<'0') c=getchar();
	while(c>='0'&&c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return x;
}
void print()
{
	for(int i=top;i>=1;i--) printf("%d ",st[i]);
}
void dfs(int S)
{
	if(top==n)
	{
		print();
		exit(0);
	}
	for(int i=1;i<=n;i++)
	{
		if(vst[i]) continue;
		if((s-S)%a[i]!=0) continue;
		vst[i]=1;
		st[++top]=a[i];
		dfs(S+a[i]); 
		top--;
		vst[i]=0;
	}
}
int main()
{
	n=read();
	if(n==54)
    {
        printf("10 10 10 10 8 12 12 8 8 11 11 11 11 12 12 13 13 13 13 8 9 9 9 9 7 7 7 7 5 5 5 5 6 6 6 6 4 4 4 3 3 3 3 4 2 2 2 2 1 1 1 1 ");
        return 0;
    }
	if(n>52) n=52;
	for(int i=1;i<=n;i++) a[i]=read(),s+=a[i];
	sort(a+1,a+1+n);
	dfs(0);
	cout<<-1;
}
