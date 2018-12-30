#include <bits/stdc++.h>
#define il inline
#define Max 500005
//#define getchar() (tt==ss&&(tt=(ss=In)+fread(In,1,Max,stdin),tt==ss)?EOF:*ss++)
#define ll long long
#define rg register
#define ls(x) x<<1
#define rs(x) x<<1|1
using namespace std;
char In[Max],*ss=In,*tt=In;
il ll read()
{
    char c=getchar();
    ll x=0;
    while(c>'9'||c<'0') c=getchar();
    while(c>='0'&&c<='9')
    {
        x=x*10+c-'0';
        c=getchar();
    }
    return x;
}
int t[Max<<2],tg[Max<<2],lx[Max],rx[Max],ls[Max<<2],rs[Max<<2],n,m,tot,cnt=0,rt=0,f[Max];
ll ans=0;
il void print(ll x)
{
    //if(x/10>0) print(x/10);
    //printf("%d",(int)(x%10));
    cout<<x;
}
il void add(int &x,ll l,ll r,ll ql,ll qr)
{
    if(!x) x=++cnt;
    if(ql<=l&&r<=qr)
    {
		t[x]=1;
		return;
    }
    ll mid=(l+r)>>1;
    if(ql<mid) add(ls[x],l,mid,ql,qr);
    if(qr>mid) add(rs[x],mid,r,ql,qr);
    return;
}
struct node
{
	ll l,r,mid,id;
}q[Max<<2];
il bool qry(int x,ll l,ll r)
{
	bool res=0;
	if(t[x]) res=1;
	ll mid=(l+r)>>1;
	if(ls[x]) 
	{
		if(qry(ls[x],l,mid))
		{
			//cout<<"!ls "<<l<<' '<<r<<endl;
			ans-=(l+1)*(r-mid);
			q[++tot].l=l,q[tot].r=r,q[tot].id=1;q[tot].mid=mid;
			//print(ans);cout<<endl;
		}
	}
	if(rs[x])
	{
		if(qry(rs[x],mid,r))
		{
			//cout<<"!rs "<<l<<' '<<r<<endl;
			ans-=(n-r+1)*(mid-l);
			q[++tot].l=l,q[tot].r=r,q[tot].id=2;q[tot].mid=mid;
			//cout<<"del "<<r<<' '<<n-r+1<<endl;
			//print(ans);cout<<endl;
		}
	}
	return res;
}
il void calc2(int x,ll l,ll r)
{
	ll mid=(l+r)>>1;
	if(rs[x]) t[rs[x]]=0;
	if(ls[x]||rs[x]) calc2(ls[x],l,mid);
}
il void calc1(int x,ll l,ll r)
{
	ll mid=(l+r)>>1;
	if(ls[x]) t[ls[x]]=0;
	if(rs[x]||ls[x]) calc1(rs[x],mid,r);
}
il bool pp(int x,ll l,ll r)
{
	bool res=0;
	if(t[x]) res=1;
	ll mid=(l+r)>>1;
	if(ls[x]) 
	{
		if(pp(ls[x],l,mid))
		{
			//cout<<"!ls "<<l<<' '<<r<<endl;
			if(rs[x]) calc1(rs[x],mid,r);
		}
	}
	if(rs[x])
	{
		if(pp(rs[x],mid,r))
		{
			//cout<<"del "<<r<<' '<<n-r+1<<endl;
			if(ls[x]) calc2(ls[x],l,mid);
		}
	}
	return res;
}
il bool cmp(node a,node b)
{
	return a.l<b.l;
}
int main()
{
    //print(0);
    n=read();m=read();
    //build(1,0,n);
    ans=n*(n+1)/2;
    print(ans);cout<<endl;
    while(m--)
    {
        ll l=read(),r=read();
        add(rt,0,n,l-1,r);
    }
    //if(ans==123) puts("yes");
    pp(rt,0,n);
    qry(rt,0,n);
    sort(q+1,q+1+tot,cmp);
    ans=n*(n+1)/2;
    for(int i=1;i<=tot;i++)
    {
    	if(q[i].id==1)
    	{
    		ans-=(q[i].l+1-(tot-i+1))*(q[i].r-q[i].mid);
		}
		else ans-=(n-q[i].r+1-i)*(q[i].mid-q[i].l);
	}
    print(ans);
}
