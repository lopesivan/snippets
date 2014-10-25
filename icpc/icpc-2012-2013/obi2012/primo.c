#include <stdio.h>
#include <math.h>

int main()
{
    long int n;
    int i;

    scanf("%ld",&n);

    if (!n%2)
    {
        if (n!=2)
        {
            printf("nao");
            return 0;
        }
        else
        {
            printf("sim");
            return 0;
        }
    }

    for (i=3; i<= floor(sqrt(n)); i+=2)
    {
        if (!n%i)
        {
            if (n!=i && n>1)
            {
                printf("nao");
                return 0;
            }
            else if (n>1)
            {
                printf("sim");
                return 0;
            }
        }
    }

    return 0;
}
