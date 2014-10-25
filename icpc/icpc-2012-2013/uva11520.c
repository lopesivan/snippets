#include <stdio.h>
#include <string.h>
#define MAX (10)

int n;
char tab[MAX][MAX+1];

int can(char c, int i, int j)
{
	int flag = 1;

	if (i > 0)
		if (tab[i-1][j] == c)
			flag = 0;
	if (i < n-1)
		if (tab[i+1][j] == c)
			flag = 0;

	if (j > 0)
		if (tab[i][j-1] == c)
			flag = 0;

	if (j < n-1)
		if (tab[i][j+1] == c)
			flag = 0;

	return flag;
}

void fill()
{
	char try;
	int i, j;

	for (i = 0; i < n; ++i) /*row major*/
		for (j = 0; j < n; ++j) {
			if (tab[i][j] != '.')
				continue;
			try = 'A';
			while ( !can(try, i, j) )
				++try;
			tab[i][j] = try;
		}
}

int main() {
	int TC, i, _TC;

	scanf("%d", &TC);

	for (_TC = 1; _TC <= TC; ++_TC) {
		scanf("%d", &n);

		for (i = 0; i < n; ++i)
			scanf("%s", tab[i]);

		fill();

		printf("Case %d:\n", _TC);

		for (i = 0; i < n; ++i)
			/*printf("%s\n", tab[i]);*/
			puts(tab[i]);
	}
	return 0;
}
