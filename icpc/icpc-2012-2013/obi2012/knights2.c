#include <stdio.h>
#include <math.h>

int main()
{
	int n,m,k; /*k=resposta*/
	
	while (scanf("%d%d",&m,&n) ==2)
	{
		if (!(m || n))
			break;
		
		if (m==1 || n==1)
			k=(m>n? m:n);
		else if (m==2 || n==2)
		{
			int max=(m>n?m:n);
			if (max%4==0)
				k=max;
			else if(max%4==1)
				k=(max/4)*4+2;
			else
				k=((max/4)+1)*4;
		}
		else
		{
			int prod=m*n;
			if (!(prod % 2))
				k=prod/2;
			else
				k=(prod/2)+1;
		}
			
		printf("%d knights may be placed on a %d row %d column board.\n",k,m,n);
	}
	
	return 0;
}