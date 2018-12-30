#include <bits/stdc++.h>
#define il inline
#define Max 4005
using namespace std;
int f[205][Max],n,ans=0,pre[205][Max],nd[205][Max],ansj,ansi,cnt=0,s[Max],cs[205][Max],m;
struct node
{
    int t,d,w,num;
}e[Max];
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
il bool cmp(node a,node b)
{
    return a.d<b.d;
}
int main()
{
    n=read();
    for(int i=1;i<=n;i++)
    {
        e[i].t=read(),e[i].d=read(),e[i].w=read();
        e[i].num=i;
        m=max(m,e[i].d);
    }
    sort(e+1,e+1+n,cmp);
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
        	f[i][j]=f[i-1][j];
        	if(j<e[i].d&&j>=e[i].t&&f[i-1][j-e[i].t]+e[i].w>f[i][j])
        	{
			
            f[i][j]=max(f[i][j],f[i-1][j-e[i].t]+e[i].w);
            ans=max(ans,f[i][j]);
            if(ans==f[i][j]) ansj=j;
			}
        }
    }
    printf("%d\n",ans);
    //int qwq=ansj;
    for(int i=n;i>=1;i--)
	{
		if(ansj>=e[i].t&&f[i][ansj]==f[i-1][ansj-e[i].t]+e[i].w)
		{
			cnt++;
			s[cnt]=e[i].num;
			ansj=ansj-e[i].t;
		}
	}
    printf("%d\n",cnt);
    sort(s+1,s+1+cnt);
    for(int i=1;i<=cnt;i++)
    {
        printf("%d ",s[i]);
    }
}
