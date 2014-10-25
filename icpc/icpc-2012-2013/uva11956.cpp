#include <cstdio>
#include <cstring>
#include <vector>

#define MAX (100001+100)

using namespace std;

int main()
{
	vector<unsigned char> display;
	int t, j, tam, i, k;
	char input[MAX];
	
	scanf("%d%*c", &t);
	
	for (k = 1; k <= t; ++k)
	{
		display.assign(100, 0);
		j = 0;
		gets(input);
		tam = strlen(input);
		
		for (i = 0; i < tam; i++)
		{
			switch (input[i])
			{
				case '>':
					j = (j+1)%100;
					break;
				case '<':
					j = (j+99)%100;
					break;
				case '+':
					display[j] = ++display[j]; /*(display[j]+1)%256;*/
					break;
				case '-':
					display[j] = --display[j]; /*(display[j]+255)%256;*/
			}
		}
		
		printf("Case %d:", k);
		
		for (i = 0; i < 100; ++i)
			printf(" %.2X", display[i]); /*printf(" %02X", display[i]);*/
		puts("");
	}
	
	return 0;
}