#include <cstdio>
#include <cstdlib>
#include <cstring>
#define max(a, b) ((a) > (b) ? (a) : (b))

using namespace std;

inline int n ( char c)
{
	switch(c)
	{
		case 'S':
			return 0;
		case 'H':
			return 1;
		case 'D':
			return 2;
		case 'C':
			return 3;
	}
}

inline char l (int i)
{
	switch(i)
	{
		case 0:
			return 'S';
		case 1:
			return 'H';
		case 2:
			return 'D';
		case 3:
			return 'C';
	}
}

int main() {
	char v[39+6]; /*cartas em 3*i+0 num e 3*i+1 naipe*/
	
	while ( gets(v) != NULL ) {
		
		/* parte 1: declarar e zerar*/
		int count[4], sum = 0;
		bool a[4], k[4], q[4], j[4], stop[4];
		
		memset(count, 0, sizeof count);
		memset(a, 0, sizeof a);
		memset(k, 0, sizeof k);
		memset(q, 0, sizeof q);
		memset(j, 0, sizeof j);
		memset(stop, 0, sizeof stop);
		
		/* parte 2: preencher */
		for (int i = 0; i < 3*13; i += 3) {
			++count [n (v[i+1])];
			
			switch (v[i])
			{
				case 'A':
					a [n (v[i+1])] = true;
					sum += 4;
					break;
				case 'K':
					k [n (v[i+1])] = true;
					sum +=3;
					break;
				case 'Q':
					q [n (v[i+1])] = true;
					sum += 2;
					break;
				case 'J':
					j [n (v[i+1])] = true;
					++sum;
					break;
			}
		}
		
		for (int i = 0; i < 4; ++i) {
			
			if (a[i])
				stop[i] = 1;
			if (k[i] && ((count[i] - 1) > 0))
				stop[i] = 1;
			if (q[i] && ((count[i] - 2) > 0))
				stop[i] = 1;
		}
		
		/* parte 3: regras*/
		
		for (int i = 0; i < 4; ++i) {
			
			if (k[i] && count[i] == 1)
				--sum;
			if (q[i] && count[i] <= 2)
				--sum;
			if (j[i] && count[i] <= 3)
				--sum;	
		}
		
		if (sum >= 16 && stop[0] && stop[1] && stop[2] && stop[3])
			puts("BID NO-TRUMP");
		else {
			
			/* regras adicionais (5, 6, 7) */
			for (int i = 0; i < 4; ++i) {
				if (count[i] == 2)
					++sum;
				else if (count[i] == 1 || count[i] == 0)
					sum += 2;
			}
			
			if (sum >= 14) {
				int maior = -1, pos = -1;
				
				for (int i = 0; i < 4; ++i) {
					if (count[i] > maior) {
						maior = count[i];
						pos = i;
					}
				}
				printf("BID %c\n", l(pos));
			}
			else
				puts("PASS");
		}
	}
	return 0;
}