#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int inf=1<<30;
int dep[10101],head[10101];
int top=1;
int maxflow=0;
int n,m,s,t;
struct Node{
    int v;
    int val;
    int next;
}node[200100];
inline void addedge(int u,int v,int val){
    node[++top].v=v;
    node[top].val=val;
    node[top].next=head[u];
    head[u]=top;
}
inline int Read(){
    int x=0;char c=getchar();
    while(c>'9'||c<'0')c=getchar();
    while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
    return x;
}
bool bfs(){
    memset(dep,0x3f,sizeof(dep));
    dep[s]=0;
    queue<int>q;
    q.push(s);
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int i=head[u];i;i=node[i].next){
            int d=node[i].v;
            if(dep[d]>dep[u]+1&&node[i].val){
                dep[d]=dep[u]+1;
                q.push(d);
            }
        }
    }
    if(dep[t]!=0x3f3f3f3f)return 1;
    return 0;
}//????????? 
inline int min(int x,int y){
    return x<y?x:y;
}
int dfs(int u,int low){
    int rlow=0;
    if(u==t)return low;
    for(int i=head[u];i;i=node[i].next){
        int d=node[i].v;
        if(node[i].val&&dep[d]==dep[u]+1){
        if(rlow=dfs(d,min(low,node[i].val))){
            node[i].val-=rlow;
            node[i^1].val+=rlow;
            return rlow;
        }   
        }
    }
    return 0;
}//????? 
int Dinic(){
    int lowflow;
    while(bfs()){
        while(lowflow=dfs(s,inf))maxflow+=lowflow,printf("%d\n",lowflow);
    }
    return maxflow;
}//Dinic????? 
int main(){
    n=Read(),m=Read(),s=Read(),t=Read();
    register int i;
    int u,v,val;
    for(i=1;i<=m;i++)u=Read(),v=Read(),val=Read(),addedge(u,v,val),addedge(v,u,0);
    printf("%d",Dinic());
    return 0;
}
