#include <stdio.h>

int b, p, m;

int pot (int b, int p)
{
	if (p == 0)
		return 1;
	/* b^p mod m */
	int tmp;
	b %= m;
	tmp = pot (b, p/2) % m;
	tmp = (tmp * tmp) % m;

	if ( p%2 == 1)
		tmp = (tmp * b) % m;

	return tmp % m;
}

int main() {
	while (scanf("%d%d%d", &b, &p, &m) == 3)
		printf("%d\n", pot(b, p) );
	return 0;
}
