#include <stdio.h>
#include <string.h>
#define MAX (180001)
#define min(a,b) (((a)<=(b)) ? (a) : (b))

int main()
{
	int sinais[100], count = -1, i, j, k, flag, inicio;
	
	while (1)
	{
		/* entrada*/
		while (scanf("%d", &sinais[++count]), sinais[count] );
		
		/* minimo */
		inicio = 100;
		for (i = 0; i < count; ++i)
			inicio = min(inicio, sinais[i]-5);
		
		/* processamento*/
		for (i = inicio; i < MAX; ++i)
		{
			flag = 1;
			
			for (j = 0; j < count; ++j)
			{
				k = sinais[j];
				
				/*se for vermelho OU se for laranja*/
				if (  (((i % (2*k))/k) == 1) || ((((i % (2*k))/k) == 0) && (i % k) >= (k - 5)) )
				{
					flag = 0;
					break;
				}
			}
			
			/*se for essa, imprima a hora*/
			if (flag)
			{
				printf("%02d:%02d:%02d\n", i/3600, (i/60)%60, i%60);
				break;
			}
		}
		if (i == MAX)
			puts("Signals fail to synchronise in 5 hours");
		
		count = -1;
		scanf("%d",&sinais[++count]);
		scanf("%d",&sinais[++count]);
		
		if (sinais[1] == 0)
			break;
	}
	
	return 0;
}