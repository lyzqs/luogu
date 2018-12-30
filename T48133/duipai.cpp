#include <bits/stdc++.h>
using namespace std;
int main()
{
	int cnt=0;
	//while(1);
	while(19260817)
	{
		printf("(%d):",++cnt);
		//system()
		int s=clock();
		system("T48133 <1.in >1.ans");
		int t=clock();
		//system("dij <1.in >qwq.out");
		if(system("fc 1.ans 1.out"))
		{
			cout<<"WA!"<<endl;
			system("pause>nul");
		}
		else cout<<"AC time:"<<t-s;
	}
}
