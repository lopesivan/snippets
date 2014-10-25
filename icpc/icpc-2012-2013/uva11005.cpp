#include <cstdio>
#define max(a,b) ((a)>=(b) ? (a) : (b))
#define min(a,b) ((a)<=(b) ? (a) : (b))

using namespace std;

int valores[36];
int resp[37];
int minanswer;
int answer;

int calc(int next, int b)
{
	answer = 0;
	
	while (next != 0)
	{
		answer += valores[ next % b ];
		next /= b;
	}
	
	return answer;
}

int main()
{
	int t, am, i, j, q, next;
	
	scanf("%d", &t);
	
	for (am = 1; am <= t; ++am)
	{
		printf("Case %d:\n", am);
		
		for (i = 0; i < 36; ++i)
			scanf("%d", &valores[i]);
		
		scanf("%d", &q);
		
		for (i = 0; i < q; ++i)
		{
			scanf("%d", &next);
			printf("Cheapest base(s) for number %d:", next);
			
			minanswer = 1000000;
			
			/*potenciais bases*/
			for (j = 2; j <= 36; ++j)
			{
				resp[j] = calc(next, j);
				minanswer = min(resp[j], minanswer);
			}
			
			for (j = 2; j <= 36; ++j)
				if (resp[j] == minanswer)
					printf(" %d", j);
				
			puts("");
		}
		
		if (am != t)
			puts("");
	}
	
	return 0;
}