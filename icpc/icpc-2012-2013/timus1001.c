/*problem: crash on test #9*/

#include <stdio.h>
#include <math.h>

#define MAX (131078) /*256*1024/2*/

int main()
{
	int i=0;
	long long a[MAX];

	while (scanf("%lld",&a[i++]) == 1);

	for (i=i-2; i>=0; i--)
		printf("%.4lf\n",sqrt(a[i]));


	return 0;

}