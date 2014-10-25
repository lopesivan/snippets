#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

char s[60];

int cmp (const void *a, const void *b)
{
	return strcmp( (char*)a, (char*)b );
}

void f()
{
	int tam;
	tam = strlen(s);
	
	if (tam == 1)
		puts("No Successor");
	else
	{
		int flag = 0;
		int i;
		
		for (i = tam-1; i > 0; --i)
		{
			if (s[i-1] < s[i])
			{
				flag = 1;
				break;
			}
		}
		
		if (flag == 0)
			puts("No Successor");
		else
		{
			int pos = i-1;
			
			for (i = tam-1; i > pos; --i)
			{
				if (s[i] > s[pos])
				{
					char temp = s[i];
					s[i] = s[pos];
					s[pos] = temp;
					break;
				}
			}
			qsort( s + pos+1, tam - (pos+1), sizeof s[0], cmp);
			
			puts(s);
		}
	}
	
}

int main()
{
	while ( scanf("%s", s) , strcmp(s, "#"))
	{
		f();
	}
	
	return 0;
}