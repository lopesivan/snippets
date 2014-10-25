#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

int main()
{
	int n, tmp, tmp2, i;
	long long int sum;
	priority_queue<int> fila;
	
	while (scanf("%d", &n) == 1)
	{
		fila = priority_queue<int> ();
		sum = 0;
		
		if (!n)
			break;
		
		for (i = 0; i < n; ++i)
		{
			scanf("%d", &tmp);
			fila.push(-tmp);
		}
		
		while (fila.size() >= 2)
		{
			tmp = fila.top();
			fila.pop();
			tmp2 = fila.top();
			fila.pop();
			sum -= tmp + tmp2;
			fila.push(tmp + tmp2);
		}
		
		printf("%lld\n", sum );
	}
	
	return 0;
}