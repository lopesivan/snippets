#include <cstdio>
#include <cstring>
#include <vector>

#define MAX (10001+100)

using namespace std;

int main()
{
	int t, k, tmp, i;
	double cents;
	vector<int> ascii;
	char c, input[MAX];
	
	scanf("%d", &t);
	
	while (t--)
	{
		ascii.assign(256, 0);
		cents = 0.0;
		
		scanf("%d%*c", &k);
		
		while (k--)
		{
			scanf("%c%d", &c, &tmp);
			getchar();
			ascii[ (int) c] = tmp;
		}
		
// 		for (i = 0; i < 256; i++)
// 			printf("%c ==> %d\n", i, ascii[i]);
		
		scanf("%d%*c", &k);
		
		while (k--)
		{
			gets(input);
			
			for (i = 0; input[i]; ++i)
				cents += ascii[input[i]];
		}
		
		printf("%.2lf$\n", cents/100.0 );
	}
	
	return 0;
}