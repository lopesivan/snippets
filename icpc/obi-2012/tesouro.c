#include <stdio.h>
#define MAX 100
/*#define mod(a,b) a>=b ? (a-b) : (b-a)*/

int mod (int a, int b)
{
    return a>=b? (a-b) : (b-a);
}

int main()
{
    int v[MAX][MAX];
    int n,k;
    int i,r,s; /*índices*/
    int a,b,c;
    int tx, ty, flag=0; /*coordenadas do tesouro*/

    /*zera a matriz*/

    for (r=0; r<MAX; r++)
    {
        for (s=0; s<MAX; s++)
        {
            v[r][s]=0;
        }
    }

    /*parte 1: entrada e preenchimento da matriz com alguns 1's*/

    scanf("%d%d",&n,&k);

    for (i=0; i<k; i++)
    {
        scanf("%d%d%d",&a,&b,&c);

        for (r=0; r<n; r++)
        {
            for (s=0; s<n; s++)
            {
                /* (r,s) e (a,b) --> se |r-a| + |s-b|=c, poe igual a 1*/
                if (!i && (( mod(r,a) + mod(s,b) ) == c))
                        v[r][s]=1;
                else
                {
                    if (( mod(r,a) + mod(s,b) ) == c )
                    {
                        if (v[r][s])
                            v[r][s]=1;
                    }
                    else
                        v[r][s]=0;
                }
            }
        }

    }

    /*parte 2: checa coordenadas com 1*/

    for (r=0; r<n; r++)
    {
        for (s=0; s<n; s++)
        {
            if (v[r][s])
            {
                flag++;
                tx=r;
                ty=s;
            }
        }
    }

    if (flag==1)
        printf("%d %d",tx,ty);
    else
        printf("%d %d",-1,-1);

    return 0;
}
