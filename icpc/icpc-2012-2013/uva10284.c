#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define legal(x) (((x)>=0) && ((x)<8) ? 1 : 0)

char tab[8][8];
int knight[8][2] = { {2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {1, 2}, {1, -2}, {-1, 2}, {-1, -2} };

/*int legal(int x)
{
	if (x >= 0 && x < 8)
		return 1;
	else
		return 0;
}*/

/*void print()
{
	int j, k;
	
	for (j = 0; j < 8; j++)
	{
		for (k = 0; k < 8; k++)
			printf("%c ",tab[j][k]);
		puts("");
	}
}*/

int main()
{
	char input[100], c;
	int i, j, k, a, b, _a, _b, tam, answer;
	
	while ( gets(input) != NULL )
	{
		for (j = 0; j < 8; j++)
			for (k = 0; k < 8; k++)
				tab[j][k]='z'; /*zera*/
				
		answer = j = k = 0;
		
		tam = strlen(input);
		
		for (i = 0; i < tam; i++)
		{
			c = input[i];
			
			if (c == '/')
				j++, k = 0;
			else if ( isalpha(c) )
				tab[j][k++] = c;
			else
				k += c - '0';
		}
		
		for (j = 0; j < 8; j++)
			for (k = 0; k < 8; k++)
			{
				switch ( tab[j][k] )
				{
					case 'x':
					case 'z':
						break;
					case 'p':
						if ( legal(j+1) )
						{
							if ( legal(k+1) )
								if ( tab[j+1][k+1] == 'z')
									tab[j+1][k+1] = 'x';
							if ( legal(k-1) )
								if ( tab[j+1][k-1] == 'z')
									tab[j+1][k-1] = 'x';
						}
						break;
					case 'P':
						if ( legal(j-1) )
						{
							if ( legal(k+1) )
								if ( tab[j-1][k+1] == 'z')
									tab[j-1][k+1] = 'x';
							if ( legal(k-1) )
								if ( tab[j-1][k-1] == 'z')
									tab[j-1][k-1] = 'x';
						}
						break;
						
					case 'q':
					case 'Q':
						for (a = -1; a <= 1; a++)
							for (b = -1; b <= 1; b++)
							{
								_a = j;
								_b = k;
								
								if (!a && !b)
									continue;
								
								while ( legal(_a + a) && legal (_b + b) )
								{
									_a += a;
									_b += b;
									
									if (tab[_a][_b] == 'z' || tab[_a][_b] == 'x')
										tab[_a][_b] = 'x';
									else
										break;
								}
							}
							
						break;
					
					case 'b':
					case 'B':
						for (a = -1; a <= 1; a += 2)
							for (b = -1; b <= 1; b += 2)
							{
								_a = j;
								_b = k;
								
								while ( legal(_a + a) && legal (_b + b) )
								{
									_a += a;
									_b += b;
									
									if (tab[_a][_b] == 'z' || tab[_a][_b] == 'x')
										tab[_a][_b] = 'x';
									else
										break;
								}
							}
							
						break;
						
					case 'r':
					case 'R':
						for (a = -1; a <= 1; a++)
							for (b = -1; b <= 1; b++)
							{
								_a = j;
								_b = k;
								
								if ( (!a && !b) || (a==1 && b==1) || (a==1 && b==-1) || (a==-1 && b==1) || (a==-1 && b==-1)    )
									continue;
								
								while ( legal(_a + a) && legal (_b + b) )
								{
									_a += a;
									_b += b;
									
									if (tab[_a][_b] == 'z' || tab[_a][_b] == 'x')
										tab[_a][_b] = 'x';
									else
										break;
								}
							}
							
						break;
					
					case 'K':
					case 'k':
						for (a = -1; a <= 1; a++)
							for (b = -1; b <= 1; b++)
							{
								_a = j;
								_b = k;
								
								if ( legal(_a + a) && legal (_b + b) )
									if (tab[_a + a][_b + b] == 'z')
										tab[_a + a][_b + b] = 'x';
							}
							
						break;
					
					case 'N':
					case 'n':
						for (a = 0; a < 8; a++)
						{
							if ( legal(j + knight[a][0]) && legal(k + knight[a][1]) )
								if ( tab[ j + knight[a][0] ][ k + knight[a][1] ] == 'z' )
									tab[ j + knight[a][0] ][ k + knight[a][1] ] = 'x';
						}
						break;
				}
			}
		
		for (j = 0; j < 8; j++)
			for (k = 0; k < 8; k++)
				if ( tab[j][k] == 'z')
					answer++;
		
		printf("%d\n", answer);
	}
	
	return 0;
}