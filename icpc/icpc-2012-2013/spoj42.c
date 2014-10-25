#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int reverse (int x)
{
	int i,j,tam,flag=0;
	char z[100];
	char y[100];
	
	sprintf(z, "%d", x);
	
	tam = strlen(z);
	
	for (i=tam-1, j=0; i >= 0; i--)
	{
		
	}
	
	y[j]='\0';
	
	sscanf(y, "%d", &x);
		   
	return x;
	
}

int main()
{
	int n,a,b;
	
	scanf("%d",&n);
	
	while (n--)
	{
		scanf("%d%d",&a,&b);
		
		printf("%d\n", reverse( reverse(a) + reverse(b) ) );
	}
	
	return 0;
}