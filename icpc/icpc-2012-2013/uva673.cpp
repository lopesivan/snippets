#include <cstdio>
#include <stack>
#include <cstring>

#define MAX (129+10)

using namespace std;

int main()
{
	int t, i, tam, flag;
	stack<char> pilha;
	char input[MAX];
	
	scanf("%d%*c", &t);
	
	while (t--)
	{
		flag = 0;
		pilha = stack<char> ();
		
		gets(input);
		tam = strlen(input);
		
		for (i = 0; i < tam; i++)
		{
			switch ( input[i] )
			{
				case '[':
				case '(':
					pilha.push( input[i] );
					break;
				case ')':
					if ( pilha.size() )
					{
						if ( pilha.top() == '(' )
							pilha.pop();
						else
							flag = 1;
					}
					else
						flag = 1;
					break;
				case ']':
					if ( pilha.size() )
					{
						if ( pilha.top() == '[' )
							pilha.pop();
						else
							flag = 1;
					}
					else
						flag = 1;
					break;
				
			}
			if (flag)
				break;
		}
		
		if ( pilha.size() )
			flag = 1;
		
		flag == 1 ? puts("No") : puts("Yes");
	}
	return 0;
}