#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX (100+5)

void copy (int deck[], int deckaux[]) /*copia as cartas de deckaux para deck*/
{
	int i;
	for (i=0; i<52; i++)
		*(deck+i)=*(deckaux+i);
}

void pdeck(int deck[]) /*imprime o deck especificado*/
{
	int i;
	int naipe,numero;
	for (i=0; i<52; i++)
	{
		naipe=(deck[i]-1)/13; /*varia de 0 a 3*/
		numero=(deck[i]-1)%13; /*varia de 0 a 12, repr 2 a A*/
		
		if (numero <=8)
			printf("%d",numero+2);
		else
			switch (numero)
			{
				case 9: printf("Jack"); break;
				case 10: printf("Queen"); break;
				case 11: printf("King"); break;
				case 12: printf("Ace"); break;
			}
		printf(" of ");
		switch (naipe)
		{
			case 0: puts("Clubs"); break;
			case 1: puts("Diamonds"); break;
			case 2: puts("Hearts"); break;
			case 3: puts("Spades"); break;
		}
	}
}

int main()
{
	int test,n,prox,shuf[MAX][52];
	int deck[52],deckaux[52];
	int t,i,j; /*iteradores*/
	char s[5]; /*para reconhecer uma linha em branco*/
	
	scanf("%d",&test);
	
	for (t=0; t<test; t++)
	{
		if (t)
			puts("");
		
		/*inicializa deck*/
		for (i=0; i<52; i++)
			deck[i]=i+1;
		
		
		/*adquire todos os shuffles e armazena em shuf[numero do shuffle][carta correspondente]*/
		scanf("%d",&n);
		for (j=0; j<n; j++)
			for (i=0; i<52; i++)
				scanf("%d",&shuf[j][i]);
		
		gets(s);
		
		while(gets(s))
		{
			if (strlen(s)!=0)
			{
				sscanf(s,"%d",&prox);
				prox--;
				for (i=0; i<52; i++)
					deckaux[i]=deck[ (shuf[prox][i])-1];
				copy(deck,deckaux);
			}
			else
				break;
		}
		pdeck(deck);
	}

	return 0;
}