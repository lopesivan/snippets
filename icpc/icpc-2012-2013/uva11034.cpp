#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

int main()
{
	int c, l, m, tmp, viagem, atual;
	queue<int> left, right;
	char input[10];
	
	scanf("%d", &c);
	
	while (c--)
	{
		left = right = queue<int> ();
		viagem = 0;
		
		scanf("%d%d", &l, &m);
		
		l*=100;
		
		while (m--)
		{
			scanf("%d%s", &tmp, input);
			
			if ( !strcmp(input, "left") )
				left.push(tmp);
			else
				right.push(tmp);
		}
		
		while ( !left.empty() || !right.empty() )
		{
			atual = 0;
			
			while(!left.empty() && (l - (atual + left.front() )) >= 0 )
			{
				atual += left.front();
				left.pop();
			}
			
			if( !left.empty() || !right.empty() )
				++viagem;
			
			atual = 0;
			
			while(!right.empty() && (l - (atual + right.front() )) >= 0)
			{
				atual += right.front();
				right.pop();
			}
			
			if( !left.empty() || !right.empty() )
				++viagem;
		}
		
		if (m)
			++viagem;
		
		printf("%d\n", viagem);
		
	}
	return 0;
}