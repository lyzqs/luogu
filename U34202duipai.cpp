#include <bits/stdc++.h>
using namespace std;
int main()
{
	long long cnt=0,t,s,k=300;
	while(1)
	{
		while(k--)
		{
			printf("(%lld):",++cnt);
			system("U34202md > try.in");
			s=clock();
			system("U34202 < try.in > try.out");
			t=clock();
			system("U34202test <try.in > try.ans");
			if(system("fc try.out try.ans>nul")) 
			break;
			if(t-s>1000) printf("TLE but ");
			printf("AC! Time:%lldms QAQ\n",t-s);
		}
		printf("WA! Time:%lldms qwq\n",t-s);
		system("fc try.out try.ans");
		system("pause>nul");
	}
}
