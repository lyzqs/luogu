//π“¡Àorz£¨¿±º¶dfs–¥π“¡À 
#include <bits/stdc++.h>
#define il inline
#define Max 100005
using namespace std;
struct node
{
    int t,nt;
}e[Max<<1];
int low[Max],head[Max],tot,cnt,dfn[Max],s[Max],top=0,flag=0,vis[Max],vst[Max],n,m,cl,is[Max];
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
il void add(int u,int v)
{
    e[++tot].t=v;
    e[tot].nt=head[u];
    head[u]=tot;
}
il bool dfs(int u,int color)
{
    vst[u]=color;
//	printf("nw:%d %d\n",u,cl);
    for(int i=head[u];i;i=e[i].nt)
    {
        if(vis[i]&&vst[e[i].t]!=color) continue;
        //printf("nw:%d to:%d vst[v]:%d vis[i]:%d\n",u,e[i].t,vst[e[i].t],vis[i]);
        if(!vst[e[i].t]&&!vis[i]) 
        {
            if(!dfs(e[i].t,color)) return false;
        }
        else if(vst[e[i].t]==color) {//printf("false:%d %d\n",u,e[i].t);
        return false;}
    }
    return true;
}
il void tarjan(int u)
{
    low[u]=dfn[u]=++cnt;
    is[u]=1;
	vst[u]=1;
    s[++top]=u;
    for(int i=head[u];i;i=e[i].nt)
    {
        int v=e[i].t;
        if(!dfn[v])
        {
            tarjan(v);
            low[u]=min(low[u],low[v]);
        }
        else if(vst[v]) low[u]=min(low[u],low[v]);
    }
    if(dfn[u]==low[u])
    {
        if(s[top]!=u)
        {
            flag=1;
            int v;
            while(v=s[top--])
            {
            //	printf("qwq:%d %d\n",u,v);
                for(int i=head[v];i;i=e[i].nt)
                {
                    if(!is[e[i].t]) continue;
 					vis[i]=1;
                    //is[i]=1;
                    cl=0;
                //	printf("vis:%d %d\n",v,e[i].t);
                    memset(vst,0,sizeof(vst));
                    for(int j=1;j<=n;j++)
                    {
                        if(vst[j]) continue;
                        if(!dfs(j,++cl)) break;
                        if(j==n) printf("YES"),exit(0);
                    }
                    vis[i]=0;
                }
                if(v==u) break;
            }
            printf("NO");
                exit(0);
        }
        else 
            while(top--)
            {
                //printf("qwq:%d %d\n",u,s[top+1]);
                is[s[top+1]]=0;vst[s[top+1]]=0;
                if(s[top+1]==u) break;
            }
    }
}
int main()
{
    n=read(),m=read();
    for(int i=1;i<=m;i++)
    {
        int u=read(),v=read();
        add(u,v);
    }
    for(int i=1;i<=n;i++)
    {
        if(!flag&&!dfn[i]) tarjan(i);
    }
    //for(int)
    printf("YES");
}
