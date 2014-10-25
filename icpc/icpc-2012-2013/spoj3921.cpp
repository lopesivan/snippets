#include <cstdio>
#include <set>

using namespace std;

int max (int a, int b)
{
	return a>=b ? a : b ;
}

int main()
{
	int t,n,i,tmp,tmp2,answer,people;
	std::set<int> in,out;
	std::set<int> ::iterator it,iz;
	
	scanf("%d",&t);
	
	while (t--)
	{
		in = set<int> ();
		out = set<int> ();
		/*in.clear();
		out.clear();*/
		answer=people=0;
		scanf("%d",&n);
		
		for (i=0; i<n; i++)
		{
			scanf("%d%d",&tmp,&tmp2);
			in.insert(tmp);
			out.insert(tmp2);
		}
		
		it = in.begin();
		iz = out.begin();
		
		/* 1 2 3 4 8 -- 6 7 9 11 13*/
		while (it != in.end() )
		{
			if (*it < *iz)
			{
				people++;
				answer = max(people, answer);
				it++;
			}
			else
			{
				people--;
				iz++;
			}
		}
		
		printf("%d\n",answer);
	}
	return 0;
}