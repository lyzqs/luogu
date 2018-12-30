#include <bits/stdc++.h>
#define il inline
#define Max 100005
#define dg puts("qwq")
#define ls(x) e[x].s[0]
#define rs(x) e[x].s[1]
#define fa(x) e[x].f
using namespace std;
il int read()
{
    char c=getchar();
    int x=0,f=1;
    while(c>'9'||c<'0')
    {
        if(c=='-') f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9')
    {
        x=x*10+c-'0';
        c=getchar();
    }
    return x*f;
}
struct node
{
    int sz,s[2],id,f;
}e[Max];
int n,m,rt,cnt,pos[Max];
il int rlt(int x)
{
    return rs(fa(x))==x;
}
il void pushup(int x)
{
    e[x].sz=e[ls(x)].sz+e[rs(x)].sz+1;
    pos[e[ls(x)].id]=ls(x),pos[e[rs(x)].id]=rs(x);
}
il void ct(int x,int f,int k)
{
    e[x].f=f;
    e[f].s[k]=x;
}
il void rot(int x)
{
    int y=fa(x),z=fa(y),ys=rlt(x),zs=rlt(y),k=e[x].s[ys^1];
    ct(k,y,ys),ct(y,x,ys^1),ct(x,z,zs);
    pushup(y),pushup(x);
}
il void splay(int x,int to)
{
    for(int y;(y=fa(x))!=to;rot(x))
    {
        if(fa(fa(x))==to) continue;
        if(rlt(x)==rlt(y)) rot(y);
        else rot(x);
        //cout<<y<<' '<<to<<endl;
    }
    pos[e[x].id]=x;
    if(to==0) rt=x;
}
il void add(int k)
{
    int f=rt;while(rs(f)) f=rs(f);
    int x=++cnt;
    e[x].f=f;
    rs(f)=x;
    e[x].id=k;
    pos[e[x].id]=x;
    e[x].sz=1;
    ls(x)=rs(x)=0;
    splay(x,0);
}
il void tb(int s,int k)
{
    splay(pos[s],0);
    if(!e[rt].s[k]) return;
    if(!e[rt].s[!k]) e[rt].s[!k]=e[rt].s[k],e[rt].s[k]=0;
    else
    {
        int x=e[rt].s[!k];
        while(e[x].s[k]) x=e[x].s[k];
        fa(e[rt].s[k])=x;
        e[x].s[k]=e[rt].s[k];
        e[rt].s[k]=0;
        splay(e[x].s[k],0);
    }
}
il void ins(int t,int s)
{
    //cout<<t<<' '<<s<<endl; 
    splay(pos[s],0);
    if(!t) return;
    if(t==1)
    {
        int x=rs(rt),ps=pos[s];
        while(ls(x)) x=ls(x);
        swap(pos[s],pos[e[x].id]);
        swap(e[ps].id,e[x].id);
    }
    else
    {
        int x=ls(rt),ps=pos[s];
        while(rs(x)) x=rs(x);
        swap(pos[s],pos[e[x].id]);
        swap(e[ps].id,e[x].id);
    }
}
il void ask(int x)
{
    splay(pos[x],0);
    printf("%d\n",e[ls(rt)].sz);
}
il int qry(int s)
{
    int x=rt;
    while(1926)
    {
        if(e[ls(x)].sz+1==s) return e[x].id;
        else if(e[ls(x)].sz>=s) x=ls(x);
        else s-=e[ls(x)].sz+1,x=rs(x);
        //cout<<s<<' '<<x<<' '<<e[ls(x)].sz+1<<endl;
    }
}
int main()
{
	freopen("P2596.in","r",stdin);
	freopen("P2596.out","w",stdout);
    n=read(),m=read();
    rt=0;
    ls(0)=rs(0)=fa(rt)=e[rt].sz=e[rt].id=pos[0]=0;
    for(int i=1;i<=n;i++) add(read());//puts("qwq");
    char opt[10];
    for(int i=1;i<=m;i++)
    {
        scanf("%s",opt);
        switch(opt[0])
        {
            case 'T':tb(read(),0);break;
            case 'B':tb(read(),1);break;
            case 'I':ins(read(),read());break;
            case 'A':ask(read());break;
            case 'Q':printf("%d\n",qry(read()));break;
        }
    }
}
