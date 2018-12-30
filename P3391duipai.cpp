#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	ll cnt=0,s1,s2,t1,t2;
	while(1)
	{
		while(19260817)
		{
			printf("(%d):",++cnt);
			system("P3391md > P3391p1.in");
			s1=clock();
			system("P3391 < P3391p1.in > P3391p.ans");
			t1=clock();
			s2=clock();
			system("P3391stl < P3391p1.in > P3391p.out");
			t2=clock();
			if(system("fc P3391p.ans P3391p.out>nul"))
			break;
			printf("AC~!time1:%lld time2:%lld\n",t1-s1,t2-s2);
		}
		printf("WA?!time1:%lld time2:%lld\n",t1-s1,t2-s2);
		system("fc P3391p.ans P3391p.out");
		system("pause>nul");
	}
}
