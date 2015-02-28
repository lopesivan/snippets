/*
	Conta o numero de soluções para o problema das n - rainhas.
*/

# include <stdio.h>
# include <string.h>

# define MAXN 16

int board[MAXN][MAXN];

void ataca(int r, int c, int n, int t){
	int i, j, k, l;
	for(i = -1; i <= 1; i++){
		for(j = -1; j <= 1; j++){
			if( i == 0 && j == 0 ) continue;
			for(k = r, l = c; k >= 0 && l >= 0 && k < n && l < n; k+=i, l+=j){
				board[k][l] += t;
			}
		}
	}
}

int solve(int p, int n){
	int ans = 0;
	int i;
	if( p == n ) return 1;
	for(i = 0; i < n; i++){
		if( board[p][i] == 0 ){
			ataca(p,i,n,1);
			ans += solve(p+1,n);
			ataca(p,i,n,-1);
		}
	}
	return ans;
}

int main (void){
	int n;
	scanf("%d", &n);
	memset(board, 0, sizeof board);
	printf("%d\n", solve(0,n));
	return 0;
}
