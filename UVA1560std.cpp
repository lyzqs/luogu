#include <bits/stdc++.h>
using namespace std;

inline int read(){
    int x=0,f=1;char cc=getchar();
    while(cc<'0' || cc>'9') {if(cc=='-') f=-1;cc=getchar();}
    while(cc>='0' && cc<='9') {x=x*10+cc-'0';cc=getchar();}
    return x*f;
}

int n=5,m=6,p=30,tt;
int sx[5]={0,1,-1,0,0};
int sy[5]={0,0,0,1,-1};
bool a[6][7],s[31][32],t[31][32],ans[31];

inline int num(int x,int y){
    if(x==0 || x==n+1 || y==0 || y==m+1) return 0;
    return (x-1)*m+y;
}

int main(){
    tt=read();
    for(int id=1;id<=tt;id++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++) a[i][j]=read();
        }
        for(int i=1;i<=p;i++){
            for(int j=1;j<=p;j++) s[i][j]=0;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                s[num(i,j)][p+1]=a[i][j];
                for(int k=0;k<=4;k++) s[num(i+sx[k],j+sy[k])][num(i,j)]=1;
            }
        }
        for(int i=1;i<=p;i++){
            for(int j=1;j<=p+1;j++) t[i][j]=0;
        }
        for(int i=1;i<=p;i++){
            for(int j=1;j<=p;j++){
                for(;j<=p && s[i][j]==0;j++);
                if(t[j][j]==0){
                	printf("p%d s%d:",j,i);
                    for(int k=j;k<=p+1;k++) t[j][k]=s[i][k];
                    for(int k=1;k<=31;k++) printf("%d ",t[j][k]);
            		printf("\n");
                    break;
                }
                for(int k=j;k<=p+1;k++) s[i][k]^=t[j][k];
                printf("s%d p%d:",i,j);
            	for(int k=1;k<=31;k++) printf("%d ",s[i][k]);
            	printf("\n");
            }
        }
        for(int i=p;i>=1;i--){
            ans[i]=t[i][p+1];
            for(int j=i+1;j<=p;j++) ans[i]^=t[i][j]&ans[j];
            ans[i]&=t[i][i];
        }
        printf("PUZZLE #%d\n",id);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m-1;j++) printf("%d ",ans[num(i,j)]);
            printf("%d\n",ans[num(i,m)]);
        }
    }
}
