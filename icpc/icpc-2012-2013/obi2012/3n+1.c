#include <stdio.h>
#define max(a,b) (((a)>(b))?(a):(b))

int main()
{
	int a,b,am,bm,w,length,maxlength;
	
	while (scanf("%d%d",&a,&b) == 2)
	{
		maxlength=0;
		
		if (a>b)
		{
			am=b;
			bm=a;
		}
		else
		{
			am=a;
			bm=b;
		}
		
		while (bm>=am)
		{
			length=1;
			w=bm;
			
			while (w!=1)
			{
				if (!(w%2))
					w/=2;
				else
					w=3*w+1;
				length++;
			}
			
			maxlength=max(maxlength,length);
			
			bm--;
		}
		
		printf("%d %d %d\n",a,b,maxlength);		
		
	}
	
	
	return 0;
}