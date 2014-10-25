#include <stdio.h>
#define MAX (105)

int main()
{
	int n,i,j,temp;
	int idade[MAX];
	
	while (scanf("%d",&n) == 1)
	{
		if (!n)
			break;
		
		for (i=0; i< MAX; i++)
			idade[i]=0;
		
		for (i=0; i<n; i++)
		{
			scanf("%d",&temp);
			idade[temp]++;
		}
		
		for (i=1; i<MAX; i++)
		{
			for (j=0; j< idade[i]; j++)
			{
				if (j || (!j && (i-1)))
					printf(" ");
				printf("%d",i);
			}
		}
		
		puts("");
	}
	
	
	return 0;
}