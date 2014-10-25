#include <stdio.h>
#include <stdlib.h>

int cmp( const void *a, const void *b)
{
	const int *c,*d;
	
	c=(const int *)a;
	d=(const int *)b;
	
	if (*c>*d)
		return 1;
	else if (*c<*d)
		return -1;
	else
		return 0;
}

int main()
{
	int k,i,num=0;
	int v[105];
	
	scanf("%d",&k);
	
	for (i=0; i<k; i++)
		scanf("%d",&v[i]);
	
	qsort(v,k,sizeof v[0], cmp);
	
	for (i=0; i<k/2+1; i++)
		num+=v[i]/2+1;
	
	printf("%d",num);
	
	
	
	return 0;
}