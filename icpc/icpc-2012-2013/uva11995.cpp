#include <cstdio>
#include <stack>
#include <queue>

using namespace std;

int main()
{
	int n, i, a, b, efila, eprior, epilha;
	stack<int> pilha;
	queue<int> fila;
	priority_queue<int> prior;
	
	while (scanf("%d", &n) == 1 )
	{
		pilha = stack<int> ();
		fila = queue<int> ();
		prior = priority_queue<int> ();
		eprior = epilha = efila = 0;
		
		for (i = 0; i < n; ++i)
		{
			scanf("%d%d", &a, &b);
			
			switch(a)
			{
				case 1:
					pilha.push(b);
					fila.push(b);
					prior.push(b);
					break;
				case 2:
					if (pilha.size() != 0)
					{
						if (pilha.top() == b)
							pilha.pop();
						else
							epilha = 1;
					}
					else
						epilha = 1;
					
					if (fila.size() != 0)
					{
						if (fila.front() == b)
							fila.pop();
						else
							efila = 1;
					}
					else
						efila = 1;
					
					if (prior.size() != 0)
					{
						if (prior.top() == b)
							prior.pop();
						else
							eprior = 1;
					}
					else
						eprior = 1;
			}
		}
		if ( epilha == 1 && eprior == 1 && efila == 1)
			puts("impossible");
		else if (epilha == 0 && eprior == 1 && efila == 1)
			puts("stack");
		else if (epilha == 1 && eprior == 0 && efila == 1)
			puts("priority queue");
		else if (epilha == 1 && eprior == 1 && efila == 0)
			puts("queue");
		else
			puts("not sure");
		
	}
	
	return 0;
}