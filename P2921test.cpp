#include<bits/stdc++.h>
using namespace std;
const int Maxn=100005;
int next[Maxn];
int ans[Maxn];
int head[Maxn],cnt;
struct road
{
    int to,next;
}e[Maxn*2];
void add(int a,int b)
{
    cnt++;
    e[cnt].to=b;
    e[cnt].next=head[a];
    head[a]=cnt;
}
int sum,color[Maxn],low[Maxn],ins[Maxn],tim[Maxn],sta[Maxn],top=1,col;
int Lemon[Maxn];
void Tarjan(int x)
{
    sum++;
    tim[x]=low[x]=sum;
    sta[top]=x;
    top++;
    ins[x]=1;
    for(int i=head[x];i!=0;i=e[i].next)
    {
        if(ins[e[i].to]==0)
        {
            Tarjan(e[i].to);
            low[x]=min(low[x],low[e[i].to]);
        }
        else if(ins[e[i].to]==1)
                low[x]=min(low[x],tim[e[i].to]);
    }
    if(tim[x]==low[x])
    {
        col++;
        do
        {
            top--;
            color[sta[top]]=col;
            ins[sta[top]]=-1;
        }while(sta[top]!=x);
    }
    return ;
}
void search(int root,int x,int step)
{
    if(ans[x]!=0) {
                    ans[root]=ans[x]+step;
                    return ;
                  }
    else search(root,next[x],step+1);
}
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&next[i]);
        add(i,next[i]);
        if(next[i]==i) ans[i]=1;//??????1????
    }
    for(int i=1;i<=n;i++)
        if(ins[i]==0) Tarjan(i);
    for(int i=1;i<=n;i++)
        Lemon[color[i]]++;//??????
    for(int i=1;i<=n;i++)
        if(Lemon[color[i]]!=1) ans[i]=Lemon[color[i]];//???????
    for(int i=1;i<=n;i++)
        if(ans[i]==0) search(i,next[i],1);//????????
    for(int i=1;i<=n;i++)
        printf("%d\n",ans[i]);
    return 0;
}
