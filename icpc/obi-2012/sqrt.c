#include <stdio.h>
#include <math.h>
#define MAX 65536+100

int main()
{
long long a[MAX],i=0;

while (scanf("%lld",&a[i++]) != EOF);

for (i=i-2; i>=0; i--)
printf("%.4f\n",sqrt(a[i]));



return 0;

}
