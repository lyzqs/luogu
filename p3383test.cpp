#include<iostream>
#include<cstdio>
using namespace std;
struct data
{
    int pre,to;
}p[220010];
int head[200100],tot;
int n;
int son[200100],siz[200100],father[200100];
int deep[200100];
int top[200100];  
int in[200100],num;  //i?dfs? ???? 
long long s[400100];  //??? 
long long tag[400100];
void add(int x,int y)
{
    p[++tot].pre=head[x];
    p[tot].to=y;
    head[x]=tot;
}
void dfs(int x)
{
    siz[x]++;
    for(int i=head[x];i;i=p[i].pre)
    {
        int v=p[i].to;
        deep[v]=deep[x]+1;
        dfs(v);
        siz[x]+=siz[v];
        if(son[x]==0||siz[v]>siz[son[x]])  son[x]=v;
    }
}
void dfs2(int x)   //?top??? 
{
    in[x]=++num;
    if(son[x]>0)
    top[son[x]]=top[x],dfs2(son[x]);
    for(int i=head[x];i;i=p[i].pre)
    {
        int v=p[i].to;
        if(v!=son[x])
        {
            top[v]=v;
            dfs2(v);
        }
    }
}
void df(int rt,int l,int r)
{
    if(tag[rt])
    {
        int mid=(l+r)>>1;
        long long t=tag[rt];
        tag[rt]=0;
        s[rt<<1]+=(mid-l+1)*t;
        s[rt<<1|1]+=(r-mid)*t;
        tag[rt<<1]+=t;
        tag[rt<<1|1]+=t;
    }
}
void addans(int rt,int l,int r,int x,int y,int z)
{
    if(l>=x&&y>=r)  tag[rt]+=z*1ll,s[rt]+=1ll*(r-l+1)*z;
    else
    {
        int mid=(l+r)>>1;
        df(rt,l,r);
        if(x<=mid)  addans(rt<<1,l,mid,x,y,z);
        if(y>mid)  addans(rt<<1|1,mid+1,r,x,y,z);
        s[rt]=s[rt<<1]+s[rt<<1|1];
    }
}
void hp(int x,int y,int z)
{
    while(top[x]!=top[y])
    {
        if(deep[top[x]]>deep[top[y]])
        {
            addans(1,1,n,in[top[x]],in[x],z);
            x=father[top[x]];
        }
        else
        {
            addans(1,1,n,in[top[y]],in[y],z);
            y=father[top[y]];
        }
    }
    if(deep[x]>deep[y])    //??????? 
    {
        addans(1,1,n,in[y],in[x],z);
    }
    else
    {
        addans(1,1,n,in[x],in[y],z);
    }
}
long long Query(int x,int y,int l,int r,int rt)
{
    if(l>=x&&r<=y)  return s[rt];
    else
    {
        int mid=(l+r)>>1;
        df(rt,l,r);
        long long ans=0;
        if(x<=mid)  ans+=Query(x,y,l,mid,rt<<1);
        if(y>mid)  ans+=Query(x,y,mid+1,r,rt<<1|1);
        return ans;
    }
}
int main()
{
    scanf("%d",&n);
    int x,y,z;
    for(int i=1;i<=n-1;i++)
    {
        scanf("%d%d",&x,&y);
        father[y]=x;
        add(x,y);
    }
    dfs(0);
    top[0]=0;
    dfs2(0);
    int q;
    scanf("%d",&q);
    char c;
    for(int i=1;i<=q;i++)
    {
        cin>>c;
        if(c=='A')  
        {
            scanf("%d%d%d",&x,&y,&z);
            hp(x,y,z);
        }
        else
        {
            scanf("%d",&x);
            printf("%lld\n",Query(in[x],in[x]+siz[x]-1,1,n,1));
        }
        for(int i=1;i<=n<<1;i++) printf("%d ",s[i]);printf("\n");
    }
    return 0;
}
