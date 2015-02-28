#include<stdio.h>
#include<string.h>

int dir[4][2] =
{
{0,1},
{1,0},
{0,-1},
{-1,0}
};

int M[110][110];
int n,m;

// retorna 1 se achou um 1 na regiao do 2 , 0 caso contrario
char busca(int i,int j){
	int d;

	if(i >= n || i < 0 || j >= m || j < 0) return 0;

	if(M[i][j] == 0 || M[i][j] == 3) return 0;

	char ret = 0;

	if(M[i][j] == 1)
		ret = 1;

	M[i][j] = 3;

	for(d=0;d<4;d++){
		int nl = i + dir[d][0];
		int nc = j + dir[d][1];

		char temp = busca(nl,nc);

		ret = ret||temp;
	}

	return ret;

}

int main(){
	int i,j,k,l,c;

	scanf("%d %d",&n,&m);

	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			char ch;
			scanf(" %c",&ch);
			if(ch == '.') M[i][j] = 0;
			else M[i][j] = 1;
		}
	}

//0 é água	 e 1 é navio
	scanf("%d",&k);

	for(i=0;i<k;i++){
		scanf("%d %d",&l,&c);
		l--; c--;

		if(M[l][c] == 1) M[l][c] = 2;

	}

	/*
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			printf("%d ",M[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	*/

	int nd = 0;

	for(i=0;i<n;i++){
		for(j=0;j<m;j++){

			if(M[i][j] == 2){
				if(busca(i,j) == 0)
					nd++;
			}

		}
	}

	/*
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			printf("%d ",M[i][j]);
		}
		printf("\n");
	}
	*/

	printf("%d\n",nd);

    return 0;
}
