#include <cstdio>
#include <queue>
#include <deque>

using namespace std;

int main()
{
	int n, tmp;
	deque<int> bar;
	queue<int> discard;
	
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
			discard = queue<int> ();
			bar = deque<int> ();
			
			for (int i = 1; i <= n; i++)
				bar.push_back(i);
			
			//simula
			while ( bar.size() > 1 )
			{
				discard.push( bar.front() );
				bar.pop_front();
				tmp = bar.front();
				bar.pop_front();
				bar.push_back(tmp);
			}
			
			//imprime
			printf("Discarded cards: ");
			
			while ( discard.size() > 1 )
			{
				printf("%d, ", discard.front() );
				discard.pop();
			}
			printf("%d\nRemaining card: %d\n", discard.front(), bar.front() );
		}
	}
	
	return 0;
}