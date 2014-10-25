#include <stdio.h>
#include <stdlib.h>

int topo;

void push (int *p,int a)
{
    p[topo++]=a;
}

int pop (int *p)
{
    if (topo>0)
        return p[--topo];
    else
        return 0;
}

int main()
{
    int n,i,j,n2, permutacao=0;
    int *config, *inicial,*pilha;

    scanf("%d",&n);

    while (n!=0)
    {
        pilha=malloc(n*sizeof(int)); /*pilha de trens, "topo" controla*/
        inicial=malloc(n*sizeof(int));
        config=malloc(n*sizeof(int));

        topo=0;

        /*adquire o trem*/
        if (permutacao)
        {
            *config=n2;
            i=1;
        }
        else
            i=0;

        for (; i<n; i++)
            scanf("%d",config+i);

        /*preenche o trem inicial, em B*/
        for (i=0; i<n; i++)
            *(inicial+i)=i+1;

        permutacao=0;

        /*processamento solo*/
        for (i=0,j=0; j<n || (topo > 0 && topo<n); ) /*i indexa config e j indexa inicial, pilha é indexada por topo*/
        {
            if (config[i]==inicial[j])
            {
                /*puts("vai");*/
                j++;
                i++;
            }

            else if (topo!=0 && config[i]==pilha[topo-1])
            {
                /*puts("pop");*/
                pop(pilha);
                i++;
            }
            else
            {
                if (j>=n)
                    break;
                else
                {
                    /*puts("push");*/
                    push(pilha,inicial[j]);
                    j++;
                }
            }


        }

        if (i==n)
            printf("Yes\n");
        else
            printf("No\n");

        free(pilha);
        free(inicial);
        free(config);

        scanf("%d",&n2);

        if (n2==0)
        {
            scanf("%d",&n);
            permutacao=0;
            printf("\n");
        }
        else
            permutacao=1;

    }

    return 0;
}
