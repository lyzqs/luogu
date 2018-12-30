#include <bits/stdc++.h>
#define Max 205
#define inf 0x3f3f3f3f
#define il inline
#define qwq() cout<<"qwq"<<endl
using namespace std;
int f[Max][Max*Max],n,s[Max],ans=inf;
il int read()
{
	int x=0;
	char c=getchar();
	while(c>'9'||c<'0') c=getchar();
	while(c>='0'&&c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return x;
}
struct node
{
	int d,c;
}e[Max];
il bool cmp(node a,node b)
{
	return a.c>b.c;
}
int main()
{
	n=read();
	for(int i=1;i<=n;i++) e[i].d=read(),e[i].c=read();
	//cout<<n<<" 233"<<endl;
	sort(e+1,e+1+n,cmp);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+e[i].d;
	memset(f,inf,sizeof(f));
	f[0][0]=0;
	//cout<<n<<" 233"<<endl;
	for(int i=1;i<=n;i++)
		for(int j=0;j<=s[i];j++)
		{
			if(j>=e[i].d) f[i][j]=min(f[i][j],max(f[i-1][j-e[i].d],j+e[i].c));
			f[i][j]=min(f[i][j],max(f[i-1][j],s[i]-j+e[i].c));
			//printf("%d %d:%d\n",i,j,f[i][j]);
		}
	for(int i=0;i<=s[n];i++)
		ans=min(ans,f[n][i]);
	cout<<ans;
}
