#include <cstdio>
#include <iostream>
#include <queue>

using namespace std;

int main()
{
	long long int a,b,c,n,i,next,sum,tmp,med;
	int t;
	priority_queue<int> esq, dir;
	
	scanf("%d",&t);
	
	while (t--)
	{
		esq = priority_queue <int>();
		dir = priority_queue <int>();
		
		sum = 1;
		esq.push(1);
		
		scanf("%lld%lld%lld%lld",&a,&b,&c,&n);
		
		/* 1 3 5 [7] ---- 9 11 13 15 */
		for (i=2; i<=n; i++)
		{
			med = esq.top();
			
			next = (a * (long long)med + b*i + c) % 1000000007;
			
			if (i%2) // acrescenta na esquerda
			{
				if (next < -dir.top())
					esq.push(next);
				else
				{
					tmp = -dir.top();
					dir.pop();
					esq.push(tmp);
					dir.push(-next);
				}
			}
			else // acrescenta na direita
			{
				if (next > med)
					dir.push(-next);
				else
				{
					esq.pop();
					esq.push(next);
					dir.push(-med);
				}
			}
			sum+= next;
		}
		
		printf("%lld\n", sum);
	}
	return 0;
}