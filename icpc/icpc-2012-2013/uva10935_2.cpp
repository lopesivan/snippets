#include <cstdio>
#include <deque>

using namespace std;

int main()
{
	int n, tmp, i;
	deque<int> bar;
	
	while( scanf("%d", &n) == 1)
	{
		if (!n)
			break;
		else if (n == 1)
		{
			printf("Discarded cards:\nRemaining card: 1\n");
		}
		else
		{
			//reset
			bar = deque<int> ();
			
			for (i = 1; i <= n; i++)
				bar.push_back(i);
			
			//simula
			printf("Discarded cards: ");
			
			while ( bar.size() > 1 )
			{
				if (bar.size() > 2)
					printf("%d, ", bar.front() );
				else
					break;
				bar.pop_front();
				tmp = bar.front();
				bar.pop_front();
				bar.push_back(tmp);
			}
			
			tmp = bar.front();
			bar.pop_front();
			
			printf("%d\nRemaining card: %d\n", tmp, bar.front() );
		}
	}
	
	return 0;
}