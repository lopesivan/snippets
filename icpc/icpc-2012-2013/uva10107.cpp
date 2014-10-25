#include <cstdio>
#include <queue>

using namespace std;

int main()
{
	int next, i = 0, tmp;
	priority_queue <int> left, right;
	
	while ( scanf("%d", &next) == 1 )
	{
		if (i == 0)
			left.push(next);
		
		else
		{
			if ( i%2 == 0)
			{
				tmp = -right.top();
				if (next < tmp)
					left.push(next);
				else
				{
					right.pop();
					right.push(-next);
					left.push(tmp);
				}
			}
			else
			{
				tmp = left.top();
				if (next > tmp)
					right.push(-next);
				else
				{
					left.pop();
					left.push(next);
					right.push(-tmp);
				}
				/*1 3 5 -- 8 10 12*/
			}
		}
		
		i++;
		
		//printf("%d\n", left.top());
		if (i%2 == 1)
			printf("%d\n", left.top() );
		else
			printf("%d\n", (left.top() - right.top())/2 );
			
		// i%2 == 0 ? printf("%d\n", left.top() ) : printf("%d\n", (left.top() - right.top())/2 );
	}
	
	return 0;
}