#include <bits/stdc++.h>

using namespace std;
#define LL  long long
#define pii  pair<int, int>

const int N = 1e5+10;
const int INF = 0x3f3f3f3f;


vector<pii> edge[N];

void add(int u, int v, int l)
{
	edge[u].push_back(pii(v, l));
	edge[v].push_back(pii(u, l));
}

bool vis[N];
int sz[N];

void getsz(int cur, int fa)
{
	sz[cur] = 1;
	for (pii e : edge[cur])
	{
		int v = e.first;
		if (v == fa || vis[v]) continue;
		getsz(v, cur);
		sz[cur] += sz[v];
	}
}

int centroid(int cur, int fa, int n)
{
	int ret = cur;
	for (pii e : edge[cur])
	{
		int v = e.first;
		if (v == fa || vis[v]) continue;
		int t = centroid(v, cur, n);
		if (sz[v] > n/2) return t;
	}
	return ret;
}

int u[N], v[N], dep[N], sub[N];

void dfs(int cur, int fa, int s, int d)
{
	dep[cur] = d;
	sub[cur] = s;
	for (pii e : edge[cur])
	{
		int v = e.first;
		if (v == fa) continue;
		dfs(v, cur, s, d+e.second);
	}
}

void calc(int root)
{
	dep[root] = sub[root] = 0;
	for (pii e : edge[root])
	{
		int v = e.first;
		dfs(v, root, v, e.second);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n-1; ++i)
	{
		int x, y, z;
		cin >> x >> y >> z;
		add(x, y, z);
	}
	for (int i = 0; i < m; ++i)
	{
		cin >> u[i] >> v[i];
	}
	int ans = INF, s = 1;
	bool ok = false;
	while (!ok)
	{
		getsz(s, -1);
		int root = centroid(s, -1, sz[s]);
		calc(root);
		vis[root] = true;
		int mx = 0;
		for (int i = 0; i < m; ++i)
		{
			mx = max(mx, dep[u[i]] + dep[v[i]]);
		}
		ans = min(ans, mx);
		s = 0;
		for (int i = 0; i < m; ++i)
		{
			if (mx == dep[u[i]] + dep[v[i]])
			{
				if (sub[u[i]] == sub[v[i]] && sub[u[i]] != 0)
				{
					if (s == 0) s = sub[u[i]], ok = vis[s];
					else if (s != sub[u[i]]) ok = true;
				}
				else
				{
					ok = true;
				}
			}
		}
	}
	cout << ans << endl;
}
