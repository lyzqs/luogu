#include <bits/stdc++.h>
#define il inline
#define Max 105
using namespace std;
il int read()
{
	char c=getchar();
	int x=0;
	while(c>'9'||c<'0') c=getchar();
	while(c>='0'&&c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return x;
}
int n,m,q,r,k,tot=0,pos;
int s[Max][Max],cnt[Max];
char in[Max];
il void print(int st,int x,int y)
{
	int res=0;
	for(int i=st;i<=m;i++)
	{
		if(s[x][i])
		{
			printf("%d%c ",x,'A'+i-1);
			s[x][i]=0;
			res++;
		}
		if(res==y) break;
	}
	cnt[x]-=y;
	tot-=y;
	printf("\n");
}
il int check(int x)
{
	int res=0,res2=0;
	pos=1;
	for(int i=1;i<=m;i++)
	{
		if(s[x][i]) res++;
		else res=0,pos=i+1;
		if(res>res2) res2=res;
		if(res2==k) break;
	}
	return res2;
}
int main()
{
	n=read(),m=read();
	for(int i=1;i<=n;i++)
	{
		scanf("%s",in+1);
		for(int j=1;j<=m;j++)
		{
			if(in[j]=='-') s[i][j]=1,tot++,cnt[i]++;
		}
	}
	//for(int i=1;i<=n;i++,puts(""))
	//	for(int j=1;j<=m;j++)
	//		cout<<s[i][j];
	q=read();
	for(int i=1;i<=q;i++)
	{
		r=read(),k=read();
		if(r>n) 
		{
			printf("Theater only contains %d rows\n",n);
			continue;
		}
		if(tot<k)
		{
			printf("Sold out\n");
			continue;
		}
		if(cnt[r]>=k)
		{
			if(check(r)==k)
				print(pos,r,k);
			else print(1,r,k);
			continue;
		}
		int flag=0;
		for(int i=1;i<=n;i++)
		{
			if(cnt[i]>=k&&check(i)==k)
			{
				print(pos,i,k);
				flag=1;
				break;
			}
		}
		if(!flag) printf("Please contact our staff to buy tickets\n");
	}
}
