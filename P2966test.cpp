#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N=255,INF=0x3f3f3f3f;
int n,m,q,u,v,w,s,t;
int rank[N],dist[N][N],d[N][N];
struct node
{
    int d;
    int id;
}nm[N];
bool cmp(node a,node b)
{
    if(a.d==b.d)
        return a.id<b.id;
    return a.d<b.d;
}
inline void get(int &a)//??
{
    char c=getchar();
    a=0;
    for(;c<'0'||c>'9';c=getchar());
    a=c-'0';
    for(c=getchar();c>='0'&&c<='9';c=getchar())
        a=a*10+c-'0';
}
int main()
{
	freopen("P2966.in","r",stdin);
    get(n);get(m);get(q);
    for(int i=1;i<=n;i++)
    {
        get(nm[i].d);
        nm[i].id=i;
    }
    sort(nm+1,nm+1+n,cmp);//?????
    for(int i=1;i<=n;i++)
        rank[nm[i].id]=i;//??????????,?????
    memset(d,0x3f,sizeof(d));
    for(int i=1;i<=n;i++)
        d[i][i]=0;
    for(int i=1;i<=m;i++)
    {
        get(u);get(v);get(w);
        d[rank[v]][rank[u]]=d[rank[u]][rank[v]]=min(d[rank[u]][rank[v]],w);
    }
    memset(dist,0x3f,sizeof(dist));
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
            {
                if(i==j)
                    continue;
                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
                dist[i][j]=min(dist[i][j],d[i][j]+max(nm[k].d,max(nm[i].d,nm[j].d)));
            }
    //while(q--)
    {
        get(s);get(t);
        printf("%d\n",dist[rank[s]][rank[t]]);
    }
    return 0;
}
