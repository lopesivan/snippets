#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

vector<int> v(40, 0);
vector<int> _v(40, 0);
stack<int> pilha;

inline void flip(int m)
{
	int i;
	
	for (i = 0; i <= m; ++i)
		pilha.push(v[i]);
	
	for (i = 0; i <= m; ++i)
		v[i] = pilha.top(), pilha.pop();
}

int main()
{
	int size, i, j, flag;
	char c;
	
	while(1)
	{
		//zera
		pilha = stack<int> ();
		size = 0;
		
		//adquire entrada
		flag = 1;
		
		while ( scanf("%d%c", &v[size++], &c) == 2 )
		{
			_v[size-1] = v[size-1];
			
			if (c == '\n')
			{
				flag = 0;
				break;
			}
		}
		
		if (flag)
			return 0;
		
		//echo entrada
		printf("%d", v[0]);
		for (i = 1; i < size; ++i)
			printf(" %d", v[i]);
		puts("");
		
		sort( _v.begin(), _v.begin() + size );
		
		//processa e imprime
		for (i = size - 1; i >= 0; --i)
		{
			if (v[i] != _v[i])
			{
				for (j = 0; j < i; ++j)
					if ( v[j] == _v[i])
						break;
				
				if (j != 0)
				{
					flip(j);
					printf("%d ", size-j);
				}
				
				flip(i);
				printf("%d ", size-i);
			}
		}
		
		printf("0\n");
		
	}
	
	return 0;
}