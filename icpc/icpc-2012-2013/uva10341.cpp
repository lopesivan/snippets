#include <cstdio>
#include <cstdlib>
#include <cmath>

int p, q, r, s, t, u;

inline double calc(double x)
{
	return ( p*exp(-x) ) + ( q * sin(x) ) + (r * cos(x) ) + (s * tan(x) ) + (t * x * x) + (u);
}

int main()
{
	int flag;
	double inicio, fim, meio, comput, tmp;
	
	while (scanf("%d%d%d%d%d%d", &p, &q, &r, &s, &t, &u) == 6 )
	{
		inicio = 0.0; 
		fim = 1.0;
		flag = 100;
		
		while(flag--)
		{
			meio = (inicio+fim)/2;
			comput = calc(meio);
			
			if (comput == 0.0)
				break;
			else if (comput < 0)
				fim = meio;
			else
				inicio = meio;
		}
		
// 		printf("%lf     %lf\n", calc(meio), meio);
		
		tmp = calc(meio);
// 		(-0.0001 <= tmp && tmp <= 0.0001) ? printf("%.4lf\n", meio) : puts("No solution");
		( fabs(tmp) <= 0.0001) ? printf("%.4lf\n", meio) : puts("No solution");
	}
}