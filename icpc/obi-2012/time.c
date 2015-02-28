#include <stdio.h>
#include <time.h>

long long int i;

/*int main()
{
	
	time_t ini = time(0); // tempo de inicio
		
	for (i=0; i<1000000000; i++);
	
	
	printf("duracao do metodo em s: %d\n",time(0)-ini);
	
	return 0;
}*/

int main()
{
	clock_t t0, tf;
	double tempo_gasto;
	t0 = clock();
	
	for (i=0; i<10000000000; i++);
	
	tf = clock();
	tempo_gasto = ( (double) (tf - t0) ) / (CLOCKS_PER_SEC/1000);
	printf("Tempo gasto: %lf ms\n", tempo_gasto);
	
	return 0;
   
}