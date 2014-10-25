/*calcule C {b, (a+b-1)*/

#include <stdio.h>
#define QUOC 1300031

int a,b;

int solve()
{
	int answer,i;
	int p,n;
	int _n,_p;
	
	n = a+b-1;
	p = b<=n/2? b: (n-b);
	
	/*calculo de c n,p mod QUOC*/
	
	for (i=n; i>=2; i--)
	{
		
	}
	
	return answer;
}


int main()
{
	int num;
		
	scanf("%d",&num);
	
	while(num--)
	{
		scanf("%d%d",&a,&b);
		
		printf("%d\n",solve());
		
	}
	
	return 0;
}