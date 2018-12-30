#include <bits/stdc++.h>
using namespace std;
int n,t,f[201][201][25],s,e,nm[1005],pos,ans[2][205];
int main()
{
	memset(f,127/3,sizeof(f));
	memset(ans,127/2,sizeof(ans));
	scanf("%d%d%d%d",&n,&t,&s,&e);
	for(int i=1;i<=t;i++)
	{
		int d,u,v;
		scanf("%d%d%d",&d,&u,&v);
		if(!nm[u]) nm[u]=++pos;
		if(!nm[v]) nm[v]=++pos;
		f[nm[v]][nm[u]][0]=f[nm[u]][nm[v]][0]=d;
	}
	int lgn=log2(n);
	for(int p=1;p<=lgn;p++)
		for(int k=1;k<=pos;k++)
			for(int i=1;i<=pos;i++)
				for(int j=1;j<=pos;j++)
					f[i][j][p]=min(f[i][k][p-1]+f[k][j][p-1],f[i][j][p]);
	t=0;
	int p=0;
	ans[0][nm[s]]=0;
	while(n)
	{
		if(n&1)
		{
			t=!t;
 			for(int i=1;i<=pos;i++)
            {ans[t][i]=2e9;
            	for(int j=1;j<=pos;j++)
                {
                    ans[t][i]=min(ans[t][i],ans[!t][j]+f[i][j][p]);
                }    
			}
		}
		p++;
		n>>=1;
	}
	printf("%d",ans[t][nm[e]]);
}
