#include <bits/stdc++.h>
#define Max 1000005
using namespace std;
char a[Max],b[Max],c[Max];
char s1[Max],s2[Max],s3[Max],s4[Max],s5[Max];
int ol[6],ls[4],n,la,lb,lc,l1,l2,l3,l4,l5;
char l[Max];
int main()
{
	scanf("%d",&n);
	//scanf("%s%s%s",a+1,b+1,c+1);
	//printf("%s %s %s",a,b,c);
	//scanf("%s%s%s%s%s",s1+1,s2+1,s3+1,s4+1,s5+1);
	la=strlen(a+1),lb=strlen(b+1),lc=strlen(c+1),l1=strlen(s1+1),l2=strlen(s2+1),l3=strlen(s3+1),l4=strlen(s4+1),l5=strlen(s5+1);
	gets(l);
	while(n--)
	{
		gets(l+1);
		printf("%s\n",l+1);
	}
}
