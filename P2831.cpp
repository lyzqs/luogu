#include <bits/stdc++.h>
#define il inline
#define Max 20
#define eps 1e-8
#define ld double
#define ll long long
using namespace std;
int n,m,T,l[Max][Max],low[1<<Max],f[1<<Max];
double x[Max],y[Max];
il bool dy(ld a,ld b)
{
	return fabs(a-b)<eps;
}
il void solve(double &a,double &b,int i,int j)
{
	ld k1=x[i]*x[i],k2=x[i],k3=x[j]*x[j],k4=x[j],y1=y[i],y2=y[j];
	k2=k2*k3/k1;
	y1=y1*k3/k1;
	b=(y2-y1)/(k4-k2);
	a=y2-(k4*b);
	a/=k3;
}
int main()
{
	for(int i=0;i<=(1<<18);i++)
	{
		low[i]=1;
		for(int j=1;j<=18&&((1<<(j-1))&i);j++)
			low[i]=j+1;
	}
	scanf("%d",&T);
	while(T--)
	{
		memset(l,0,sizeof(l));
		memset(f,0x3f,sizeof(f));
		f[0]=0;
		scanf("%d%d",&n,&m);
		//cout<<n<<' '<<m<<endl;
		for(int i=1;i<=n;i++) scanf("%lf%lf",&x[i],&y[i]);//cout<<x[i]<<' '<<y[i]<<endl;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				double a,b;
				solve(a,b,i,j);
				//cout<<a<<"qwq"<<b<<endl;
				if(a>-eps) continue;
				for(int k=1;k<=n;k++)
				{
					//cout<<k<<' '<<a*x[k]*x[k]+b*x[k]-y[k]<<endl;
					if(fabs(a*x[k]*x[k]+b*x[k]-y[k])<eps) l[i][j]|=(1<<(k-1));//cout<<k<<"qwq"<<endl;
					//cout<<"qwq\n";
				}
			}
		}
		for(int i=0;i<(1<<n);i++)
		{
			int j=low[i];
			//cout<<"qwq233\n";
			f[i|(1<<(j-1))]=min(f[i|(1<<(j-1))],f[i]+1);
			for(int k=1;k<=n;k++) f[i|l[j][k]]=min(f[i|l[j][k]],f[i]+1);//cout<<"qwq\n";
		}
		cout<<f[(1<<n)-1]<<endl;
	}
}
