#include <stdio.h>

int main()
{
	int t, n, h, i, j, k, lim, count;
	
	scanf("%d", &t);
	
	while (t--)
	{
		scanf("%d%d", &n, &h);
		
		lim = (1 << n);
		
		for (j = 0; j < lim; ++j)
		{
			count = 0;
			for (i = 0; i < n; ++i)
				if ( (j>>i)&1 )
					++count;
			if (count == h)
			{
				for (k = n-1; k>=0; --k)
					((j>>k)&1) == 1? putchar('1') : putchar('0');
				puts("");
			}
		}
		
		
		if (t)
			puts("");
	}
	
	return 0;
}