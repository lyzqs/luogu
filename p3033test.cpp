#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
int n, lh, ll, cnt, sum;
int next[62501], to[62501], head[251], g[251];
bool vis[251];
struct node
{
    int pos, minn, maxx;
}h[10001], l[10001];
void add(int x, int y)
{
    to[cnt] = y;
    next[cnt] = head[x];
    head[x] = cnt++;
}
bool check(int i, int j)
{
    if(h[i].pos < l[j].minn || h[i].pos > l[j].maxx) return 0;
    if(l[j].pos < h[i].minn || l[j].pos > h[i].maxx) return 0;
    return 1;
}
bool find(int u)
{
    int i, v;
    for(i = head[u]; i != -1; i = next[i])
    {
        v = to[i];
        if(!vis[v])
        {
            vis[v] = 1;
            if(!g[v] || find(g[v]))
            {
                g[v] = u;
                return 1;
            }
        }
    }
    return 0;
}
int main()
{
	freopen("p3033.in","r",stdin);
    int i, j, x1, y1, x2, y2;
    scanf("%d", &n);
    memset(head, -1, sizeof(head));
    for(i = 1; i <= n; i++)
    {
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        if(x1 == x2)
        {
            ++lh;
            h[lh].pos = x1;
            h[lh].minn = min(y1, y2);
            h[lh].maxx = max(y1, y2);
        }
        else if(y1 == y2)
        {
            ++ll;
            l[ll].pos = y1;
            l[ll].minn = min(x1, x2);
            l[ll].maxx = max(x1, x2);
        }
    }
    for(i = 1; i <= lh; i++)
     for(j = 1; j <= ll; j++)
      if(check(i, j))
       add(i, j);
    for(i = 1; i <= lh; i++)
    {
        memset(vis, 0, sizeof(vis));
        if(find(i)) sum++;
    }
    printf("%d", n - sum);
    return 0;
}
