#include<bits/stdc++.h>
#define IL inline
#define RI register int
#define N 1008
IL void read(int &x){
    int f=1;x=0;char s=getchar();
    while(s>'9'||s<'0'){if(s=='-')f=-1;s=getchar();}
    while(s<='9'&&s>='0'){x=x*10+s-'0';s=getchar();}
    x*=f;
}
int res[N][N],n,m,ans;
int left[N][N],right[N][N],up[N][N];
int main()
{
    read(n),read(m);
    for(RI i=1;i<=n;i++)
        for(RI j=1;j<=n;j++)
        {
            left[i][j]=right[i][j]=j;
            up[i][j]=1;
        }//?????????!!
    for(RI i=1,x,y;i<=m;i++)
    {
        read(x),read(y);
        res[x][y]=1;
    }
    for(RI i=1;i<=n;i++)
        for(RI j=2;j<=n;j++)
            if(res[i][j]==0&&res[i][j-1]==0)
                left[i][j]=left[i][j-1];//??????
    for(RI i=1;i<=n;i++)
        for(RI j=n-1;j>0;j--)
            if(res[i][j]==0&&res[i][j+1]==0)
                right[i][j]=right[i][j+1];//??????
    for(RI i=1;i<=n;i++)
        for(RI j=1;j<=n;j++)
        {
            if(i>1&&res[i][j]==0&&res[i-1][j]==0)
            {
                left[i][j]=std::max(left[i][j],left[i-1][j]);
                right[i][j]=std::min(right[i][j],right[i-1][j]);
                up[i][j]=up[i-1][j]+1;
            }
            int a=right[i][j]-left[i][j]+1;
            int b=std::min(a,up[i][j]);
            ans=std::max(ans,b);
        }
    printf("%d",ans);

}
