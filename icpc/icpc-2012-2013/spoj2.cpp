#include <cstdio>
#include <iostream>
#include <set>

using namespace std;

set <int> crivo_inicial;
int n,m;

void reset_crivo()
{
	int i;
	
	for (i=3; i<=n; i+=2)
		crivo_inicial.insert(i);
}

int main()
{
	int t,p;
	set <int> primes,crivo;
	
	cin >> t;
	
	reset_crivo();
	
	while (t--)
	{
		cin >> m >> n;
		crivo = crivo_inicial;
		
		
		
		
	}
	
	
	
	return 0;
}
