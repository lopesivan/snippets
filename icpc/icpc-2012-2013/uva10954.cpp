#include <cstdio>
#include <queue>

using namespace std;

int main()
{
	int n, tmp, tmp2, bin, i;
	long long int sum;
	priority_queue<int> input;
	
	while (scanf("%d",&n)) /*,0 ou 1*/
	{
		if (!n)
			break;
		
		sum = 0;
		input = priority_queue<int> ();
		
		for (i=0; i<n; i++)
		{
			scanf("%d",&tmp);
			input.push(-tmp);
		}
		
		for (i=0; i<n-1; i++)
		{
			tmp = input.top();
			input.pop();
			tmp2 = input.top();
			input.pop();
			
			bin = tmp + tmp2;
			sum-=bin;
			input.push(bin);
		}
		
		// OBS.: ERRADO!!!
		/*i = n-1;
		tmp = input.top();
		input.pop();
		sum-=tmp * i;
		
		for (i = n-1; i>=1; i--)
		{
			tmp=input.top();
			input.pop();
			sum -= tmp * i;
		}*/
		
		printf("%lld\n",sum);
	}
	
	return 0;
}