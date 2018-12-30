#include<cstdio>
#include<cstring>
#include<algorithm>
#include <bits/stdc++.h>
using namespace std;
const int MAXN=8*1e4+5;
int inline swp(int &a,int &b)
{
	a^=b^=a^=b;
}
int inline readuint()
{
	int Num;
	char ch;
	while((ch=getchar())<'0'||ch>'9');
	Num=ch-'0';
	while((ch=getchar())>='0'&&ch<='9') Num=Num*10+ch-'0';
	return Num;
}
int inline readint()
{
	int Num=0,Flag=1;
	char ch;
	while((ch=getchar())<'0'||ch>'9') if(ch=='-') break;
	if(ch=='-') Flag=-1;
	else Num=ch-'0';
	while((ch=getchar())>='0'&&ch<='9') Num=Num*10+ch-'0';
	return Num*Flag;
}
void outint(int x)
{
	if(x>=10) outint(x/10);
	putchar(x%10+'0');
}
int n,m,ch[MAXN][2],fa[MAXN],cnt=0;
int num[MAXN],pos[MAXN],siz[MAXN],rt=0;
void inline pushup(int &x)
{
	siz[x]=siz[ch[x][0]]+siz[ch[x][1]]+1;
	//pos[num[ch[x][0]]]=ch[x][0],pos[num[ch[x][1]]]=ch[x][1];
}
void rot(int x,int p)
{
	int y=fa[x];
	fa[ch[x][!p]]=y,ch[y][p]=ch[x][!p];
	fa[x]=fa[y];
	if(fa[y]) ch[fa[y]][ch[fa[y]][1]==y]=x;
	fa[y]=x,ch[x][!p]=y;
	pushup(y),pushup(x);
}
void splay(int x,int T)
{
	while(fa[x]!=T)
	{
		if(fa[fa[x]]==T) rot(x,ch[fa[x]][1]==x);
		else
		{
			int y=fa[x],z=fa[y],p=ch[z][1]==y;
			if(ch[y][p]==x) rot(y,p),rot(x,p);
			else rot(x,!p),rot(x,p);
		}
	}
	pos[num[x]]=x;
	if(!T) rt=x;
}
void insert(int key)
{
	int x=rt;
	while(ch[rt][1]) x=ch[rt][1];
	fa[++cnt]=x,ch[x][1]=cnt,num[cnt]=key,pos[key]=cnt,siz[cnt]=1,ch[cnt][0]=ch[cnt][1]=0;
	splay(cnt,0);
}
void top_bottom(int s,int p)
{
	//cout<<pos[s]<<endl;
	splay(pos[s],0);
	//cout<<rt<<endl;
	if(!ch[rt][p]) return;
	if(!ch[rt][!p]) ch[rt][!p]=ch[rt][p],ch[rt][p]=0;
	else
	{
		int x=ch[rt][!p];
		//cout<<x<<endl;
		while(ch[x][p]) x=ch[x][p];
		fa[ch[rt][p]]=x,ch[x][p]=ch[rt][p],ch[rt][p]=0;
		splay(ch[x][p],0);
	}
}
void ist(int t,int s)
{
	splay(pos[s],0);
	if(!t) return;
	if(t==1)
	{
		int suc=ch[rt][1],ps=pos[s];
		while(ch[suc][0]) suc=ch[suc][0];
		swp(pos[s],pos[num[suc]]);
		swp(num[ps],num[suc]);
		//cout<<num[ps]<<' '<<num[suc]<<endl;
	}
	else
	{
		int pre=ch[rt][0],ps=pos[s];
		while(ch[pre][1]) pre=ch[pre][1];
		swp(pos[s],pos[num[pre]]);
		swp(num[ps],num[pre]);
		//cout<<num[ps]<<' '<<num[pre]<<endl;
	}
}
void ask(int s)
{
	splay(pos[s],0);
	outint(siz[ch[rt][0]]);
}
int qry(int s)
{
	int x=rt;
	while(pos)
	{
		if(siz[ch[x][0]]+1==s) return num[x];
		else if(siz[ch[x][0]]>=s) x=ch[x][0];
		else s-=siz[ch[x][0]]+1,x=ch[x][1];
		//cout<<s<<' '<<x<<' '<<siz[ch[x][0]]+1<<endl;
	}
}
int main()
{
	freopen("P2596.in","r",stdin);
	freopen("P2596.ans","w",stdout);
	ch[0][0]=ch[0][1]=siz[0]=fa[0]=num[0]=pos[0]=0;
	n=readuint(),m=readuint();
	for(int i=1; i<=n; i++) insert(readint());
	//cout<<"qwq "<<rt<<endl;
	for(int i=1; i<=m; i++)
	{
		char opt[10];
		scanf("%s",opt);
		switch(opt[0])
		{
			case 'T':
				top_bottom(readuint(),0);
				break;
			case 'B':
				top_bottom(readuint(),1);
				break;
			case 'I':
				ist(readint(),readuint());
				break;
			case 'A':
				ask(readuint()),putchar('\n');
				break;
			case 'Q':
				outint(qry(readuint())),putchar('\n');
				break;
			
		}
		//cout<<"qwq "<<rt<<endl;
		//for(int j=1;j<=n;j++) cout<<pos[j]<<' ';puts("");
	}
}
