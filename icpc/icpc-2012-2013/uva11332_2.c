#include <stdio.h>

#define MAX 10

int a;
int dez[20];

int dig()
{
	return a > 9 ? 1 : 0;
}

int sum()
{
	int i;
	int sum = 0;
	
	for (i = 0; i < MAX; i++)
		sum += (a / dez[i]) % 10;
		
	return sum;
}

int main()
{
	int i;
	dez[0] = 1;
	
	for (i=1; i < MAX; i++)
		dez [i] = dez [i-1] * 10;
		
	
	while ( scanf("%d",&a) )
	{
		if (!a)
			break;
		
		while ( dig() )
			a = sum();
		
		printf("%d\n", a);
	}
	
	return 0;
}