#include <cstdio>
#include <bits/stdc++.h>
namespace rqy             //?????????????????????,?????
{
	typedef long long LL;
	const int N = 3000500;
	int fa[N], son[N][2], cnt;
	LL l[N], r[N], siz[N]; //l, r????????,??????(????)
	struct Splay
	{
		int root;
		inline int newNode(LL ll, LL rr)      //ll, rr????????????
		{
			++cnt;
			fa[cnt] = son[cnt][0] = son[cnt][1] = 0;
			siz[cnt] = (r[cnt] = rr) - (l[cnt] = ll);
			return cnt;
		}
		inline void init(LL ll, LL rr)        //????,??????[ll,rr)?????
		{
			root = newNode(ll, rr);
		}
		inline void upd(int x)
		{
			siz[x] = siz[son[x][0]] + siz[son[x][1]] + r[x] - l[x];
		}
		inline int dir(int x)
		{
			return son[fa[x]][1] == x;    //x?fa[x]?????
		}
		inline void rotate(int x)     //??????
		{
			int d = dir(x), f = fa[x];
			fa[x] = fa[f];
			if (f == root) root = x;
			else son[fa[f]][dir(f)] = x;
			if (son[f][d] = son[x][d ^ 1]) fa[son[f][d]] = f;
			fa[son[x][d ^ 1] = f] = x;
			upd(f);
			upd(x);
		}
		void splay(int x)     //??
		{
			for (; fa[x]; rotate(x))
				if (fa[fa[x]]) rotate(dir(x) == dir(fa[x]) ? fa[x] : x);
		}
		int splitNode(int x, LL k)    //???x??,???x?????k????x???,
		{
			k += l[x];                  //?????????(???????)
			int y = newNode(k, r[x]);
			r[x] = k;
			if (son[x][1] == 0)
			{
				fa[son[x][1] = y] = x;
			}
			else
			{
				int t = son[x][1];
				while (son[t][0]) t = son[t][0];
				fa[son[t][0] = y] = t;
				while (t != x) upd(t), t = fa[t];
			}
			splay(y);
			return y;
		}
		LL popKth(LL k)               //???k??
		{
			int o = root;
			while (1)
			{
				if (siz[son[o][0]] >= k)
				{
					o = son[o][0];
				}
				else
				{
					k -= siz[son[o][0]];
					if (k <= r[o] - l[o])
					{
						if (k != r[o] - l[o]) splitNode(o, k);
						if (k != 1) o = splitNode(o, k - 1);
						break;
					}
					else
					{
						k -= r[o] - l[o];
						o = son[o][1];
					}
				}
			}
			splay(o);
			fa[son[o][0]] = fa[son[o][1]] = 0;
			if (!son[o][0])             //splay??
			{
				root = son[o][1];
			}
			else
			{
				int t = son[o][0];
				std::cout<<t<<std::endl;
				while (son[t][1]) t = son[t][1],std::cout<<t<<std::endl;
				splay(t);
				upd(root = fa[son[t][1] = son[o][1]] = t);
			}
			return l[o];
		}
		void pushBack(LL k)           //?????k
		{
			int y = newNode(k, k + 1);
			if (!root)
			{
				root = y;
			}
			else
			{
				int o = root;
				while (son[o][1]) o = son[o][1];
				splay(o);
				upd(fa[son[o][1] = y] = o);
			}
		}
	};
	Splay s[N];
	void main()
	{
		cnt = 0;
		int n, m, q;
		scanf("%d%d%d", &n, &m, &q);
		for (LL i = 1; i <= n; ++i) s[i].init((i - 1) * m + 1, i * m);
		s[0].init(m, m + 1);
		for (LL i = 2; i <= n; ++i) s[0].pushBack(i * m);
		int x, y;
		LL p;
		while (q--)
		{
			scanf("%d%d", &x, &y);
			s[x].pushBack(s[0].popKth(x));
			printf("%lld\n", p = s[x].popKth(y));
			s[0].pushBack(p);
		}
	}
};
int main()
{
	rqy::main();
	return 0;
}
