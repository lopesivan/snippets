#include <stdio.h>
#include <string.h>

#define MAX_C (105)
#define infty (0x3f3f3f3f)
#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))

int c,s,q;
int custo[MAX_C][MAX_C];

void floyd()
{
    int i,j,k;
	int temp;

    for (i=0; i<MAX_C; ++i)
        custo[i][i]=0;

    for (k=0; k<c; ++k)
        for (i=0; i<c; ++i)
            for (j=0; j<c; ++j)
            {
				temp = max(custo[j][k],custo[k][i]);
                custo[i][j] = min(custo[i][j],temp);
            }
}

int main()
{
    int i,x,y,z;
    int v=0;
	/*printf("%d %#x",0x3f3f3f3f,0x3f3f3f3f);*/

    memset(custo,infty,sizeof (custo));

    while (scanf("%d%d%d",&c,&s,&q) == 3)
    {
        if (!(c || s || q))
            break;

        if(v)
            printf("\n");

        for (i=0; i<s; ++i)
        {
            scanf("%d%d%d",&x,&y,&z);
            --x,--y;
            custo[x][y]=z;
        }

        floyd();
		printf("Case #%d\n",++v);

        for (i=0; i<q-1; ++i)
        {
            scanf("%d%d",&x,&y);
            --x,--y;
            custo[x][y]==infty ? puts("no path") : printf("%d\n",custo[x][y]);
        } 
			scanf("%d%d",&x,&y);
			x--,y--;
			custo[x][y]==infty? printf("no path\n") : printf("%d\n",custo[x][y]);
        

        memset(custo,infty,sizeof (custo));
    }


    return 0;
}
