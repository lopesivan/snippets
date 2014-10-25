#include <cstdio>
#include <set>

using namespace std;

int min3 (int a, int b, int c)
{
	if (a<b && a<c)
		return a;
	else if (b<c)
		return b;
	else
		return c;
}

int main()
{
	int b, sg, sb, n;
	int i,tmp,rounds;
	multiset <int> green, blue, greenbuffer, bluebuffer;
	multiset <int> ::iterator ig, ib, it;
	multiset <int> ::reverse_iterator rit;
	
	scanf("%d",&n);
	
	while (n--)
	{
		scanf("%d%d%d",&b,&sg,&sb);
		green.clear();
		blue.clear();
		
		for (i=0; i<sg; i++)
		{
			scanf("%d",&tmp);
			green.insert(tmp);
		}
		
		for (i=0; i<sb; i++)
		{
			scanf("%d",&tmp);
			blue.insert(tmp);
		}
		
		/*simulation*/
		while (green.size() != 0 && blue.size() != 0)
		{
			rounds = min3(green.size(), blue.size(), b);
			greenbuffer.clear();
			bluebuffer.clear();
			
			/*batalhas*/
			for (ig = green.end(), ib = blue.end(), i = 0; i < rounds; i++)
			{
				ig--;
				ib--;
				
				if (*ig > *ib)
				{
					greenbuffer.insert(*ig-*ib);
					blue.erase(ib);
					green.erase(ig);
				}
				else if (*ib > *ig)
				{
					bluebuffer.insert(*ib-*ig);
					green.erase(ig);
					blue.erase(ib);
				}
				else
				{
					green.erase(ig);
					blue.erase(ib);
				}
			}
			/*arranjar*/
			for (it = greenbuffer.begin(); it!=greenbuffer.end(); it++)
				green.insert(*it);
			for (it = bluebuffer.begin(); it!=bluebuffer.end(); it++)
				blue.insert(*it);
		}
		
		if (green.size()==0 && blue.size()==0)
			puts("green and blue died");
		else if (green.size()==0)
		{
			puts("blue wins");
			for (rit = blue.rbegin(); rit != blue.rend(); rit++)
					printf("%d\n", *rit);
		}
		else
		{
			puts("green wins");
			for (rit = green.rbegin(); rit!= green.rend(); rit++)
				printf("%d\n",*rit);
		}
		
		if (n)
			puts("");
	}
	
	return 0;
}