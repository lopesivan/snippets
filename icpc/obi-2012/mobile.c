#include <stdio.h>
#include <stdlib.h>

int flag;

/*protótipos*/
int eval(int,int,int,int), mobile();
void pflag(void);

void pflag() /* imprime flag, para debug*/
{
    printf("flag vale: %d\n",flag);
}

int eval(int a,int b,int c,int d) /*se o conjunto esta em equilibrio retorna 1,
senao retorna 0*/
{
    return (a*b)==(c*d)? (1) : (0);
}

int mobile()
{
    int a,b,c,d;
    int peso=0,_peso=0;

    scanf("%d%d%d%d",&a,&b,&c,&d);

    if (a==0 && c!=0)
    {
        peso += mobile();
        flag = flag && eval(peso,b,c,d);
    }

    else if (a!=0 && c==0)
    {
        _peso += mobile();
        flag = flag && eval(a,b,_peso,d);
    }

    else if (a!=0 && c!=0)
    {
        flag = flag && eval(a,b,c,d);
    }

    else
    {
        peso += mobile();
        _peso += mobile();
        flag = flag && eval(peso,b,_peso,d);

    }

    return peso+a+_peso+c;
}

int main()
{
    int n,i,v=0;

    scanf("%d",&n);

    for (i=0; i<n; i++)
    {
	if(v) printf("\n");
        flag=1;
        mobile();

        (flag==1)? puts("YES") : puts("NO");
	v++;
    }

    return 0;
}

/*SAMPLE:

15

0 2 6 5 
0 2 6 3 
1 8 0 1 
0 5 0 3 
1 2 2 1 
2 3 3 2 

0 2 6 6 
0 2 6 3 
1 8 0 1 
0 5 0 3 
1 2 2 1 
2 3 3 2 

0 2 0 4 
0 3 0 2 
1 1 1 1 
2 4 4 2 
1 6 3 2 

0 2 0 4 
0 3 0 1 
1 1 1 1 
2 4 4 2 
1 6 3 2 

1 6 3 1 

2 4 4 2 

0 4 8 1 
1 1 1 3 

1 1 1 1 

2 100 100 2 

2 100 2 100 

0 3 0 3 
0 2 0 2 
1 1 1 1 
1 1 1 1 
0 2 0 2 
1 1 1 1 
1 1 1 1

0 2 0 4
0 3 0 1
1 1 1 1
2 4 4 2
1 6 3 2

0 2 4 4
0 2 4 2
2 2 2 2

4 4 0 2
4 2 0 2
2 2 2 2

0 2 4 4
0 2 4 2
2 1 2 2


DEVE RETORNAR:
YES

NO

NO

YES

NO

YES

NO

YES

YES

YES

YES

YES

YES

YES

NO
*/
