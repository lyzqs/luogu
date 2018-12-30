#include<bits/stdc++.h>
using namespace std;
char a[10005],b[10005],c[1005];
int n,len,len2,s[10005],f[1005];
int main()
{
	memset(s,0,sizeof(s));
	scanf("%s",a);
	scanf("%s",b);
	scanf("%s",c);
	len=strlen(a),len2=strlen(c);
	for(int i=0;i<len;i++)
	{
		if(s[a[i]]==0||s[a[i]]==b[i]) s[a[i]]=b[i],f[b[i]]++;
		else 
		{
			printf("Failed");
			return 0;
		}
	}
	for(int i='A';i<='Z';i++)
	{
		if(s[i]==0||f[i]==0)
		{
			printf("Failed");
			return 0;
		}
	}
	for(int i=1;i<=len2;i++)
	{
		putchar(s[c[i-1]]);
	}
}
