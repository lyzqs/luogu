#include <bits/stdc++.h>
using namespace std;
int l,r,k,s,t,mld,mlu,mrd,mru,cnt=0,ans=0,flag,vst[10],zn,p[25];
int main()
{
	cin>>l>>r;
	for(int i=l;i<=r;i++)
	{
		k=i;
		cnt=0;
		t=s=0;
		flag=0;
		zn=0;
		mld=mlu=mrd=mru=-1;
		memset(vst,0,sizeof(vst));
		while(k!=0)
		{
			++cnt;
			p[cnt]=k%10;
			vst[p[cnt]]++;
			if(cnt%2==0) t+=p[cnt],mrd=max(p[cnt],mrd),mru=max(9-(p[cnt]),mru);
			else s+=p[cnt],mld=max(p[cnt],mld),mlu=max(9-(p[cnt]),mru);
			k/=10;
		}
		//if(s==t) continue;
		for(int j=cnt-1;j>=1;j--) 
			if(!p[j]) zn++;
				else break;
		if(s>t&&(s-t<=mld||s-t<=mru)&&cnt%2==1) ans++,flag=1;
		if(t>s&&(t-s<=mrd||t-s<=mlu)&&cnt%2==1) ans++,flag=1;
		if(cnt%2==0&&p[cnt]==t-s&&zn%2==0) ans++,flag=1;
		if(cnt%2==1&&p[cnt]==s-t&&vst[p[cnt]]==1&&zn%2==0&&mru<s-t) ans--,flag=0;
		//printf("p:%d cnt:%d k:%d zn:%d s:%d t:%d mld:%d mlu:%d mrd:%d mru:%d flag:%d\n",p[cnt],cnt,i,zn,s,t,mld,mlu,mrd,mru,flag);
	}	
	printf("%d",ans);
}
