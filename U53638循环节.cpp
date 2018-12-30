#include <iostream>
#include <string.h>
#include <algorithm>
#include <stdio.h>
#include <math.h>
 
using namespace std;
typedef long long LL;
const int N = 2;
const LL MOD = 1000000007;
 
LL fac[2][505];
int cnt,ct;
 
LL pri[6] = {2, 3, 7, 109, 167, 500000003};
LL num[6] = {4, 2, 1, 2, 1, 1};
 
struct Matrix
{
    LL m[N][N];
} ;
 
Matrix A;
Matrix I = {1, 0, 0, 1};
 
Matrix multi(Matrix a,Matrix b)
{
    Matrix c;
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            c.m[i][j]  =0;
            for(int k=0; k<N; k++)
            {
                c.m[i][j] += a.m[i][k] * b.m[k][j];
                c.m[i][j] %= MOD;
            }
        }
    }
    return c;
}
 
Matrix power(Matrix A,LL n)
{
    Matrix ans = I, p = A;
    while(n)
    {
        if(n & 1)
        {
            ans = multi(ans,p);
            n--;
        }
        n >>= 1;
        p = multi(p,p);
    }
    return ans;
}
 
LL quick_mod(LL a,LL b)
{
    LL ans = 1;
    a %= MOD;
    while(b)
    {
        if(b & 1)
        {
            ans = ans * a % MOD;
            b--;
        }
        b >>= 1;
        a = a * a % MOD;
    }
    return ans;
}
 
LL Legendre(LL a,LL p)
{
    LL t = quick_mod(a,(p-1)>>1);
    if(t == 1) return 1;
    return -1;
}
 
void dfs(int dept,LL product = 1)
{
    if(dept == cnt)
    {
        fac[1][ct++] = product;
        return;
    }
    for(int i=0; i<=num[dept]; i++)
    {
        dfs(dept+1,product);
        product *= pri[dept];
    }
}
 
bool OK(Matrix A,LL n)
{
    Matrix ans = power(A,n);
    return ans.m[0][0] == 1 && ans.m[0][1] == 0 &&
           ans.m[1][0] == 0 && ans.m[1][1] == 1;
}
 
int main()
{
    fac[0][0] = 1;
    fac[0][1] = 2;
    fac[0][2] = 500000003;
    fac[0][3] = 1000000006;
    LL a,b,c,d;
    while(cin>>a>>b>>c>>d)
    {
        LL t = a * a + 4 * b;
        A.m[0][0] = a;
        A.m[0][1] = b;
        A.m[1][0] = 1;
        A.m[1][1] = 0;
        if(Legendre(t,MOD) == 1)
        {
            for(int i=0; i<4; i++)
            {
                if(OK(A,fac[0][i]))
                {
                    cout<<fac[0][i]<<endl;
                    break;
                }
            }
        }
        else
        {
            ct = 0;
            cnt = 6;
            dfs(0,1);
            sort(fac[1],fac[1]+ct);
            for(int i=0;i<ct;i++)
            {
                if(OK(A,fac[1][i]))
                {
                    cout<<fac[1][i]<<endl;
                    break;
                }
            }
        }
    }
    return 0;
}

