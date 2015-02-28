/* Problema: encontre o centro do grafo! -- versão caminhoneiros ((motoqueiros)) */

#include <stdio.h>
#include <string.h>

#define infty 0x3f3f3f3f
#define MAXI 100
#define MAXJ 100

int max(int a, int b)
{
	return (a>=b)?(a):(b);
}

int min(int a,int b)
{
	return (a>=b)?(b):(a);
}

int adj[MAXI][MAXJ]; /*matriz de adjacência, se (i,j) está conectado = custo-aresta, senão = \infty*/
int custo[MAXI][MAXJ]; /*o que é gerado pelo floyd em cima de adj*/

void floyd(int n)
{
	int i,j,k;

	/*inicializa com m(i,j,0) ==> se (i,j) \in \mathbb{E} = custo-aresta, senão está conectado vale \infty, senão i,i=0*/
	for (i=0; i<n; i++)
		for (j=0; j<n; j++)
		{
			if (!adj[i][j])
				custo[i][j]=infty;
			else
				custo[i][j]=adj[i][j];
		}

	for (i=0; i<n; i++)
		custo[i][i]=0;

	/*processa o floyd*/
	for (k=0; k<n; k++)
		for (j=0; j<n; j++)
			for (i=0; i<n; i++)
				custo[i][j] = min(custo[i][j], custo[i][k]+custo[k][j]);
}

int main()
{
	int n,m; /*n nós e m arestas*/
	int i,j;
	int u,v,w;
	int menor=infty, maior=-1; /*maior = maior da linha atual*/

	memset(adj, infty, sizeof(adj)); /*obs.: memset só funciona para 0, -1 e 'strings periódicas de numeros'*/

	scanf("%d%d",&n,&m);

	/*preenche a matriz de adjacencia*/
	for (i=0; i<m; i++)
	{
		scanf("%d%d%d",&u,&v,&w);
		adj[u][v]=adj[v][u]=w;
	}

	/*processa floyd e obtem o menor caminhoneiro*/
	floyd(n);

	/*for (i=0; i<n; i++)
	{
		for (j=0; j<n; j++)
		{
			printf("%4d ",custo[i][j]);
		}
		printf("\n");
	}*/

	for (i=0; i<n; i++)
	{
		maior=-1;
		for (j=0; j<n; j++)
		{
			if (custo[i][j] > maior)
				maior=custo[i][j];
		}
		if (maior < menor)
				menor=maior;
	}

	printf("%d\n",menor);


	return 0;
}
