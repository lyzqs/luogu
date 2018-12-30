#include <bits/stdc++.h>
using namespace std;
int e[205][205],n,m,pre[205],d[205],vst[205],ans1,ans2,u[100005],v[100005];
void dij()
{
    for(int i=1;i<=n;i++) d[i]=0x3f3f3f3f;
    d[1]=0;
    int k;
	//vst[1]=1;
    for(int i=1;i<=n-1;i++)
    {
    	int maxn=0x3f3f3f3f;
		k=0;
    	for(int j=1;j<=n;j++)
    	{
    		if(!vst[j]&&d[j]<maxn)
    		{
    			maxn=d[j];
    			k=j;
            }
        }
        if(k==0) break;
        vst[k]=1;
        for(int j=1;j<=n;j++)
        {
            if(!vst[j]&&d[j]>d[k]+e[k][j])
            {
                pre[j]=k;
                d[j]=d[k]+e[k][j];
            }
        }
    }
}
int main()
{
	//freopen("P2176.in","r",stdin);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++) e[i][j]=0x3f3f3f3f;
    //for(int i=1;i<=n;i++) e[i][i]=0;
    for(int i=1;i<=m;i++)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        e[a][b]=e[b][a]=c;
        u[i]=a;
        v[i]=b;
    }
    dij();
    //for(int i=1;i<=n;i++) printf("%d ",d[i]);
    //printf("\n");
    ans1=d[n];
    int p=n;
    //pre[1]=0;
    for(int i=1;i<=m;i++)
    {
    	e[u[i]][v[i]]*=2;
    	e[v[i]][u[i]]*=2;
    	memset(vst,0,sizeof(vst));
    	dij();
        //for(int i=1;i<=n;i++) printf("%d ",d[i]);
    	//printf("\n");
    	e[u[i]][v[i]]/=2;
    	e[v[i]][u[i]]/=2;
    	ans2=max(ans2,d[n]);
    	//printf("%d\n",ans2);
    	p=pre[p];
    }
    printf("%d",ans2-ans1);
}
