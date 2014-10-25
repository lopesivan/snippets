#include <stdio.h>
#include <stdlib.h>

int stack[104];
int stack2[104];
int top = -1;
int top2 = -1;

void push (char a)
{
	stack[++top] = a;
}

char pop()
{
	return stack[top--];
}

void push2 (char a)
{
	stack2[++top2] = a;
}

char pop2()
{
	return stack2[top2--];
}

int main()
{
	int v = 0;
	int n,i,j;
	int x,y;
	char a,b;
	
	scanf("%d%*c",&n);
	
	while (n--)
	{
		top = top2 = -1;
		y = 0;
		
		for (i = 0; i < 52; ++i)
		{
			scanf(" %c %c ",&a,&b);
			/*putchar(a), putchar(b), putchar(' ');*/
			push(a), push(b);
		}
		
		for (i = 0; i < 25; ++i)
		{
			a = pop();
			b = pop();
			push2 ( b );
			push2 ( a );
		}
		
		for (j = 0; j < 3; ++j)
		{
			b = pop();
			a = pop();
			
			if (a >= '2' && a <= '9')
				x = (int) (a - '0');
			else
				x = 10;
			
			/*putchar(a), putchar(b), printf("%d",x), putchar(' ');*/
			
			y += x;
			
			for (i = 0; i < 10 - x; ++i)
			{
				pop();
				pop();
			}
		}
		
		for (i = 0; i < 25; ++i)
		{
			a = pop2();
			b = pop2();
			push ( b );
			push ( a );
		}
		printf("Case %d: %c%c\n", ++v, stack[2*y-2], stack[2*y-1]);	
	}
	return 0;
}