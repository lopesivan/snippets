#include <stdio.h>
#define MAX (1000000+100)

int modif(int,int);

int modif(int a, int b)
{
	return a>=b? a-b:b-a;
	/*if (a>=b)
		return a-b;
	else
		return b-a;*/
}

int main()
{
	int n,v[MAX],i,soma=0;
	scanf("%d",&n);
	
	for (i=0; i<n; i++)
		scanf("%d",&v[i]);
	
	for (i=0; i<n; i++)
	{
		soma+=modif(i+1,v[i]);
		printf("%d\t%d\t%d\n",modif(i+1,v[i]),i+1,v[i]);
	}
	
	soma/=2;
	
	printf("%d",soma);
	
	
	return 0;
}