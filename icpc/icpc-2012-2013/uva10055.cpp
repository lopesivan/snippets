#include <cstdio>

using namespace std;

int main()
{
	long long int a, b;
	
	while (scanf("%lld%lld",&a,&b)==2)
		b > a? printf("%lld\n",b-a) : printf("%lld\n",a-b);
	
	return 0;
}