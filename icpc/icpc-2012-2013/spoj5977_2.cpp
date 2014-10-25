#include <cstdio>
#include <iostream>
#include <set>

using namespace std;

int main()
{
	std::multiset<int> esq, dir;
	std::multiset<int> ::iterator it;
	long long int a,b,c,n,i,next,sum,tmp;
	int t;
	
	scanf("%d",&t);
	
	while (t--)
	{
		/* não usar clear */
		esq = multiset<int> ();
		dir = multiset<int> ();
		sum = 1;
		esq.insert(1);
		
		scanf("%lld%lld%lld%lld",&a,&b,&c,&n);
		
		/* 1 3 5 [7] ---- 9 11 13 15 */
		for (i=2; i<=n; i++)
		{
			next = (a * ((long long)(*(esq.rbegin()))) + (b*i + c)) % (1000000007);
			
			if (i%2) // acrescenta na esquerda
			{
				it = dir.begin();
				tmp = *it;
				
				if (next < tmp)
					esq.insert(next);
				else
				{
					dir.erase(it);
					esq.insert(tmp);
					dir.insert(next);
				}
			}
			else // acrescenta na direita
			{
				//it = esq.rbegin();
				it=esq.end();
				it--;
				tmp=*it;
				
				if (next > tmp)
					dir.insert(next);
				else
				{
					esq.erase(it);
					dir.insert(tmp);
					esq.insert(next);
				}
			}
			sum += next;
			
			/*for (it=esq.begin(); it!= esq.end(); it++)
				printf("%d ",*it);
			printf("-- ");
			for (it=dir.begin(); it!= dir.end(); it++)
				printf("%d ",*it);
			puts("");*/
		}
		printf("%lld\n", sum);
	}
	return 0;
}