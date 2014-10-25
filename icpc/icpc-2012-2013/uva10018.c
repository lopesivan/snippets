#include <stdio.h>
#include <string.h>

/*unsigned int reversed (unsigned int n)
{
	char input[50], output[50];
	int tam, i;
	
	sprintf(input, "%u", n);
	tam = strlen(input);
	
	for (i = 0; i < tam; i++)
		output[i] = input[tam-1-i];
	output[tam]='\0';
	
	sscanf(output, "%u", &n);
	return n;
}*/

/*int pal (unsigned int n)
{
	char input[50], output[50];
	int i, tam;
	
	sprintf(input, "%u", n);
	tam = strlen(input);
	
	for (i = 0; i < tam; i++)
		output[i] = input[tam-1-i];
	output[tam]='\0';
	
	return strcmp(input, output) == 0? 1 : 0;
}*/

int pal (unsigned int n)
{
	unsigned int _n = n, m;
	
	m = 0;
	
	while (_n != 0)
	{
		m *= 10;
		m += _n % 10;
		_n /= 10;
	}
	
	return n == m ? 1 : 0;
}

unsigned int reversed (unsigned int n)
{
	unsigned int _n = n, m;
	
	m = 0;
	
	while (_n != 0)
	{
		m *= 10;
		m += _n % 10;
		_n /= 10;
	}
	
	return m;
}

int main()
{
	int t, iter;
	unsigned int n;
	
	scanf("%d", &t);
	
	while (t--)
	{
		iter = 0;
		scanf("%u", &n);
		
		while ( !pal(n) )
		{
			n += reversed(n);
			iter++;
		}
		
		printf("%d %u\n", iter, n);
		
	}
	
	return 0;
}