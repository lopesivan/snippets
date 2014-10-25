#include <stdio.h>
#include <string.h>

int am;
#define MAX (1000)
#define rep(k) for (am = 0; am < k; am++)

int main()
{
	int s, tam, i, j, a, b;
	char input[100];
	char output[MAX][MAX];
	
	while ( scanf("%d", &s) == 1)
	{
		if (!s)
			break;
		
		scanf("%*c%s%*c", input);
		tam = strlen(input);
		
		/*sscanf(input, "%d", &a);*/
		
		for (i = 0; i < MAX; i++)
			for (j = 0; j < MAX; j++)
				output[i][j] = ' ';
		
		a = b = 0;
		
		for (j = 0; j < 5; j+=2, b = 0, a += 1+s)
		{
			for (i = 0; i < tam; i++)
			{
				if ( j == 0 )
				{
					output[a][b++] = ' ';
					switch ( input[i] )
					{
						case '1':
							rep(s) { output[a][b++] = ' '; }
							break;
						case '2':
							rep (s) { output[a][b++]='-'; }
							break;
						case '3':
							rep (s) { output[a][b++]='-'; }
							break;
						case '4':
							rep(s) { output[a][b++] = ' '; }
							break;
						case '5':
							rep (s) { output[a][b++]='-'; }
							break;
						case '6':
							rep (s) { output[a][b++]='-'; }
							break;
						case '7':
							rep (s) { output[a][b++]='-'; }
							break;
						case '8':
							rep (s) { output[a][b++]='-'; }
							break;
						case '9':
							rep (s) { output[a][b++]='-'; }
							break;
						case '0':
							rep (s) { output[a][b++]='-'; }
							break;
					}
					output[a][b++] = ' ';
					output[a][b++] = ' ';
				}
				
				else if ( j == 2 )
				{
					output[a][b++] = ' ';
					switch ( input[i] )
					{
						case '1':
							rep(s) { output[a][b++] = ' '; }
							break;
						case '2':
							rep (s) { output[a][b++]='-'; }
							break;
						case '3':
							rep (s) { output[a][b++]='-'; }
							break;
						case '4':
							rep(s) { output[a][b++] = '-'; }
							break;
						case '5':
							rep (s) { output[a][b++]='-'; }
							break;
						case '6':
							rep (s) { output[a][b++]='-'; }
							break;
						case '7':
							rep (s) { output[a][b++]=' '; }
							break;
						case '8':
							rep (s) { output[a][b++]='-'; }
							break;
						case '9':
							rep (s) { output[a][b++]='-'; }
							break;
						case '0':
							rep (s) { output[a][b++]=' '; }
							break;
					}
					output[a][b++] = ' ';
					output[a][b++] = ' ';
				}
				
				else if ( j == 4 )
				{
					output[a][b++] = ' ';
					switch ( input[i] )
					{
						case '1':
							rep(s) { output[a][b++] = ' '; }
							break;
						case '2':
							rep (s) { output[a][b++]='-'; }
							break;
						case '3':
							rep (s) { output[a][b++]='-'; }
							break;
						case '4':
							rep(s) { output[a][b++] = ' '; }
							break;
						case '5':
							rep (s) { output[a][b++]='-'; }
							break;
						case '6':
							rep (s) { output[a][b++]='-'; }
							break;
						case '7':
							rep (s) { output[a][b++]=' '; }
							break;
						case '8':
							rep (s) { output[a][b++]='-'; }
							break;
						case '9':
							rep (s) { output[a][b++]='-'; }
							break;
						case '0':
							rep (s) { output[a][b++]='-'; }
							break;
					}
					output[a][b++] = ' ';
					output[a][b++] = ' ';
				}
			}
		}
		
		for (j = 0, a = 1, b = 0; j < s; j++, b = 0, a++)
			for (i = 0; i < tam; i++)
			{
				switch ( input[i] )
				{
					case '1':
						output[a][b++] = ' ';
						b += s;
						output[a][b++] = '|';
						break;
					case '2':
						output[a][b++]=' ';
						b += s;
						output[a][b++]='|';
						break;
					case '3':
						output[a][b++]=' ';
						b += s;
						output[a][b++]='|';
						break;
					case '4':
						output[a][b++]='|';
						b += s;
						output[a][b++]='|';
						break;
					case '5':
						output[a][b++]='|';
						b += s;
						output[a][b++]=' ';
						break;
					case '6':
						output[a][b++]='|';
						b += s;
						output[a][b++]=' ';
						break;
					case '7':
						output[a][b++]=' ';
						b += s;
						output[a][b++]='|';
						break;
					case '8':
						output[a][b++]='|';
						b += s;
						output[a][b++]='|';
						break;
					case '9':
						output[a][b++]='|';
						b += s;
						output[a][b++]='|';
						break;
					case '0':
						output[a][b++]='|';
						b += s;
						output[a][b++]='|';
						break;
				}
				b++;
			}
		
		for (j = 0, a = 2 + s, b = 0; j < s; j++, b = 0, a++)
			for (i = 0; i < tam; i++)
			{
				switch ( input[i] )
				{
					case '1':
						output[a][b++] = ' ';
						b += s;
						output[a][b++] = '|';
						break;
					case '2':
						output[a][b++]='|';
						b += s;
						output[a][b++]=' ';
						break;
					case '3':
						output[a][b++]=' ';
						b += s;
						output[a][b++]='|';
						break;
					case '4':
						output[a][b++]=' ';
						b += s;
						output[a][b++]='|';
						break;
					case '5':
						output[a][b++]=' ';
						b += s;
						output[a][b++]='|';
						break;
					case '6':
						output[a][b++]='|';
						b += s;
						output[a][b++]='|';
						break;
					case '7':
						output[a][b++]=' ';
						b += s;
						output[a][b++]='|';
						break;
					case '8':
						output[a][b++]='|';
						b += s;
						output[a][b++]='|';
						break;
					case '9':
						output[a][b++]=' ';
						b += s;
						output[a][b++]='|';
						break;
					case '0':
						output[a][b++]='|';
						b += s;
						output[a][b++]='|';
						break;
				}
				b++;
			}
		/*imprime resultado*/
		a = 2*s + 3;
		b = ((s+3)*tam)-1;
		
		for (i = 0; i < a; i++) /*altura*/
		{
			for (j = 0; j < b ; j++) /*largura*/
				putchar( output[i][j] );
			puts("");
		}
		puts("");
	}
	return 0;
}