#include <cstdio>
#include <set>

using namespace std;

int max (int a, int b)
{
	return a>=b? a : b;
}

int min (int a, int b)
{
	return a<=b? a : b;
}

int main()
{
	int p,k,n,t=3,i,tmp,tmp2,people,maxp,minp;
	set<int> in,out;
	set<int> ::iterator it,iz;
	
	while (t--)
	{
		in = out = set<int> ();
		people=maxp=0;
		minp=2000000000;
		
		scanf("%d%d%d",&p,&k,&n);
		
		for (i=0; i<n; i++)
		{
			scanf("%d%d",&tmp,&tmp2);
			in.insert(tmp);
			out.insert(tmp2);
		}
		
		it = in.begin();
		iz = out.begin();
		
		/* 1 5 7 8  --  5-10 --  8 8 9 10 */
		while ()
		{
			if (*it <= *iz)
			{
				people++;
				it++;
			}
			else
			{
				people--;
				iz++;
			}
			if ((*it<=k && *it>=p)|| (*iz<=k && *iz>=p))
			{
				maxp=max(people,maxp);
				minp=min(people,minp);
			}
		}
		printf("%d %d\n",minp,maxp);
	}
	
	return 0;
}