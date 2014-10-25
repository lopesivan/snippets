#include <cstdio>
#include <cstring>
#include <stack>

#define MAX (3001+20)

using namespace std;

int main()
{
	char input[MAX];
	int tam, flag, i, j;
	stack<char> pilha;
	
	while( gets(input) )
	{
		flag = 0;
		pilha = stack<char> ();
		tam = strlen(input);
		
		for (i = 0, j = 0; i < tam; ++i, ++j)
		{
			switch (input[i])
			{
				case '[':
				case '<':
				case '{':
					pilha.push( input[i] );
					break;
				case '(':
					if (input[i+1] == '*')
					{
						pilha.push( input[i++] );
						pilha.push( input[i] );
					}
					else
						pilha.push( input[i] );
					break;
				
					
				case ']':
					if ( pilha.size() )
					{
						if (pilha.top() == '[')
							pilha.pop();
						else
							flag = 1;
					}
					else
						flag = 1;
					break;
					
				case '}':
					if ( pilha.size() )
					{
						if (pilha.top() == '{')
							pilha.pop();
						else
							flag = 1;
					}
					else
						flag = 1;
					break;
					
				case '>':
					if ( pilha.size() )
					{
						if (pilha.top() == '<')
							pilha.pop();
						else
							flag = 1;
					}
					else
						flag = 1;
					break;
					
				case ')':
					if (i >= 2)
						if (input[i-1] == '*' && input[i-2] != '(')
							--j;
					if ( pilha.size() )
					{
						if (pilha.top() == '(')
							pilha.pop();
						else
							flag = 1;
					}
					else
						flag = 1;
					break;
					
				case '*':
					if (input[i+1] == ')')
					{
						if ( pilha.size() )
						{
							if (pilha.top() == '*')
								pilha.pop();
							else
								flag = 1;
						}
						else
							flag = 1;
					}
					break;
			}
			
			if ( flag )
				goto tchau;
		}
		
		if ( pilha.size() )
			flag = 1;
		
		tchau:
		
		flag == 0 ? puts("YES") : printf("NO %d\n", j+1);
		
	}
	return 0;
}