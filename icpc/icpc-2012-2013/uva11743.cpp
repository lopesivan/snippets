#include <cstdio>
#include <cstring>

using namespace std;
 
 int main()
 {
	char c;
	int t, i, j, k, sum1, sum2, v1[16], v2[8];
	
	scanf("%d%*c", &t);
	
	for(i = 0; i < t; ++i)
	{
		j = 0;
		
		while( j < 16)
		{
			scanf("%c", &c);
			if(c != ' ')
			{
				v1[j] = (int) (c - '0') ;
				++j;
			}
		}
		getchar();
		
		for( j = 14, k = 7; j >= 0; j -= 2)
		{
			v2[k] = v1[j]*2;
			--k;
		}
		
		for( j = 0, sum1 = 0; j < 8; ++j)
			sum1 += v2[j]%10 + (v2[j]/10)%100;
		
		for (j = 1, sum2 = 0; j <= 15; j += 2)
			sum2 += v1[j];
		
		sum1 += sum2;
		
		((sum1%10) != 0) ? puts("Invalid") : puts("Valid");
	}
	 
	return 0;
 }