#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<iostream>
#define ll long long 
using namespace std;
struct node{
    ll to,next;
}e[500001];
ll rt,mod;
ll head[500001],dep[500001],sum[500001],a[500001];
ll tot,num,n,m,lazy[500001],fa[500001],l[500001];
ll ch[500001],top[500001],size[500001],son[500001];
void build(int root,int l,int r)
{
    if(l==r){sum[root]=a[l];return ;}
    int mid=(l+r)>>1;
    build(root<<1,l,mid);
    build(root<<1|1,mid+1,r);
    sum[root]=sum[root<<1]+sum[root<<1|1];sum[root]%=mod;
    return ;
}

void push(int root,int l,int r)
{
    int mid=(l+r)>>1;
    lazy[root<<1]+=lazy[root];lazy[root<<1]%=mod;
    lazy[root<<1|1]+=lazy[root];lazy[root<<1|1]%=mod;
    sum[root<<1]+=lazy[root]*(mid-l+1);sum[root<<1]%=mod;
    sum[root<<1|1]+=lazy[root]*(r-mid);sum[root<<1|1]%=mod;
    lazy[root]=0;
    return ;
}

void update(int root,int left,int right,int l,int r,ll k)
{
    if(l<=left&&r>=right)
    {
    sum[root]+=k*(right-left+1);sum[root]%=mod;
    lazy[root]+=k;lazy[root]%=mod;
    return;
    }
    if(left>r||right<l)return ;
    int mid=(left+right)>>1;
    if(lazy[root])push(root,left,right);
    if(mid>=l)update(root<<1,left,mid,l,r,k);
    if(mid<r) update(root<<1|1,mid+1,right,l,r,k);
    sum[root]=(sum[root<<1|1]+sum[root<<1])%mod;
    return;
}

ll query(int root,int left,int right,int l,int r)
{
    if(l<=left&&r>=right)return sum[root]%mod;
    if(left>r||right<l)return 0;
    int mid=(left+right)>>1;
    if(lazy[root])push(root,left,right);
    ll a=0,b=0;
    if(mid>=l) a=query(root<<1,left,mid,l,r);
    if(mid<r)  b=query(root<<1|1,mid+1,right,l,r);
    return (a%mod+b%mod)%mod;
}

//--------------------?????????-------------------------

void dfs1(int x)
{
    size[x]=1;
    for(int i=head[x];i;i=e[i].next)
    {
        int v=e[i].to;
        if(!dep[v])
        {
            dep[v]=dep[x]+1;
            fa[v]=x;
            dfs1(v);
            size[x]+=size[v];
            if(size[v]>size[son[x]])son[x]=v;
        }
    }
}

void dfs2(int x,int t)
{
    l[x]=++tot;a[tot]=ch[x];top[x]=t;
    if(son[x])dfs2(son[x],t);
    for(int i=head[x];i;i=e[i].next)
    {
        int v=e[i].to;
        if(v!=fa[x]&&v!=son[x])
        dfs2(v,v);
    }
    return ;
}

ll cal1(int x,int y)//?????
{
    ll maxx=0;
    int fx=top[x],fy=top[y];
    while(fx!=fy)
    {
        if(dep[fx]<dep[fy])swap(x,y),swap(fx,fy);
        maxx+=query(1,1,tot,l[fx],l[x]);
        x=fa[fx];fx=top[x];
    }
    if(l[x]>l[y])swap(x,y);
    maxx+=query(1,1,tot,l[x],l[y]);
    return maxx;
}

void cal2(int x,int y,int v)//??????
{
    int fx=top[x],fy=top[y];
    while(fx!=fy)
    {
        if(dep[fx]<dep[fy])swap(x,y),swap(fx,fy);
        update(1,1,tot,l[fx],l[x],v);
        x=fa[fx],fx=top[x];
    }
    if(l[x]>l[y])swap(x,y);
    update(1,1,tot,l[x],l[y],v);
}

ll read()
{
    ll x=0,w=1;char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')w=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
    return x*w;
}

void add(int from,int to)
{
    num++;
    e[num].to=to;
    e[num].next=head[from];
    head[from]=num;
}
int main()
{
    n=read();m=read();rt=read();mod=read();
    for(int i=1;i<=n;i++)ch[i]=read(),ch[i]%=mod;
    for(int i=1;i<n;i++)
    {
        int x=read(),y=read();
        add(x,y);add(y,x);
    }
    dep[rt]=1;fa[rt]=1;
    dfs1(rt);dfs2(rt,rt);build(1,1,n);
    for(int i=1;i<=n<<1;i++) printf("%lld ",l[i]);printf("\n");
    while(m--)
    {
        int qwq=read();
        if(qwq==1){int x=read(),y=read(),z=read();cal2(x,y,z%mod);}
        if(qwq==2){int x=read(),y=read();printf("%lld\n",cal1(x,y)%mod);}
        if(qwq==3){int x=read(),y=read();update(1,1,n,l[x],l[x]+size[x]-1,y%mod);}
        if(qwq==4){int x=read();printf("%lld\n",query(1,1,n,l[x],l[x]+size[x]-1)%mod);}
    //????????
    	printf("\n");for(int i=1;i<=n<<1;i++) printf("%lld ",sum[i]);printf("\n");
    	printf("\n");for(int i=1;i<=n<<1;i++) printf("%lld ",lazy[i]);printf("\n");
    }
    return 0;
}
