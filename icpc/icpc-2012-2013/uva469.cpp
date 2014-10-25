#include <cstdio>
#include <cstdlib>
#include <cstring>
#define MAX (100+5)
using namespace std;

char t[MAX][MAX], after;
int num[MAX*MAX][2];
int row, qtnum, answer, tam;

int d[8][2] = { {1, 1}, {-1, 1}, {1, -1}, {-1, -1}, {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

inline void fill (int x, int y)
{
	if ( x >= row || y >= tam || x < 0 || y < 0 || t[x][y] == 'L' )
		return;
	
	if (t[x][y] == after )
		return;
	
	++answer;
	t[x][y] = after;
	
	for (int i = 0; i < 8; ++i) {
		if (t[x+d[i][0]][y+d[i][1]] != after)
			fill(x + d[i][0], y + d[i][1]);
	}
		
}

int main()
{
	int TC;
	scanf("%d%*c%*c", &TC);
	
	while (TC--)
	{
		row = 0;
		while (gets(t[row++]), t[row-1][0] == 'L' || t[row-1][0] == 'W');
		--row;
		tam = strlen(t[0]);
		
		/*for (int i = 0; i < row; ++i)
			puts(t[i]);
		puts("");*/
		
		qtnum = 0;
		sscanf(t[row], "%d%d", &num[qtnum][0], &num[qtnum][1]);
		++qtnum;
		while ( gets(t[row]) != NULL && strlen(t[row]) ) {
			sscanf(t[row], "%d%d", &num[qtnum][0], &num[qtnum][1]);
			++qtnum;
		}
		for (int i = 0; i < qtnum; ++i) {
			answer = 0;
			/*printf(": %c\n", t[num[i][0]-1][num[i][1]-1]);*/
			after = 'Y';
			fill(num[i][0]-1,num[i][1]-1);
			/*printf("%d %d %d\n", num[i][0]-1, num[i][1]-1, answer);*/
			printf("%d\n", answer);
			after = 'W';
			fill(num[i][0]-1,num[i][1]-1);
		}
		
		if (TC)
			puts("");
	}
	return 0;
}