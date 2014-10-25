#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <map>
#include <string>

using namespace std;

int main()
{
	int m, n, i;
	map<string,float> dict;
	char input[50], c;
	int valor, sum;
	
	scanf("%d%d", &m, &n);
	
	for (i = 0; i < m; ++i)
	{
		scanf("%s%d", input, &valor);
		dict[input] = valor;
	}
	
	getchar();
	
	for (i = 0; i < n; ++i)
	{
		sum = 0;
	
		while (1)
		{
			scanf("%s", input);
			
			if ( !strcmp(input, ".") )
				break;
			c = getchar();
			
			sum += dict[input];
		}
		
		printf("%d\n", sum);
	}
	
	return 0;
}