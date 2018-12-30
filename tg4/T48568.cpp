#include <bits/stdc++.h>
#define reg register
#define fok (ch!=EOF)
#define sep (ch==' '||ch=='\n'||ch=='\t')
#define dsep !isdigit(ch)
#define neq(a,b) ((a)-(b)>1e-6)
#define il inline
#define ll long long
#define Max 10000005
using namespace std;
namespace io {
    const int SIZE = (1 << 21) + 1;
    char ibuf[SIZE], *iS, *iT, obuf[SIZE], *oS = obuf, *oT = oS + SIZE - 1, c, qu[55]; int f, qr;
    // getchar
    #define gc() (iS == iT ? (iT = (iS = ibuf) + fread (ibuf, 1, SIZE, stdin), (iS == iT ? EOF : *iS ++)) : *iS ++)
    // print the remaining part
    inline void flush () {
        fwrite (obuf, 1, oS - obuf, stdout);
        oS = obuf;
    }
    // putchar
    inline void putc (char x) {
        *oS ++ = x;
        if (oS == oT) flush ();
    }
    // input a signed integer
    template <class I>
    inline void gi (I &x) {
        for (f = 1, c = gc(); c < '0' || c > '9'; c = gc()) if (c == '-') f = -1;
        for (x = 0; c <= '9' && c >= '0'; c = gc()) x = x * 10 + (c & 15); x *= f;
    }
    // print a signed integer
    template <class I>
    inline void print (I x) {
        if (!x) putc ('0'); if (x < 0) putc ('-'), x = -x;
        while (x) qu[++ qr] = x % 10 + '0',  x /= 10;
        while (qr) putc (qu[qr --]);
    }
    //no need to call flush at the end manually!
    struct Flusher_ {~Flusher_(){flush();}}io_flusher_;
}
using io :: gi;
using io :: putc;
using io :: print;
int p[Max];
bool vis[Max];
ll t[Max],e[Max],T,n,ans[Max];
int main()
{
	//freopen("T48568.in","r",stdin);
	ll cnt=0;
    for(int i=2;i<=10000000;++i)
    {
        if(!vis[i])
        {
            p[++cnt]=i;
            t[i]=i+1;
            e[i]=1;
        }
        for(int j=1;j<=cnt;++j)
        {
            if(p[j]*i>10000000) break;
            vis[p[j]*i]=true;
            if(i%p[j]==0)
            {
                t[i*p[j]]=t[i]*p[j]+e[i];
                e[i*p[j]]=e[i];
                break;
            } 
            t[i*p[j]]=t[i]*(p[j]+1);
            e[i*p[j]]=t[i];
        }
    }
    ans[1]=0;
    for(int i=2;i<=10000000;i++)
    {
    	ans[i]=ans[i-1]+2*(i-1)+1-t[i];
	}
	gi(T);
	//T=20;
	for(int i=1;i<=T;i++)
	{
		//n=i;
		//io<<ans[n];
		//if(ans[n]==0)
		//{
		//	putc('1');
		//	putc('\n');
		//	continue;
		//}
		gi(n);
		print(ans[n]);
		putc('\n');
	}
}
