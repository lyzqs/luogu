#include <bits/stdc++.h>
using namespace std;
int a[35][35],n,p[35][35],g[35],x[35],sum,s[35][35];
void gauss()
{
    for(int i=1;i<=30;i++)
	{
        for(int j=1;j<=30;j++)
		{
        	while(j<=30&&s[i][j]==0) j++;
            if(p[j][j]==0)
			{
				//printf("p%d s%d:",j,i);
            	for(int k=j;k<=31;k++) p[j][k]=s[i][k];
				//for(int k=1;k<=31;k++) printf("%d ",p[j][k]);
            	//printf("\n");
                break;
            }
            for(int k=j;k<=31;k++) s[i][k]^=p[j][k];
            //printf("s%d p%d:",i,j);
            //for(int k=1;k<=31;k++) printf("%d ",s[i][k]);
            //printf("\n");
        }
    }
    for(int i=30;i>=1;i--)
	{
        x[i]=p[i][31];
        for(int j=i+1;j<=30;j++) x[i]^=p[i][j]&x[j];
        x[i]&=p[i][i];
    }
}
void print()
{
    for(int i=0;i<5;i++)
    {
        for(int j=1;j<6;j++)
        {
            printf("%d ",x[i*6+j]);
        }
        printf("%d\n",x[i*6+6]);
    }
}
inline int num(int x,int y){
    if(x==0 || x==6 || y==0 || y==7) return 0;
    return (x-1)*6+y;
}
int sx[5]={0,1,-1,0,0};
int sy[5]={0,0,0,1,-1};
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=5;i++)
	{
        for(int j=1;j<=6;j++)
		{
            for(int k=0;k<=4;k++) a[num(i+sx[k],j+sy[k])][num(i,j)]=1;
    	}
    }
	/*
    for(int i=1;i<=30;i++)
    {
        for(int j=1;j<=30;j++) printf("%d ",a[i][j]);
        printf("\n");
    }
    //*/
    for(int i=1;i<=n;i++)
    {
        memset(g,0,sizeof(g));
        memset(p,0,sizeof(p));
        memset(s,0,sizeof(s));
        memset(x,0,sizeof(x)); 
        for(int j=1;j<=30;j++)
        {
        	for(int k=1;k<=30;k++)
            {
            	s[j][k]=a[j][k];
            	//printf("%d ",s[j][k]);
			}
			//printf("\n");
		}
        for(int j=1;j<=30;j++) scanf("%d",&s[j][31]);
        printf("PUZZLE #%d\n",i);
        gauss();
        print();
    }
}
