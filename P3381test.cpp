#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<queue>
using namespace std;
int maxflow;//???
int cost;//???? 
int top=1,head[5010];
const int inf=1<<30;
int dist[5010];
int inque[5010];
int n,m,s,t;
struct Node{
    int v;
    int w;//?????????
    int next;
    int val;//?????? 
}node[101100];
struct P{
    int fa;//????????? 
    int adge;//???????????? 
}pre[5010];
inline int Read(){
    int x=0;
    char c=getchar();
    while(c>'9'||c<'0')c=getchar();
    while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
    return x;
}
inline void addedge(int u,int v,int val,int w){
    node[++top].v=v;
    node[top].val=val;
    node[top].w=w;
    node[top].next=head[u];
    head[u]=top;
}
bool spfa(){
    memset(pre,0,sizeof(pre));
    memset(dist,0x3f,sizeof(dist));
    memset(inque,0,sizeof(inque));
    queue<int>q;
    q.push(s);
    inque[s]=1;
    dist[s]=0;
    while(!q.empty()){
        int u=q.front();
        inque[u]=0;
        q.pop();
        register int i,d,w;
        for(i=head[u];i;i=node[i].next){
            d=node[i].v;
            w=node[i].w;
            if(node[i].val>0&&dist[d]>dist[u]+w){
                dist[d]=dist[u]+w;
                pre[d].fa=u;
                pre[d].adge=i;
                if(inque[d]==0){
                    q.push(d);
                    inque[d]=1;
                }
            }
        }
    }
    return dist[t]!=0x3f3f3f3f;
}//??????????
int EK(){//????????EK??
    maxflow=0;
    cost=0;
    int mi;
    register int i;
    while(spfa()){
        mi=inf;
        for(i=t;i!=s;i=pre[i].fa)mi=min(mi,node[pre[i].adge].val);
        for(i=t;i!=s;i=pre[i].fa){
            node[pre[i].adge].val-=mi;
            node[pre[i].adge^1].val+=mi;
        }
        maxflow+=mi;
        cost+=mi*dist[t];
    }
    return maxflow;
}
int main(){
    n=Read(),m=Read(),s=Read(),t=Read();
    register int i;
    int u,v,val,w;
    for(i=1;i<=m;i++){
        u=Read(),v=Read(),val=Read(),w=Read();
        addedge(u,v,val,w);
        addedge(v,u,0,-w);
    }
    printf("%d ",EK());
    printf("%d",cost);
    return 0;
}
