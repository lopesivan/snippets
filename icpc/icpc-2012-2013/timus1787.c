#include <stdio.h>

int main()
{
	int n, k, sum=0,i,tmp;
	
	scanf("%d%d",&k,&n);
	
	for (i=0; i<n; i++)
	{
		scanf("%d",&tmp);
		sum+=tmp;
		
		if (sum-k<=0)
			sum=0;
		else
			sum-=k;
			
	}
	
	printf("%d",sum);
	
	return 0;
}