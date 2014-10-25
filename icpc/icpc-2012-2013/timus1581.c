#include <stdio.h>

int main()
{
	int n,i,count,prev,next;
	
	scanf("%d",&n);
	scanf("%d",&prev);
	
	if (n==1)
		printf("%d %d",1,prev);
	
	else
	{
		count=1;
		for (i=1; i<n; i++)
		{
			scanf("%d",&next);
			
			if (next != prev)
			{
				printf("%d %d ", count, prev);
				count=1;
				prev=next;
			}
			else
				count++;
		}
		
		printf("%d %d", count, prev);
	}
	
	return 0;
}