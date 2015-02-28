#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX (50000+500)

int mat[MAX];
int n;

struct combinacao
{
	int v[5];
} comb[MAX/5];

int compara_combinacao(struct combinacao a, struct combinacao b)
{
	int i;
	
	for (i=0; i<5; i++)
		if (a.v[i] != b.v[i])
			return 0;
	return 1;
}

int max(int a, int b)
{
	return a>=b? a : b;
}

int min(int a, int b)
{
	return a<=b? a : b;
}

int cmp(const void *a, const void *b)
{
	int *c,*d;
	
	c=(int*)a;
	d=(int*)b;
	
	if (*c > *d)
		return 1;
	else if (*c == *d)
		return 0;
	else return (-1);
}

int cmp2 (const void *a, const void *b)
{
	struct combinacao *c,*d;
	
	c=(struct combinacao*)a;
	d=(struct combinacao*)b;
	
	int i;
	
	for (i=0; i<5; i++)
	{
		if (c->v[i] > d-> v[i])
			return 1;
		else if (c->v[i] < d-> v[i])
			return (-1);
	}
	
	return 0;
	
}

void bubble(int inicio, int fim)
{
	int i,j,temp;
	
	for (i=inicio; i<=fim; i++)
		for (j=i+1; j<=fim; j++)
		{
			if (mat[i]>mat[j])
			{
				temp=mat[i];
				mat[i]=mat[j];
				mat[j]=temp;
			}
		}
}

void reset()
{
	memset(mat,0,sizeof mat);
	memset(comb,-1,sizeof comb);
}

void ord5()
{
	int i;
	
	for (i=0; i<n; i++)
		bubble(i*5,i*5+4);
}

void process()
{
	int i,j;
	int frosh,frosh_max=0,answer=0;
	
	/*combinacao*/
	for (i=0; i<n; i++)
		for (j=0; j<5; j++)
			comb[i].v[j]=mat[5*i+j];
	
	/*ordenacao*/
	qsort (comb, n, sizeof comb[0], cmp2);
	
	/*
	 * debug_imprimir 
	for (i=0; i<n; i++)
		for (j=0; j<5; j++)
			printf("%d ",comb[i].v[j]);
	*/
	
	/*frosh_max*/
	for (i=0,frosh=1; i<n-1; i++)
	{
		if ( compara_combinacao(comb[i],comb[i+1]))
			frosh++;
		else
			frosh=1;
		frosh_max=max(frosh_max,frosh);
	}
	
	/*soma dos frosh_max*/
	for (i=0,frosh=1; i<n-1; i++)
	{
		if ( compara_combinacao(comb[i],comb[i+1]))
			frosh++;
		else
		{
			if (frosh == frosh_max)
				answer+=frosh_max;
			frosh=1;	
		}
	}
	
	if (frosh == frosh_max)
		answer+=frosh_max;
	
	
	printf("%d\n", answer);
}

int main()
{
	int i;
	
	while (scanf("%d",&n)==1)
	{
		if (!n)
			break;
		
		reset();
		
		for (i=0; i<n*5; i++)
			scanf("%d",&mat[i]);
		
		ord5();
		
		/*
		* debug_imprimir
		* 
		* {
			int i;
			for (i=0; i<5*n; i++)
				printf("%d ", mat[i]);
		}
		*/
		
		process();
		
	}
	
	return 0;
}