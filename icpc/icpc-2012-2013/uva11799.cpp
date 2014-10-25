#include <cstdio>
#include <queue>

using namespace std;

int main()
{
	int t,n,tmp,i;
	priority_queue<int> fila;
	
	scanf("%d",&t);
	
	for (i=1; i<=t; i++)
	{
		fila = priority_queue<int> ();
		scanf("%d",&n);
		
		while (n--)
		{
			scanf("%d",&tmp);
			fila.push(tmp);
		}
		
		printf("Case %d: %d\n", i, fila.top());
	}
	
	return 0;
}