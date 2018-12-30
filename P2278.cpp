#include <bits/stdc++.h>
#define il inline
#define Max 500005
using namespace std;
struct node
{
	int s,t,num,val;
}e[Max];
bool operator < (node a,node b)
{
	return a.val<b.val||(a.val==b.val&&a.num>b.num);
}
int n,rst,cnt=1,s,t,last;
priority_queue<node> q;
int main()
{
	while(scanf("%d%d%d%d",&e[n+1].num,&e[n+1].s,&e[n+1].t,&e[n+1].val)!=EOF) ++n;
	rst=n;e[n+1].s=1e9;
	while(rst)
	{
		if (!s) q.push(e[cnt]),t=e[cnt].s,s++,cnt++;
		node qwq=q.top();q.pop();s--;
		last=t;
		t=min(last+qwq.t,e[cnt].s);
		if(t==last+qwq.t) printf("%d %d\n",qwq.num,t),rst--;
		else qwq.t-=t-last,q.push(qwq),s++;
		if(t==e[cnt].s) q.push(e[cnt]),s++,cnt++;
	}
}
