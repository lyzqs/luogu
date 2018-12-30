#include <bits/stdc++.h>
using namespace std;
int main()
{
	int cnt=0;
	while(1)
	{
		long long s,t;
		while(++cnt)
		{
			printf("%d:",cnt);
			system("P2596md");
			system("P2596test");
			s=clock();
			system("P2596");
			t=clock();
			if(system("fc P2596.out P2596.ans>nul")) 
			break;
			if(t-s>1000) printf("TLE but ");
			printf("AC! Time:%lldms QAQ\n",t-s);
		}
		printf("WA! Time:%lldms qwq\n",t-s);
		system("fc P2596.out P2596.ans");
		system("pause>nul");
	}
}
