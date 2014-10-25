#include <stdio.h>
#include <math.h>
#define MAX (250) /*2*q = 2*100=200*/
#define pnum(a) (a)==(-1)? printf("Blank") : printf("%d",a)


int main()
{
    int i,soma,q,r,n,sheet;
    int left[MAX],right[MAX];

    /*int left[]={12,2,10,4,8,6};
    int right[]={1,11,3,-1,9,5,-1};*/


    while (scanf("%d",&n) == 1)
    {
        if (!n)
            break;

        r = n % 4;
        q = (int) ceil( (double)n/4 );
        soma = (int) ceil ((double)n/4)*4+1;

        left[0] = ( r != 0 ? -1 : soma-1);
        right[0] = 1;
        right[1] = (r!=0 && r!=3? -1 : soma-2);
        left[1] = 2;
        left[2] = (r==1? -1 : soma-3);
        right[2] = 3;

        for (i = 3; i < 2*q; ++i)
        {
            if ( !(i%2) )
            {
                right[i] = i+1;
                left[i] = soma-(i+1);
            }
            else
            {
                left[i] = i+1;
                right[i] = soma-(i+1);
            }
        }

        /*imprime left and right adequadamente*/
        printf("Printing order for %d pages:\n",n);

        if (n == 1)
            printf("Sheet 1, front: Blank, 1\n");

        else
        {
            for (sheet = 1,i = 0; sheet <= q; ++sheet,++i)
            {
                printf("Sheet %d, front: ",sheet);
                pnum(left[i]);
                printf(", ");
                pnum(right[i]);
                puts("");

                ++i;

                printf("Sheet %d, back : ",sheet);
                pnum(left[i]);
                printf(", ");
                pnum(right[i]);
                puts("");
            }
        }

    }


    return 0;
}
