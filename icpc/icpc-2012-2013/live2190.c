#include <stdio.h>

int main()
{
	int n, h, m, _h, _m, i, diff, tmp;
	
	while (scanf("%d", &n) == 1)
	{
		diff = 0;
		
		for (i = 0; i < n; ++i)
		{
			scanf("%d%d%d%d", &h, &m, &_h, &_m);
			
			tmp = (_h - h) * 60 + (_m - m);
			
			if (tmp > 0)
				diff += tmp;
		}
		
		printf("%d\n", diff/n);
	}
	
	return 0;
}