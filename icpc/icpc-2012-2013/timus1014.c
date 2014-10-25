#include <stdio.h>
#include <stdlib.h>

int cmp ( const void *a, const void *b)
{
	const int *c,*d;
	
	c=(const int*)a;
	d=(const int*)b;
	
	if (*c>*d)
		return 1;
	else if (*c<*d)
		return -1;
	else
		return 0;
}

int main()
{
	int n,digitos[100],i,current[8]={8,4,9,6,2,3,5,7},j;
	
	scanf("%d",&n);
	
	if (n==1)
		printf("%d",1);
	
	else if (n==0)
		printf("%d",0);
	
	else
	{
	
		i=j=0;
		
		while (j<8)
		{
			if (n%current[j]==0)
			{
				digitos[i++]=current[j];
				n/=current[j];
			}
			else
				j++;
		}
		
		if (n!=1)
			printf("%d",-1);
		
		else
		{
			qsort(digitos,i,sizeof digitos[0], cmp);
			
			for (j=0; j<i; j++)
				printf("%d",digitos[j]);
		}
	}
	return 0;
}