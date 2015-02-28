#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX (2000+20)

int compara(const void *p1, const void *p2)
{
	return strcmp((const char *)p1    ,(const char *)p2   );
}

int main()
{
	int n,i,count=1;
	char nomes[MAX][80];
	
	scanf("%d",&n);
	
	for (i=0; i<n; i++)
	{
		scanf("%s%*[^\n]%*c",nomes[i]);
	}
	
	qsort(nomes, n, sizeof(nomes[0]), compara);
	
	for (i=0; i<n-1; i++)
	{
		if (!strcmp(nomes[i],nomes[i+1]))
			count++;
		else
		{
			printf("%s %d\n",nomes[i],count);
			count=1;
		}
	}
	printf("%s %d\n",nomes[i],count);
	
	return 0;
}
