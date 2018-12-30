#include <bits/stdc++.h>
#define il inline
#define Max 2005
#define nx x+nt[dir][0]
#define ny y+nt[dir][1]
// L 1 R 2 down 3 up 4
using namespace std;
int e[Max][Max],n,m;
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
int nt[5][2];
int main()
{
	n=read(),m=read()+1;
	for(int i=1;i<=n;i++)
	{
		int x1=read()+1,y1=read()+1,x2=read()+1,y2=read()+1;
		int dir;
		if(x1==x2) dir=4;
		if(y1==y2) dir=2;
		if(x1>x2) swap(x1,x2),dir=1;
		if(y1>y2) swap(y1,y2),dir=3;
		for(int i=x1;i<=x2;i++)
			for(int j=y1;j<=y2;j++)
				e[i][j]=dir;
	}
	/*
	for(int i=1;i<=m;i++,puts(""))
		for(int j=1;j<=m;j++)
			printf("%d ",e[i][j]);
	*/
	nt[1][0]=nt[3][1]=-1;
	nt[2][0]=nt[4][1]=1;
	int q=read(),x,y,len,dir;
	char opt;
	while(q--)
	{
		x=read()+1,y=read()+1;
		opt='!';
		while(opt!='L'&&opt!='R'&&opt!='U'&&opt!='D') opt=getchar();
		len=read();
		if(opt=='L') dir=1;
		if(opt=='R') dir=2;
		if(opt=='D') dir=3;
		if(opt=='U') dir=4;
		for(int i=1;i<=len;i++)
		{
			if(e[x][y]) dir=e[x][y];
			//printf("x:%d y:%d nx:%d ny:%d dir:%d\n",x,y,nx,ny,dir);
			if(nx<1||nx>m||ny<1||ny>m) break;
			x=nx,y=ny;
		}
		printf("%d %d\n",x-1,y-1);
	}
}
