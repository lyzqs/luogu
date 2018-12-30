#include <bits/stdc++.h>
#define il inline
#define Max 2005
#define dg cout<<"qwq\n";
#define ll long long
using namespace std;
const int MAXN = 50;
__int128 f[Max][Max];
void print(__int128 x)
{
    if(x < 0)
    {
        x = -x;
        putchar('-');
    }
     if(x > 9) print(x/10);
    putchar(x%10 + '0');
}
int main()
{
    int n,m;
    cin>>n>>m;
    n=n+m;
    m=min(m,n-m);
    for(int i=1;i<=n;i++) f[i][i]=f[i][0]=1;
    for(int i=1;i<=n;i++)
    	for(int j=1;j<min(i,m+1);j++)
    		f[i][j]=f[i-1][j-1]+f[i-1][j];
	print(f[n][m]);
}
