#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
# define ls now<<1
# define rs now<<1|1
const int M = 100005 ;
const int inf = 2100000000 ;
using namespace std;
inline int read(){
    char c=getchar(); int x=0,w=1;
    while(c>'9'||c<'0'){if(c=='-') w=-1 ;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0'; c=getchar();}
    return x*w;
}
int n,m;
struct E{
    int nex,to;
}edge[M<<1];
int hea[M],num;
inline void add_edge(int from,int to){
    edge[++num].nex=hea[from];
    edge[num].to=to;
    hea[from]=num;
}
int fa[M],dep[M],size[M],son[M];
int val[M],root;
void dfs1(int u,int father,int deep){
    dep[u]=deep; 
    fa[u]=father;
    size[u]=1 ;
    int Maxson=-1;
    for(int i=hea[u];i;i=edge[i].nex){
        int v=edge[i].to;
        if(v==father) continue ;
        dfs1(v,u,deep+1);
        size[u]+=size[v];
        if(size[v]>Maxson){
            Maxson=size[v];
            son[u]=v;

        }
    }
}
int id[M],cnt,top[M],p[M];
void dfs2(int u,int topf){
    top[u]=topf; 
    id[u]=++cnt;
    p[cnt]=val[u];
    if(!son[u]) return ;
    dfs2(son[u],topf);
    for(int i=hea[u];i;i=edge[i].nex){
        int v=edge[i].to;
        if(!id[v])
          dfs2(v,v);
    }
}
inline int LCA(int x,int y){
    while(top[x]!=top[y]){
        if(dep[top[x]]<dep[top[y]]) swap(x,y);
        x=fa[top[x]];
    }
    return dep[x]<=dep[y]?x:y;
}
int tmin[M<<2],tag[M<<2];
inline void pushup(int now){
    tmin[now]=min(tmin[ls],tmin[rs]);
}
inline void pushdown(int now){
    if(tag[now]!=-1){
        tmin[ls]=tmin[rs]=tag[now];
        tag[ls]=tag[rs]=tag[now];
        tag[now]=-1;
    }
}
void Build(int l,int r,int now){
    tag[now]=-1;
    if(l==r){
        tmin[now]=p[l];
        return ;
    }
    int mid=(l+r)>>1;
    Build(l,mid,ls);
    Build(mid+1,r,rs);
    pushup(now);
}
void change(int L,int R,int C,int l,int r,int now){
    if(l==L&&r==R){
        tmin[now]=C;
        tag[now]=C;
        return ;
    }
    int mid=(l+r)>>1;
    pushdown(now);
    if(mid>=R) change(L,R,C,l,mid,ls);
    else if(mid<L) change(L,R,C,mid+1,r,rs);
    else{
        change(L,mid,C,l,mid,ls);
        change(mid+1,R,C,mid+1,r,rs);
    }
    pushup(now);
}
void change1(int x,int y,int C){
    while(top[x]!=top[y]){
        if(dep[top[x]]<dep[top[y]]) swap(x,y);
        change(id[top[x]],id[x],C,1,n,1);
        x=fa[top[x]];
    }
    if(dep[x]>dep[y]) swap(x,y);
    change(id[x],id[y],C,1,n,1);
}
int query(int L,int R,int l,int r,int now){
    if(l>R||r<L) return inf;
    if(l>=L&&r<=R) return tmin[now];
    int mid=(l+r)>>1;
    pushdown(now);
    int Ans=query(L,R,l,mid,ls);
    Ans=min(Ans,query(L,R,mid+1,r,rs));
    return Ans;
}
int main(){
    n=read(); m=read();
    int u,v;
    for(int i=1;i<n;i++){
        u=read(); v=read();
        add_edge(u,v);
        add_edge(v,u);
    }
    for(int i=1;i<=n;i++) val[i]=read();
    root=read();
    dfs1(1,1,1);
    dfs2(1,1);
    Build(1,n,1);
    while(m--){
        int opt=read();
        if(opt==1){
            int x=read();
            root=x;
        }
        else if(opt==2){
            int u=read(),v=read(),w=read();
            change1(u,v,w);
        }
        else{
            int x=read();
            if(x==root) printf("%d\n",tmin[1]);
            else{
                int lca=LCA(x,root);
                if(lca==x){
                    int y=0;
                    for(int i=hea[x];i;i=edge[i].nex){
                        int v=edge[i].to;
                        if(id[v]<=id[root]&&id[v]+size[v]-1>=id[root]){
                            y=v;
                            break;
                        }
                    }
                    printf("%d\n",min(query(1,id[y]-1,1,n,1),query(id[y]+size[y],n,1,n,1)));
                }
                else printf("%d\n",query(id[x],id[x]+size[x]-1,1,n,1));
            }
        }
    }
    return 0;
}
