#include <cstdio>
#include <cstdlib>
#include <stack>

using namespace std;

#define mod(x)  (((x)>=0) ? (x) : (-(x)))

int main()
{
	stack<int> pilha, soma;
	int next, flag = 0, sum = 0;
	//unsigned int i;
	char c;
	
	while ( scanf("%d", &next) == 1 )
	{
		c = getchar();
		sum += next;
		
		if (next < 0)
		{
			pilha.push( mod(next) );
			
			if ( soma.size() )
				soma.top() -= mod(next);
			
			soma.push( mod(next) );
		}
		else // if (next > 0)
		{
			if (pilha.size() == 0)
				flag = 1;
			else
			{
				if (pilha.top() != next)
					flag = 1;
				pilha.pop();
			}
			if ( soma.size() == 0)
				flag = 1;
			else 
			{
				if (soma.top() <= 0)
					flag = 1;
				soma.pop();
			}
		}
		
		if (c == '\n' || c == EOF)
		{
			//print e reset
			if (sum != 0)
				flag = 1;
			
			flag == 0 ? puts(":-) Matrioshka!") : puts(":-( Try again.");
			
			soma = pilha = stack<int> ();
			flag = sum = 0;
		}
	}
	return 0;
}