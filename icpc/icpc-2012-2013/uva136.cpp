/*Problema: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=72
UGLY NUMBERS : 136*/

#include <cstdio>
#include <cstdlib>
#include <set>

#define POT 13

using namespace std;

/*int cmp (const void *a, const void *b)
{
	long long int *c;
	long long int *d;
	
	c = (long long int*) a;
	d = (long long int*) b;
	
	if (*c > *d)
		return 1;
	else if (*c < *d)
		return (-1);
	else
		return 0;
}*/

int main()
{
	set <long long int> ugly;
	set <long long int> ::iterator it;
	long long int tmp;
	int i,j,k;
	int dois[POT],tres[POT],cinco[POT]; /*potencias, por exemplo dois[10] = 1024*/
	/*long long int v[2000];
	int w=0;*/
	
	/*inicializacao dos vetores potencia*/
	dois[0]=tres[0]=cinco[0]=1;
	
	for (i=1; i<POT; i++)
		dois[i]=dois[i-1]*2;
	
	for (i=1; i<POT; i++)
		tres[i]=tres[i-1]*3;
	
	for (i=1; i<POT; i++)
		cinco[i]=cinco[i-1]*5;
	
	/*calculo dos 12^3 = 1728 primeiros ugly numbers*/
	for (i=0; i<POT; i++)
		for (j=0; j<POT; j++)
			for (k=0; k<POT; k++)
			{
				tmp = ((long long int) cinco[i]) * tres[j] * dois[k];
				ugly.insert(tmp);
				/*v[w++] = cinco[i] * tres[j] * dois[k];*/
			}
	
	for (it = ugly.begin(), i=0; i < 1499; i++)
		it++;
	printf("The 1500'th ugly number is %lld.\n",*it);
	
	printf("%lld\n", *ugly.begin());
	
	/*qsort( v, w, sizeof v[0], cmp);
	
	printf("The 1500'th ugly number is %lld.\n",v[1499]);*/
	
	return 0;
}