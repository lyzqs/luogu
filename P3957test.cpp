#include<cmath>
#include<cstdio>
#include<ctype.h>
#include<cstring>
#include<iostream>
#include<algorithm>
#define INF (0x7f7f7f7f)
#define Max(a, b) ((a) > (b) ? (a) : (b))
#define Min(a, b) ((a) < (b) ? (a) : (b))
#define N (500005)
typedef long long ll;
using namespace std;
template <class T>
inline void read(T &x)
{
	int f = 0, ch = 0;
	x = 0;
	for(; !isdigit(ch); ch = getchar()) if(ch == '-') f = 1;
	for(; isdigit(ch); ch = getchar()) x = x * 10 + ch - '0';
	if(f) x = -x;
}
int q[N], h, t, n, k;
ll dis[N], val[N], f[N], d;
inline void Push(int x)
{
	while(f[q[t]] <= f[x] && t >= h) t--;
	q[++t] = x;
}
inline bool check(ll g)
{
	int p = 0;
	h = 1, t = 0, q[h] = 0;
	for(int i = 1; i <= n; i++) f[i] = -INF;
	for(int i = 1; i <= n; i++)
	{
		while(dis[i] - dis[p] >= Max(d - g, 1) && p < i) Push(p++);
		while(dis[i] - dis[q[h]] > d + g && h <= t) h++;
		if(h > t || f[q[h]] == -INF) continue;
		else f[i] = f[q[h]] + val[i];
		printf("%d %d %d\n",g,i,f[i]);
		if(f[i] >= k) return 1;
	}
	return 0;
}
int main()
{
	read(n), read(d), read(k);
	for(int i = 1; i <= n; i++) read(dis[i]), read(val[i]);
	ll l = 0, r = (ll) 1e9, ans = -1;
	while(l <= r)
	{
		ll mid = l + r >> 1;
		if(check(mid)) ans = mid, r = mid - 1;
		else l = mid + 1;
	}
	cout << ans;
	return 0;
}
